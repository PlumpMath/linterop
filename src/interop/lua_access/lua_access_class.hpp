
#ifndef _LUA_ACCESS_CLASS_DEF__
#define _LUA_ACCESS_CLASS_DEF__

//incuded by lua_access.h
#include <cassert>

//class LuaStateHost
//{ 
//public:
//	LuaStateHost()
//		:_S(nullptr)
//	{
//
//	}
//
//private:
//	lua_State *_S;
//};

class FuncRef
{
public:
	FuncRef(lua_State *L);
	FuncRef(const char *name, lua_State *L);
	~FuncRef();

	//
	FuncRef(const FuncRef&rhs);
	FuncRef& operator=(const FuncRef &rhs);
	bool require(const char *path);

private:
	FuncRef& copy(const FuncRef &rhs);
	void deinit();
	void take(int ref);

public:
	void loadFunc(const char *name);
	int createObj();

private:
	int _ref;
	int *_refCounter;
	lua_State *const L_;
};

class ObjContainer{
public:
	ObjContainer(lua_State *L);
	~ObjContainer();
	bool addObject(int obj);
	int tableRef();
	void clear();

private:
	int _ref;
	int _objCount;
	lua_State *const L_;

private:
	ObjContainer(const ObjContainer&);
	ObjContainer&operator=(const ObjContainer&);
};


#endif