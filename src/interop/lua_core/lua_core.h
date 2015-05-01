

#ifndef _CORE_LUA_DEF__H_
#define _CORE_LUA_DEF__H_

struct lua_State;

namespace LuaCore{
	void injectLuaCore(lua_State*);
}

// Use these template to make less error prone.
template<class T>
T* createUserData(lua_State *L) {
	T* rv = (T*)lua_newuserdata(L, sizeof(T));
	luaL_getmetatable(L, T::MetaName);
	if( lua_isnil(L, -1)){
		luaL_error(L, "No such metatable %s", T::MetaName);
	}
	lua_setmetatable(L, -2);	
	return rv;
}

template<class T>
T* checkUserData(lua_State *L, int ud) {
	return (T*)luaX_checkudata(L, ud, T::MetaName);
}

#define _TearInteger(T, R, O)\
	static int T##_##O(lua_State *L) {\
		T *target = checkUserData<T>(L,1);\
		R *cfg = target->ptrConfigRef;\
		lua_pushinteger(L, cfg->O);\
		return 1;\
	}

#define _TearString(T, R, O) \
	static int T##_##O(lua_State *L) {\
		T *target = checkUserData<T>(L, 1);\
		R *cfg = target->ptrConfigRef;\
		lua_pushstring(L, cfg->O.c_str());\
		return 1;\
	}

#endif

