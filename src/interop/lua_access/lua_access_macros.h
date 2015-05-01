

#ifndef _LUA_ACCESS_MACROS_DEF__
#define _LUA_ACCESS_MACROS_DEF__

extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

#include "LuaScriptor.h"

#define _DeclareState()	\
	int top = lua_gettop(L);

#define _GTrackBack	"__G__TRACKBACK__"

#endif