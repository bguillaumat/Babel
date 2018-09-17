cmake_minimum_required(VERSION 3.12)
project(CPP_babel_2018
        VERSION 0.0.0
        DESCRIPTION "It's a babel :p")

set(CMAKE_CXX_STANDARD 17)

include(conanbuildinfo.cmake)
conan_basic_setup()

############################################

add_executable(babel_client)

target_sources(babel_client PRIVATE
        sources/client/main.cpp)

target_sources(babel_client PRIVATE
        includes/client/client.hpp)

target_include_directories(babel_client PRIVATE includes/client)

target_link_libraries(babel_client ${CONAN_LIBS})


#############################################

add_executable(babel_server)

target_sources(babel_server PRIVATE
        sources/server/main.cpp)

target_sources(babel_server PRIVATE
        includes/server/server.hpp)

target_include_directories(babel_server PRIVATE includes/server)

target_link_libraries(babel_server ${CONAN_LIBS})
#############################################