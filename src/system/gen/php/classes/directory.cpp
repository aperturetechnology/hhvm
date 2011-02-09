/*
   +----------------------------------------------------------------------+
   | HipHop for PHP                                                       |
   +----------------------------------------------------------------------+
   | Copyright (c) 2010 Facebook, Inc. (http://www.facebook.com)          |
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
// @generated by HipHop Compiler

#include <php/classes/directory.h>
#include <php/classes/directory.fws.h>

// Dependencies
#include <runtime/ext/ext.h>
#include <runtime/eval/eval.h>
namespace hphp_impl_starter {}

namespace HPHP {
///////////////////////////////////////////////////////////////////////////////

/* preface starts */
extern CallInfo ci_;
/* preface finishes */
/* SRC: classes/directory.php line 3 */
#ifndef OMIT_JUMP_TABLE_CLASS_STATIC_GETINIT_Directory
Variant c_Directory::os_getInit(CStrRef s) {
  DECLARE_SYSTEM_GLOBALS(g);
  int64 hash = s->hash();
  switch (hash & 3) {
    case 0:
      HASH_RETURN_NAMSTR(0x1429F792A6880074LL, NAMSTR(s_sys_ssf362b3c4, "path"),
                         null, 4);
      break;
    case 2:
      HASH_RETURN_NAMSTR(0x5C4CA333F4541532LL, NAMSTR(s_sys_ss46eeef5c, "handle"),
                         null, 6);
      break;
    default:
      break;
  }
  return c_ObjectData::os_getInit(s);
}
#endif // OMIT_JUMP_TABLE_CLASS_STATIC_GETINIT_Directory
#ifndef OMIT_JUMP_TABLE_CLASS_STATIC_GET_Directory
Variant c_Directory::os_get(CStrRef s) {
  return c_ObjectData::os_get(s);
}
#endif // OMIT_JUMP_TABLE_CLASS_STATIC_GET_Directory
#ifndef OMIT_JUMP_TABLE_CLASS_STATIC_LVAL_Directory
Variant &c_Directory::os_lval(CStrRef s) {
  return c_ObjectData::os_lval(s);
}
#endif // OMIT_JUMP_TABLE_CLASS_STATIC_LVAL_Directory
#ifndef OMIT_JUMP_TABLE_CLASS_GETARRAY_Directory
void c_Directory::o_getArray(Array &props, bool pubOnly) const {
  if (isInitialized(m_path)) props.set(NAMSTR(s_sys_ssf362b3c4, "path"), m_path.isReferenced() ? ref(m_path) : m_path, true);
  if (isInitialized(m_handle)) props.set(NAMSTR(s_sys_ss46eeef5c, "handle"), m_handle.isReferenced() ? ref(m_handle) : m_handle, true);
  c_ObjectData::o_getArray(props, pubOnly);
}
#endif // OMIT_JUMP_TABLE_CLASS_GETARRAY_Directory
#ifndef OMIT_JUMP_TABLE_CLASS_SETARRAY_Directory
void c_Directory::o_setArray(CArrRef props) {
  c_ObjectData::o_setArray(props);
}
#endif // OMIT_JUMP_TABLE_CLASS_SETARRAY_Directory
#ifndef OMIT_JUMP_TABLE_CLASS_realProp_Directory
Variant * c_Directory::o_realProp(CStrRef prop, int flags, CStrRef context) const {
  return o_realPropPublic(prop, flags);
}
#endif // OMIT_JUMP_TABLE_CLASS_realProp_Directory
#ifndef OMIT_JUMP_TABLE_CLASS_realProp_PUBLIC_Directory
Variant * c_Directory::o_realPropPublic(CStrRef s, int flags) const {
  int64 hash = s->hash();
  switch (hash & 3) {
    case 0:
      HASH_REALPROP_STRING(0x1429F792A6880074LL, "path", 4, path);
      break;
    case 2:
      HASH_REALPROP_STRING(0x5C4CA333F4541532LL, "handle", 6, handle);
      break;
    default:
      break;
  }
  return c_ObjectData::o_realPropPublic(s, flags);
}
#endif // OMIT_JUMP_TABLE_CLASS_realProp_PUBLIC_Directory
#ifndef OMIT_JUMP_TABLE_CLASS_realProp_PRIVATE_Directory
Variant * c_Directory::o_realPropPrivate(CStrRef s, int flags) const {
  return o_realPropPublic(s, flags);
}
#endif // OMIT_JUMP_TABLE_CLASS_realProp_PRIVATE_Directory
#ifndef OMIT_JUMP_TABLE_CLASS_CONSTANT_Directory
Variant c_Directory::os_constant(const char *s) {
  return c_ObjectData::os_constant(s);
}
#endif // OMIT_JUMP_TABLE_CLASS_CONSTANT_Directory
IMPLEMENT_CLASS(Directory)
bool c_Directory::o_instanceof(CStrRef s) const {
  int64 hash = s->hash();
  switch (hash & 1) {
    case 1:
      HASH_INSTANCEOF(0x34C95AF311506C8FLL, NAMSTR(s_sys_ss55fe8ad6, "Directory"));
      break;
    default:
      break;
  }
  return false;
}
ObjectData *c_Directory::cloneImpl() {
  c_Directory *obj = NEW(c_Directory)();
  cloneSet(obj);
  return obj;
}
void c_Directory::cloneSet(c_Directory *clone) {
  clone->m_path = m_path.isReferenced() ? ref(m_path) : m_path;
  clone->m_handle = m_handle.isReferenced() ? ref(m_handle) : m_handle;
  ObjectData::cloneSet(clone);
}
Variant c_Directory::o_invoke_from_eval(const char *s, Eval::VariableEnvironment &env, const Eval::FunctionCallExpression *caller, int64 hash, bool fatal) {
  if (hash < 0) hash = hash_string(s);
  switch (hash & 7) {
    case 1:
      HASH_GUARD_LITSTR(0x78AE97BFBEBF5341LL, NAMSTR(s_sys_ssf052ec6b, "close")) {
        const std::vector<Eval::ExpressionPtr> &params = caller->params();
        std::vector<Eval::ExpressionPtr>::const_iterator it = params.begin();
        do {
        } while(false);
        for (; it != params.end(); ++it) {
          (*it)->eval(env);
        }
        int count __attribute__((__unused__)) = params.size();
        if (count > 0) return throw_toomany_arguments("Directory::close", 0, 1);
        return (t_close(), null);
      }
      HASH_GUARD_LITSTR(0x1F479267E49EF301LL, NAMSTR(s_sys_sse896cb09, "read")) {
        const std::vector<Eval::ExpressionPtr> &params = caller->params();
        std::vector<Eval::ExpressionPtr>::const_iterator it = params.begin();
        do {
        } while(false);
        for (; it != params.end(); ++it) {
          (*it)->eval(env);
        }
        int count __attribute__((__unused__)) = params.size();
        if (count > 0) return throw_toomany_arguments("Directory::read", 0, 1);
        return (t_read());
      }
      break;
    case 2:
      HASH_GUARD_LITSTR(0x1670096FDE27AF6ALL, NAMSTR(s_sys_ss941ca25f, "rewind")) {
        const std::vector<Eval::ExpressionPtr> &params = caller->params();
        std::vector<Eval::ExpressionPtr>::const_iterator it = params.begin();
        do {
        } while(false);
        for (; it != params.end(); ++it) {
          (*it)->eval(env);
        }
        int count __attribute__((__unused__)) = params.size();
        if (count > 0) return throw_toomany_arguments("Directory::rewind", 0, 1);
        return (t_rewind(), null);
      }
      break;
    case 7:
      HASH_GUARD_LITSTR(0x0D31D0AC229C615FLL, NAMSTR(s_sys_ssa1b87da7, "__construct")) {
        Variant a0;
        const std::vector<Eval::ExpressionPtr> &params = caller->params();
        std::vector<Eval::ExpressionPtr>::const_iterator it = params.begin();
        do {
          if (it == params.end()) break;
          a0 = (*it)->eval(env);
          it++;
        } while(false);
        for (; it != params.end(); ++it) {
          (*it)->eval(env);
        }
        int count __attribute__((__unused__)) = params.size();
        if (count != 1) return throw_wrong_arguments("Directory::__construct", count, 1, 1, 2);
        return (t___construct(a0), null);
      }
      break;
    default:
      break;
  }
  return c_ObjectData::o_invoke_from_eval(s, env, caller, hash, fatal);
}
Variant c_Directory::os_invoke_from_eval(const char *c, const char *s, Eval::VariableEnvironment &env, const Eval::FunctionCallExpression *caller, int64 hash, bool fatal) {
  return c_ObjectData::os_invoke_from_eval(c, s, env, caller, hash, fatal);
}
CallInfo c_Directory::ci___construct((void*)&c_Directory::i___construct, (void*)&c_Directory::ifa___construct, 1, 4, 0x0000000000000000LL);
CallInfo c_Directory::ci_close((void*)&c_Directory::i_close, (void*)&c_Directory::ifa_close, 0, 4, 0x0000000000000000LL);
CallInfo c_Directory::ci_read((void*)&c_Directory::i_read, (void*)&c_Directory::ifa_read, 0, 4, 0x0000000000000000LL);
CallInfo c_Directory::ci_rewind((void*)&c_Directory::i_rewind, (void*)&c_Directory::ifa_rewind, 0, 4, 0x0000000000000000LL);
Variant c_Directory::i___construct(MethodCallPackage &mcp, CArrRef params) {
  int count __attribute__((__unused__)) = params.size();
  c_Directory *self = NULL;
  p_Directory pobj;
  if (mcp.obj) {
    self = static_cast<c_Directory*>(mcp.obj);
  } else {
    self = createDummy(pobj);
  }
  if (count != 1) return throw_wrong_arguments("Directory::__construct", count, 1, 1, 2);
  {
    ArrayData *ad(params.get());
    ssize_t pos = ad ? ad->iter_begin() : ArrayData::invalid_index;
    CVarRef arg0((ad->getValue(pos)));
    return (self->t___construct(arg0), null);
  }
}
Variant c_Directory::i_close(MethodCallPackage &mcp, CArrRef params) {
  int count __attribute__((__unused__)) = params.size();
  c_Directory *self = NULL;
  p_Directory pobj;
  if (mcp.obj) {
    self = static_cast<c_Directory*>(mcp.obj);
  } else {
    self = createDummy(pobj);
  }
  if (count > 0) return throw_toomany_arguments("Directory::close", 0, 1);
  return (self->t_close(), null);
}
Variant c_Directory::i_read(MethodCallPackage &mcp, CArrRef params) {
  int count __attribute__((__unused__)) = params.size();
  c_Directory *self = NULL;
  p_Directory pobj;
  if (mcp.obj) {
    self = static_cast<c_Directory*>(mcp.obj);
  } else {
    self = createDummy(pobj);
  }
  if (count > 0) return throw_toomany_arguments("Directory::read", 0, 1);
  return (self->t_read());
}
Variant c_Directory::i_rewind(MethodCallPackage &mcp, CArrRef params) {
  int count __attribute__((__unused__)) = params.size();
  c_Directory *self = NULL;
  p_Directory pobj;
  if (mcp.obj) {
    self = static_cast<c_Directory*>(mcp.obj);
  } else {
    self = createDummy(pobj);
  }
  if (count > 0) return throw_toomany_arguments("Directory::rewind", 0, 1);
  return (self->t_rewind(), null);
}
Variant c_Directory::ifa___construct(MethodCallPackage &mcp, int count, INVOKE_FEW_ARGS_IMPL_ARGS) {
  c_Directory *self = NULL;
  p_Directory pobj;
  if (mcp.obj) {
    self = static_cast<c_Directory*>(mcp.obj);
  } else {
    self = createDummy(pobj);
  }
  if (count != 1) return throw_wrong_arguments("Directory::__construct", count, 1, 1, 2);
  CVarRef arg0((a0));
  return (self->t___construct(arg0), null);
}
Variant c_Directory::ifa_close(MethodCallPackage &mcp, int count, INVOKE_FEW_ARGS_IMPL_ARGS) {
  c_Directory *self = NULL;
  p_Directory pobj;
  if (mcp.obj) {
    self = static_cast<c_Directory*>(mcp.obj);
  } else {
    self = createDummy(pobj);
  }
  if (count > 0) return throw_toomany_arguments("Directory::close", 0, 1);
  return (self->t_close(), null);
}
Variant c_Directory::ifa_read(MethodCallPackage &mcp, int count, INVOKE_FEW_ARGS_IMPL_ARGS) {
  c_Directory *self = NULL;
  p_Directory pobj;
  if (mcp.obj) {
    self = static_cast<c_Directory*>(mcp.obj);
  } else {
    self = createDummy(pobj);
  }
  if (count > 0) return throw_toomany_arguments("Directory::read", 0, 1);
  return (self->t_read());
}
Variant c_Directory::ifa_rewind(MethodCallPackage &mcp, int count, INVOKE_FEW_ARGS_IMPL_ARGS) {
  c_Directory *self = NULL;
  p_Directory pobj;
  if (mcp.obj) {
    self = static_cast<c_Directory*>(mcp.obj);
  } else {
    self = createDummy(pobj);
  }
  if (count > 0) return throw_toomany_arguments("Directory::rewind", 0, 1);
  return (self->t_rewind(), null);
}
bool c_Directory::os_get_call_info(MethodCallPackage &mcp, int64 hash) {
  CStrRef s __attribute__((__unused__)) (mcp.name);
  if (hash < 0) hash = s->hash();
  switch (hash & 7) {
    case 1:
      HASH_GUARD_LITSTR(0x78AE97BFBEBF5341LL, NAMSTR(s_sys_ssf052ec6b, "close")) {
        mcp.ci = &c_Directory::ci_close;
        return true;
      }
      HASH_GUARD_LITSTR(0x1F479267E49EF301LL, NAMSTR(s_sys_sse896cb09, "read")) {
        mcp.ci = &c_Directory::ci_read;
        return true;
      }
      break;
    case 2:
      HASH_GUARD_LITSTR(0x1670096FDE27AF6ALL, NAMSTR(s_sys_ss941ca25f, "rewind")) {
        mcp.ci = &c_Directory::ci_rewind;
        return true;
      }
      break;
    case 7:
      HASH_GUARD_LITSTR(0x0D31D0AC229C615FLL, NAMSTR(s_sys_ssa1b87da7, "__construct")) {
        mcp.ci = &c_Directory::ci___construct;
        return true;
      }
      break;
    default:
      break;
  }
  return c_ObjectData::os_get_call_info(mcp, hash);
}
bool c_Directory::o_get_call_info(MethodCallPackage &mcp, int64 hash) {
  mcp.obj = this;
  return os_get_call_info(mcp, hash);
}
c_Directory *c_Directory::create(Variant v_path) {
  CountableHelper h(this);
  init();
  t___construct(v_path);
  return this;
}
ObjectData *c_Directory::dynCreate(CArrRef params, bool construct /* = true */) {
  init();
  if (construct) {
    CountableHelper h(this);
    int count __attribute__((__unused__)) = params.size();
    if (count != 1) throw_wrong_arguments("Directory::__construct", count, 1, 1, 2);
    {
      ArrayData *ad(params.get());
      ssize_t pos = ad ? ad->iter_begin() : ArrayData::invalid_index;
      CVarRef arg0((ad->getValue(pos)));
      (t___construct(arg0));
    }
  }
  return this;
}
void c_Directory::dynConstruct(CArrRef params) {
  int count __attribute__((__unused__)) = params.size();
  if (count != 1) throw_wrong_arguments("Directory::__construct", count, 1, 1, 2);
  {
    ArrayData *ad(params.get());
    ssize_t pos = ad ? ad->iter_begin() : ArrayData::invalid_index;
    CVarRef arg0((ad->getValue(pos)));
    (t___construct(arg0));
  }
}
void c_Directory::getConstructor(MethodCallPackage &mcp) {
  mcp.ci = &c_Directory::ci___construct;
  mcp.obj = this;
}
void c_Directory::dynConstructFromEval(Eval::VariableEnvironment &env, const Eval::FunctionCallExpression *caller) {
  Variant a0;
  const std::vector<Eval::ExpressionPtr> &params = caller->params();
  std::vector<Eval::ExpressionPtr>::const_iterator it = params.begin();
  do {
    if (it == params.end()) break;
    a0 = (*it)->eval(env);
    it++;
  } while(false);
  for (; it != params.end(); ++it) {
    (*it)->eval(env);
  }
  int count __attribute__((__unused__)) = params.size();
  if (count != 1) throw_wrong_arguments("Directory::__construct", count, 1, 1, 1);
  (t___construct(a0), null);
}
struct ObjectStaticCallbacks cw_Directory = {
  c_Directory::os_getInit,
  c_Directory::os_get,
  c_Directory::os_lval,
  c_Directory::os_invoke,
  c_Directory::os_constant,
  c_Directory::os_get_call_info
};
void c_Directory::init() {
  m_path = null;
  m_handle = null;
}
/* SRC: classes/directory.php line 7 */
void c_Directory::t___construct(Variant v_path) {
  INSTANCE_METHOD_INJECTION_BUILTIN(Directory, Directory::__construct);
  bool oldInCtor = gasInCtor(true);
  m_path = v_path;
  {
    const Variant &tmp0((x_opendir(toString(v_path))));
    m_handle = tmp0;
  }
  gasInCtor(oldInCtor);
}
namespace hphp_impl_splitter {}
/* SRC: classes/directory.php line 12 */
Variant c_Directory::t_read() {
  INSTANCE_METHOD_INJECTION_BUILTIN(Directory, Directory::read);
  return x_readdir(toObject(m_handle));
}
namespace hphp_impl_splitter {}
/* SRC: classes/directory.php line 16 */
void c_Directory::t_rewind() {
  INSTANCE_METHOD_INJECTION_BUILTIN(Directory, Directory::rewind);
  x_rewinddir(toObject(m_handle));
}
namespace hphp_impl_splitter {}
/* SRC: classes/directory.php line 20 */
void c_Directory::t_close() {
  INSTANCE_METHOD_INJECTION_BUILTIN(Directory, Directory::close);
  x_closedir(toObject(m_handle));
}
namespace hphp_impl_splitter {}
Object co_Directory(CArrRef params, bool init /* = true */) {
  return Object((NEW(c_Directory)())->dynCreate(params, init));
}
Object coo_Directory() {
  Object r(NEW(c_Directory)());
  r->init();
  return r;
}
Variant pm_php$classes$directory_php(bool incOnce /* = false */, LVariableTable* variables /* = NULL */, Globals *globals /* = get_globals() */) {
  PSEUDOMAIN_INJECTION_BUILTIN(run_init::classes/directory.php, pm_php$classes$directory_php);
  LVariableTable *gVariables __attribute__((__unused__)) = (LVariableTable *)g;
  return true;
}
namespace hphp_impl_splitter {}

///////////////////////////////////////////////////////////////////////////////
}
