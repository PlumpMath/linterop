

#ifndef _LUA_COMMON_DEF__
#define _LUA_COMMON_DEF__

struct lua_State;

namespace DD
{
	namespace VmProcedure
	{
		int resume(lua_State*);
		int status(lua_State*);
		int yield(lua_State*);
	}
};


#endif