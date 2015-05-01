

#ifndef _LUA_THREAD__DEF__
#define _LUA_THREAD__DEF__

extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}
#include <cassert>

namespace DD
{
	class LuaThread
	{
	public:
		LuaThread(lua_State *t)
			:thread_(t)
		{

		}

		int status()
		{
			return lua_status(thread_);
		}

		int yield()
		{
			return lua_yield(thread_, 0);
		}

		int resume()
		{
			return lua_resume(thread_, 0);
		}

		lua_State* state()
		{
			return thread_;
		}

	private:
		lua_State *thread_;

	private:
		LuaThread(const LuaThread&);
		LuaThread& operator=(const LuaThread&);
	};

	//////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	struct LuaThreadRef
	{
		LuaThreadRef(lua_State *master)
			:thread_(nullptr), 
			master_(master),
			ref_(LUA_REFNIL),
			counter_(nullptr)
		{
			const int top = lua_gettop(master);
			lua_State *thread = lua_newthread(master);
			assert( 0 == lua_gettop(thread));
			ref_ = luaL_ref(master, LUA_REGISTRYINDEX);
			counter_ = new int(1);
			thread_ = new LuaThread(thread);
			assert(lua_gettop(master) == top);
		}

		LuaThreadRef()
			:master_(nullptr),
			thread_(nullptr),
			ref_(LUA_REFNIL),
			counter_(nullptr)
		{

		}

		~LuaThreadRef()
		{
			deinit();
		}

		LuaThreadRef(const LuaThreadRef&rhs)
			:counter_(nullptr),
			master_(nullptr),
			thread_(nullptr),
			ref_(LUA_REFNIL)
		{
			copy(rhs);
		}

		LuaThreadRef& operator=(const LuaThreadRef&rhs)
		{
			return copy(rhs);
		}

		LuaThreadRef& copy(const LuaThreadRef &rhs)
		{
			deinit();
			if(rhs.counter_)
			{
				master_ = rhs.master_;
				thread_ = rhs.thread_;
				ref_ = rhs.ref_;
				counter_ = rhs.counter_;
				++(*counter_);
			}
			return *this;
		}

		void deinit()
		{
			if(counter_)
			{
				--(*counter_);
				if(0==*counter_)
				{
					luaL_unref(master_, LUA_REGISTRYINDEX, ref_);
					delete thread_;
					delete counter_;
				}
			}

			master_ = nullptr;
			thread_ = nullptr;
			counter_ = nullptr;
			ref_ = LUA_REFNIL;
		}

		lua_State* state()const
		{
			return thread_->state();
		}

		int status()
		{
			return thread_->status();
		}

	private:
		lua_State *master_;
		LuaThread *thread_;
		int *counter_;
		int ref_;
	};



}

#endif