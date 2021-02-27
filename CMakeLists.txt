cmake_minimum_required(VERSION 3.10)
project(NebulaAccess)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(LIB3RD_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../NebulaDepend)
set(NEBULA_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../Nebula)
set(DEPEND_LIBS
    ${NEBULA_PATH}/lib/libnebula.so
    ${LIB3RD_PATH}/lib/libcryptopp.so
    ${LIB3RD_PATH}/lib/libprotobuf.so
    ${LIB3RD_PATH}/lib/libev.so
    )

include_directories(
    include
    ${LIB3RD_PATH}/include
    ${NEBULA_PATH}/src
)

add_executable(NebulaAccess
    src/Main.cpp
    src/CmdHello.cpp
    src/CmdSwitch.cpp
    src/StepSwitch.cpp
    )

target_link_libraries(NebulaAccess ${DEPEND_LIBS})
