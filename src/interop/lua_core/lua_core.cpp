

#include "LuaScriptor.h"

extern "C" {
	#include "lauxlib.h"
}

#include "mcore.h"

namespace LuaCore{

void injectLuaCore(lua_State *L) {
	//lua_State *L = LuaScriptor::sharedInstance()->getLuaState();
	installMDataExports(L);
}



}//end of namespace
