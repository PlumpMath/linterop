

#ifndef _LUAVM_DEF__
#define _LUAVM_DEF__

#include <map>
#include <unordered_map>

extern "C" 
{
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

#include "luathread.hpp"
#include <vector>

namespace DD
{

class LuaVM
{
	//Wrapper

public:
	LuaVM();
	~LuaVM();

	bool loadScript(const char *path);
	lua_State* start(const char *func);
	void finalize(lua_State *t);
	void step();

private:
	void purge();
	lua_State *thread();	//~ All the same

private:
	lua_State *_luaStateObj;
	typedef std::unordered_map<lua_State*, int> TaskMap;
	TaskMap _task;
	int taskID_;
	std::vector<LuaThreadRef> pool_;
	int lastTaskID_;
};

}

#endif