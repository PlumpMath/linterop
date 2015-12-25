
#ifndef _CHECK_STACK_LUA_DEF__
#define _CHECK_STACK_LUA_DEF__

#include <cassert>

class _BCheck_clz{
public:
	_BCheck_clz(lua_State *L):
		_L(L),
		_top(lua_gettop(L)){
	}

	~_BCheck_clz(){
		assert(_top == lua_gettop(_L));
	}

private:
	lua_State* const _L;
	const int _top;
};

#define _BC(L)	_BCheck_clz ___12300xxx(L)

#endif