// mylib.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "mylib.h"


#include "math.h"

static int l_cos(lua_State * L)
{
	double d = luaL_checknumber(L,1); // first argument
	lua_pushnumber(L,cos(d)); // push first result
	return 1; // count of argument
}

static const struct luaL_Reg mylibs[] = 
{
	{
		"mycos",l_cos
	},
	{
		NULL,NULL
	}
};

int luaopen_mylib( lua_State * L )
{
	luaL_register(L,"mylib",mylibs);
	return 1;
}
