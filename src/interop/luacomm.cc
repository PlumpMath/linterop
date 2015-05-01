

#include "luacomm.h"

extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

namespace DD{
namespace VmProcedure{

	int resume(lua_State *S)
	{
		return lua_resume(S, 0);
	}

	int status(lua_State *S)
	{
		return lua_status(S);
	}

	int yield(lua_State *S)
	{
		return lua_yield(S, 0);
	}
}}