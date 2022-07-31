//
//  lua_inchi.cpp
//  lua-inchi
//

#include <string.h>
#include <stdlib.h>

#include "inchi_api.h"

extern int MakeINCHIFromMolfileText( const char *moltext,
                                    char *szOptions,
                                    inchi_Output *result );

#define LUA_LIB
extern "C" {
#include "lua.h"
#include "lauxlib.h"
}

#if LUA_VERSION_NUM > 501
//
// Lua 5.2
//
#define lua_strlen lua_rawlen
// luaL_typerror always used with arg at ndx == NULL
#define luaL_typerror(L,ndx,str) luaL_error(L,"bad argument %d (%s expected, got nil)",ndx,str)
// luaL_register used once, so below expansion is OK for this case
#define luaL_register(L,name,reg) lua_newtable(L);luaL_setfuncs(L,reg,0)
// luaL_openlib always used with name == NULL
#define luaL_openlib(L,name,reg,nup) luaL_setfuncs(L,reg,nup)
#endif

#include "gideros.h"

static int mol2inchi(lua_State *L) {
    char* inchi = "";
    inchi_Output result;
    size_t mol_len = 0;
    const char* mol = lua_tolstring(L, -1, &mol_len);
    memset(&result, 0, sizeof(result));
    
    if (mol_len > 0) {
        char szMol[mol_len+1];
        
        memcpy(szMol, mol, mol_len);
        szMol[mol_len] = 0;
        
        int x = MakeINCHIFromMolfileText(szMol, "", &result);
        if ((x == 0 || x == 1) && result.szInChI != 0) {
            inchi = result.szInChI;
        }
    }
    
    if (inchi != 0) {
        lua_pushstring(L, inchi);
    }
    else {
        lua_pushnil(L);
    }
    
    FreeINCHI(&result);
    return 1;
}

static int loader(lua_State *L)
{
    const luaL_Reg functionlist[] = {
        {"mol2inchi", mol2inchi},
        {NULL, NULL},
    };
    luaL_register(L, "luainchi", functionlist);
    
    //return the pointer to the plugin
    return 1;
}

static void g_initializePlugin(lua_State* L)
{
    lua_getglobal(L, "package");
    lua_getfield(L, -1, "preload");
    
    lua_pushcnfunction(L, loader, "plugin_init_inchi");
    lua_setfield(L, -2, "luainchi");
    
    lua_pop(L, 2);
}

static void g_deinitializePlugin(lua_State* L)
{
    
}

REGISTER_PLUGIN("luainchi", "1.0")
