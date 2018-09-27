cmake_minimum_required(VERSION 3.10)
project(CPP_babel_2018
        VERSION 0.0.0
        DESCRIPTION "It's a babel :p")

set(CMAKE_CXX_STANDARD 17)

include(conanbuildinfo.cmake)
conan_basic_setup()

find_package(Qt5Widgets CONFIG REQUIRED)

include_directories(includes/common)
SET(COMMON_SRCS
		sources/common/Factory.cpp
		sources/common/IObservable.cpp
		)

############################################

SET(CLIENT_SRCS
	sources/client/main.cpp
	sources/client/Opus.cpp
	sources/client/PaInput.cpp
	sources/client/PaOutput.cpp)

add_executable(babel_client ${CLIENT_SRCS} ${COMMON_SRCS} includes/client/IAudio.hpp)

target_include_directories(babel_client PRIVATE includes/client)

target_link_libraries(babel_client ${CONAN_LIBS} Qt5::Widgets)
#############################################

SET(SERVER_SRCS sources/server/main.cpp)

add_executable(babel_server ${SERVER_SRCS})

target_include_directories(babel_server PRIVATE includes/server)

target_link_libraries(babel_server ${CONAN_LIBS} ${COMMON_SRCS})
#############################################
