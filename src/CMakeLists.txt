cmake_minimum_required(VERSION 2.8)
project(linterop_test)

add_subdirectory(../external/lua/src, ${CMAKE_BINARY_DIR}/lib/lua)

set(L_ACCESS_SRC
    ./interop/access/lua_access.cpp
    ./interop/access/lua_access.h
    ./interop/access/lua_access_class.cc
    ./interop/access/lua_access_class.hpp
    ./interop/access/lua_access_macros.h
    ./interop/access/refobj.cpp
    ./interop/access/refobj.h
    ./interop/access/refproto.cpp
    ./interop/access/refproto.h
)

source_group(interop/access
    FILES ${L_ACCESS_SRC}
)

set(INTEROP_SRC
    ./interop/lextension.c
    ./interop/lextension.h
    ./interop/luacomm.cc
    ./interop/luacomm.h
    ./interop/luathread.hpp
    ./interop/luavm.cc
    ./interop/luavm.h
)

source_group(interop
    FILES ${INTEROPSRC}
)

set(TEST_SRC
    ./test/main.cc
)

source_group(test
    FILES ${TEST_SRC)
)

add_executable(linterop_test
    ${TEST_SRC} ${L_ACCESS_SRC} ${INTEROP_SRC}
)

include_directory(./src)

target_link_libraries(linterop_test, liblua)
#set_target_properties(linterop_test,
    
