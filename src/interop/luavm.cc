

#include "luavm.h"
#include <cassert>
#include "interop/interopconf.h"

namespace DD
{

LuaVM::LuaVM()
	:_luaStateObj(nullptr),
	taskID_(0),
	lastTaskID_(0)
{
	_luaStateObj = luaL_newstate();
	luaL_openlibs(_luaStateObj);
	_InitLuaVM(_luaStateObj);
}

LuaVM::~LuaVM()
{
	purge();
	lua_close(_luaStateObj);
}

void LuaVM::purge()
{
	_task.clear();
	pool_.clear();
}

bool LuaVM::loadScript(const char *path)
{
	int top = lua_gettop(_luaStateObj);
	if(luaL_loadfile(_luaStateObj, path)){
		fprintf(stderr, "Error loading %s\n", path);
		lua_pop(_luaStateObj, 1);
		assert( lua_gettop(_luaStateObj) == top);
		return false;
	}
	if(lua_pcall(_luaStateObj, 0, 0, 0)){
		const char *err = lua_tostring(_luaStateObj, -1);
		fprintf(stderr, "script error :%s\n", err);
		lua_pop(_luaStateObj, 1);
		assert(lua_gettop(_luaStateObj) == top);
		return false;
	}
	assert( lua_gettop(_luaStateObj) == top);
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

	LuaThreadRef one(_luaStateObj);
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



