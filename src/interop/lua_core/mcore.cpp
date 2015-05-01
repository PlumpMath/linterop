
#include "mcore.h"
#include <cstdio>

extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

#include "nodes/EsNode.h"

//
//static int readDataChunk(lua_State *L) {
//	const char *filepath = luaL_checkstring(L, 1);
//	const char *mode = luaL_checkstring(L, 2);
//
//	//FileUtils::getFileData will try to get full-path for the input file. (inside job)
//
//	//In the old days
//	//ssize_t size = 0;
//	//unsigned char *pBytes = FileUtils::getInstance()->getFileData(filepath, mode, &size);
//	//free(pBytes);
//
//	auto data = FileUtils::getInstance()->getDataFromFile(filepath);
//	lua_pushlstring(L, (const char*)(data.getBytes()), data.getSize());
//	return 1;
//}

static int testEntryOne(lua_State *L){
	puts("Hello, this is testEntryOne");
	return 0;
}

static int setEsNodeTransform(lua_State *L)
{
	int top = lua_gettop(L);
	if(top!=4) {
		luaL_error(L,"Parameter error");
	}
	EsNode *node = (EsNode*)lua_touserdata(L, 1);
	float x = lua_tonumber(L, 2);
	float y = lua_tonumber(L, 3);
	float z = lua_tonumber(L, 4);
	node->setTransform(x,y,z);
	return 0;
}

static int setEsNodeRotate(lua_State *L)
{
	int top = lua_gettop(L);
	if(top!=2){
		luaL_error(L, "parameter error for set-esnode-rotate");
	}
	EsNode *node = (EsNode*)lua_touserdata(L, 1);
	float angle = lua_tonumber(L, 2);
	node->setRotate(angle, 0, 1, 0);
	return 0;
}

static int setEsNodeScale(lua_State *L)
{
	int top = lua_gettop(L);
	float xs = -1, ys = -1, zs = -1;
	if(top<1){
		luaL_error(L, "No parameter for esnode set scale");
	}
	if(top>=2){
		xs = lua_tonumber(L, 2);
	}
	if(top>=3){
		ys = lua_tonumber(L, 3);
	}
	if(top>=4){
		zs = lua_tonumber(L, 4);
	}
	EsNode *node = (EsNode*)lua_touserdata(L, 1);
	node->setScale(xs, ys, zs);
	return 0;;
}

static luaL_Reg _regs[]={
	{"test", testEntryOne},
	{"setEsNodeTransform", setEsNodeTransform},
	{"setEsNodeRotate",    setEsNodeRotate},
	{"setEsNodeScale",     setEsNodeScale},
	{NULL, NULL},
};

//Call from start
void installMDataExports(lua_State *L) {
	luaL_register(L, "mcore", _regs);
}