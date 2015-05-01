

#include "luavm.h"
#include <cassert>

namespace DD
{

LuaVM::LuaVM()
	:_L(nullptr),
	taskID_(0),
	lastTaskID_(0)
{
	_L = luaL_newstate();
	luaL_openlibs(_L);
	LuaCore::doExports(_L);
	LuaCore::injectLuaCore(_L);
	LuaCore::injectExperimental(_L);
}

LuaVM::~LuaVM()
{
	purge();
	lua_close(_L);
}

void LuaVM::purge()
{
	_task.clear();
	pool_.clear();
}

bool LuaVM::loadScript(const char *path)
{
	int top = lua_gettop(_L);
	if(luaL_loadfile(_L, path)){
		fprintf(stderr, "Error loading %s\n", path);
		lua_pop(_L, 1);
		assert( lua_gettop(_L) == top);
		return false;
	}
	if(lua_pcall(_L, 0, 0, 0)){
		const char *err = lua_tostring(_L, -1);
		fprintf(stderr, "script error :%s\n", err);
		lua_pop(_L, 1);
		assert(lua_gettop(_L) == top);
		return false;
	}
	assert( lua_gettop(_L) == top);
	return true;
}

void LuaVM::step()
{
	lua_State *S = nullptr;
	for(auto it=_task.begin();it!=_task.end();++it)
	{
		int status = lua_status(it->first);
		if(LUA_YIELD == status)
		{
			S = it->first;
			break;
		}
	}

	if(S)
	{
		lua_resume(S, 0);
		finalize(S);
	}
	else
	{
		printf("LuaVM:step: No task for now.\n");
		printf("ThreadPool: (%d)\n", pool_.size());
	}
}


//Find a free thread
lua_State* LuaVM::thread()
{
	for(auto it=pool_.begin();it!=pool_.end();)
	{
		LuaThreadRef one = *it;
		int status = it->status();
		if( 0 == status )
		{
			auto pos = _task.find(one.state());
			if( pos == _task.end())
			{
				return one.state();
			}
			//No this one
			++it;
		}
		else if(LUA_YIELD == status)
		{
			++it;
		}
		else
		{
			//Error happened.
			it = pool_.erase(it);	//~ next
		}
	}

	LuaThreadRef one(_L);
	pool_.push_back(one);
	return one.state();
}

lua_State* LuaVM::start(const char *func)
{
	lua_State *S = thread();
	int top = lua_gettop(S);
	lua_getglobal(S, func);
	if(!lua_isfunction(S, -1))
	{
		lua_pop(S, 1);
		assert(top == lua_gettop(S));
		return 0;
	}
	/*int firstStart = */
	lua_resume(S, 0);
	_task[S] = ++taskID_;
	return S;	//~ go
}

void LuaVM::finalize(lua_State *t)
{
	int status = lua_status(t);
	if(0==status)
	{
		auto it = _task.find(t);
		if(it!=_task.end())
		{
			_task.erase(it);
		}
		lastTaskID_ = 0;
	}
	else if(LUA_YIELD == status)
	{
		auto it = _task.find(t);
		lastTaskID_ = (it!=_task.end() ? it->second:0);
	}
	else
	{
		const char *err = lua_tostring(t, -1);
		fprintf(stderr, "LuaVM :%s\n", err);
		lua_pop(t, 1);
		auto it = _task.find(t);
		if(it!=_task.end())
		{
			_task.erase(it);
		}
		lastTaskID_ = 0;
	}
}




}//End of namespace



