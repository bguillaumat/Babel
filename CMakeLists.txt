cmake_minimum_required(VERSION 3.10)
project(CPP_babel_2018
        VERSION 0.0.0
        DESCRIPTION "It's a babel :p")

set(CMAKE_CXX_STANDARD 17)

if(MSVC)
	if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
		string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
	else()
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
	endif()
elseif(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
endif()

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

find_package(Qt5Widgets CONFIG REQUIRED)

include_directories(includes/common)
SET(COMMON_SRCS
		sources/common/Factory.cpp
		sources/common/IObservable.cpp)

############################################

SET(CLIENT_SRCS
	sources/client/main.cpp
	sources/client/Opus.cpp
	sources/client/PaInput.cpp
	sources/client/PaOutput.cpp sources/server/server.cpp includes/server/server.hpp sources/server/server_commands.cpp)

add_executable(babel_client ${CLIENT_SRCS} ${COMMON_SRCS} includes/client/IAudio.hpp)

target_include_directories(babel_client PRIVATE includes/client)

target_link_libraries(babel_client ${CONAN_LIBS} Qt5::Widgets)
#############################################

SET(SERVER_SRCS sources/server/main.cpp sources/server/server.cpp includes/server/server.hpp sources/server/log_funcs.cpp)

add_executable(babel_server ${SERVER_SRCS} ${COMMON_SRCS})

target_include_directories(babel_server PRIVATE includes/server)

target_link_libraries(babel_server ${CONAN_LIBS})
#############################################
