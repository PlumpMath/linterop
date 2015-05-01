cmake_minimum_required(VERSION 2.8)
project(linterop_test)

#aux_source_directory(. MODELTEST_SRC)
#include(SourceList)

set(INTEROP_ACCESS_SRC
    ./src/interop/access/lua_access.cpp
    ./src/interop/access/lua_access.h
    ./src/interop/access/lua_access_class.cc
    ./src/interop/access/lua_access_class.hpp
    ./src/interop/access/lua_access_macros.h
)

source_group(interop/access
    FILES ${INTEROP_ACCESS_SRC}
)

set(INTEROP_SRC
    ./src/interop/lextension.c
    ./src/interop/lextension.h
    ./src/interop/luacomm.cc
    ./src/interop/luacomm.h
    ./src/interop/luathread.hpp
    ./src/interop/luavm.cc
    ./src/interop/luavm.h
)

source_group(interop
    FILES ${INTEROP_SRC}
)

set(TEST_SRC
    ./test/main.cc
)

source_group(test
    FILES ${TEST_SRC}
)

add_executable(interoptest ${INTEROP_ACCESS_SRC} ${INTEROP_SRC} ${TEST_SRC})
include_directories(./src)

set_target_properties(interoptest
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/output"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/output"
)


