
#include "experimental.h"

extern "C" {
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
}

#include <cstdio>
#include <cstdlib>

#include "EventCenter.h"
#include "interop/luacomm.h"

#include <functional>

static int wait(lua_State *L)
{
	float waits = lua_tonumber(L, 1);
	//printf("You wait %f!\n", waits);
	EventCenter::instance()->Go.connect(std::bind(&DD::VmProcedure::resume, L), 1);
	return lua_yield(L, 0);
}

static luaL_reg entries[]={
	{"wait", wait},
	{NULL, NULL}
};

namespace LuaCore
{

void injectExperimental(lua_State *L)
{
	luaL_register(L, "exp", entries);
}


}