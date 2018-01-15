/*
   +----------------------------------------------------------------------+
   | HipHop for PHP                                                       |
   +----------------------------------------------------------------------+
   | Copyright (c) 2017-present Facebook, Inc. (http://www.facebook.com)  |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.01 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.php.net/license/3_01.txt                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
*/

#ifndef incl_HPHP_VSDEBUG_BREAKPOINT_MGR_H_
#define incl_HPHP_VSDEBUG_BREAKPOINT_MGR_H_

#include "hphp/runtime/ext/vsdebug/break_mode.h"
#include "hphp/runtime/ext/vsdebug/command.h"
#include "hphp/runtime/ext/vsdebug/debugger.h"

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace HPHP {
namespace VSDEBUG {

struct ClientPreferences;
struct RequestInfo;

enum BreakpointType {
  Source,
  Function
};

// Represents the resolved location of an installed breakpoint. This may
// differ from the request location due to source mapping and line calibration.
struct ResolvedLocation {
  int m_startLine;
  int m_endLine;
  int m_startCol;
  int m_endCol;
  std::string m_path;
};

struct Breakpoint {
  Breakpoint(
    int id,
    int line,
    int column,
    const std::string path,
    const std::string condition,
    const std::string hitCondition
  );

  void updateConditions(std::string condition, std::string hitCondition);

  const int m_id;
  const BreakpointType m_type;
  const int m_line;
  const int m_column;
  const std::string m_path;

  ResolvedLocation m_resolvedLocation;
  int m_hitCount;

  std::string getCondition() const { return m_condition; }
  std::string getHitCondition() { return m_hitCondition; }

  void cacheConditionUnit(request_id_t requestId, HPHP::Unit* unit) {
    m_unitCache.emplace(requestId, unit);
  }

  HPHP::Unit* getCachedConditionUnit(request_id_t requestId) {
    auto it = m_unitCache.find(requestId);
    return it == m_unitCache.end() ? nullptr : it->second;
  }

  void clearCachedConditionUnit(request_id_t requestId) {
    auto it = m_unitCache.find(requestId);
    if (it != m_unitCache.end()) {
      m_unitCache.erase(it);
    }
  }

private:

  // Evaluation condition for a conditional breakpoint.
  std::string m_condition;

  // Hit condition, specified separately in the protocol. This is used for
  // comparison to the number of times the breakpoint has been hit.
  std::string m_hitCondition;

  // Cache of compilation units for breakpoint conditions, per request
  // thread.
  std::unordered_map<request_id_t, HPHP::Unit*> m_unitCache;
};

struct ExceptionBreakpointSettings {
  ExceptionBreakMode m_breakMode {ExceptionBreakMode::BreakNone};
  const std::vector<std::string> m_filters;
};

struct BreakpointManager {
  BreakpointManager(Debugger* debugger);
  ~BreakpointManager();

  void setExceptionBreakMode(ExceptionBreakMode mode);
  ExceptionBreakMode getExceptionBreakMode() const;

  void onBreakpointResolved(
    int id,
    int startLine,
    int endLine,
    int startColumn,
    int endColumn,
    const std::string& path
  );

  void onBreakpointHit(int id);

  bool isBreakpointResolved(int id) const;

  int addBreakpoint(
    int line,
    int column,
    const std::string& path,
    const std::string& condition,
    const std::string& hitCondition
  );

  void removeBreakpoint(int id);

  Breakpoint* getBreakpointById(int id);

  const std::unordered_set<int> getAllBreakpointIds() const;

  const std::unordered_set<int> getBreakpointIdsByFile(
    const std::string& sourcePath
  ) const;

  bool isBreakConditionSatisified(
    RequestInfo* ri,
    Breakpoint* bp
  );

  void onRequestShutdown(request_id_t requestId);

private:

  static constexpr char* ReasonNew = "new";
  static constexpr char* ReasonChanged = "changed";
  static constexpr char* ReasonRemoved = "removed";

  void sendBreakpointEvent(int breakpointId, const char* reason);

  void sendBpError(
    int bpId,
    const char* error,
    const std::string& condition
  );

  // Helper to honor client's lines start at 0 or 1 preference.
  static int adjustLineNumber(
    const ClientPreferences& preferences,
    int line,
    bool column
  );

  ExceptionBreakpointSettings m_exceptionSettings;

  // The authoratative list of the current breakpoints set by the client.
  std::unordered_map<int, Breakpoint> m_breakpoints;

  // Map of source file name to list of breakpoints in that file.
  std::unordered_map<std::string, std::unordered_set<int>> m_sourceBreakpoints;

  // Verified breakpoints. A breakpoint is verified if at least one request
  // has resolved it in a compilation unit since it was set. This is a bit odd
  // compared to most debuggers, because each request loads its own Hack/PHP
  // code and needs to resolve the bp itself. Clients consuming the protocol
  // expect a single resolved notification to mean the bp is valid for the whole
  // program...
  std::unordered_set<int> m_resolvedBreakpoints;

  Debugger* m_debugger;
};

}
}

#endif //incl_HPHP_VSDEBUG_BREAKPOINT_MGR_H_
