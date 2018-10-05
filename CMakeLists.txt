cmake_minimum_required(VERSION 3.10)
project(CPP_babel_2018
        VERSION 0.0.0
        DESCRIPTION "It's a babel :p"
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

if (MSVC)
    if (CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
        string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
    else ()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
    endif ()
elseif (CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
endif ()

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

find_package(Threads REQUIRED)
find_package(Qt5 COMPONENTS Gui Core Widgets Network REQUIRED)

include_directories(includes/common)
SET(COMMON_SRCS
        sources/common/Factory.cpp
        sources/common/IObservable.cpp
        sources/common/PrintVector.cpp)

############################################

SET(CLIENT_SRCS
        sources/client/main.cpp
        sources/client/Opus.cpp
        sources/client/PaInput.cpp
        sources/client/PaOutput.cpp
        sources/client/Core.cpp
        includes/client/Core.hpp
        sources/client/UI/Login.cpp
        includes/client/UI/Login.hpp
        includes/client/UI/Home.hpp
        sources/client/UI/Home.cpp
        sources/client/Network/UDPNetwork.cpp
        includes/client/Network/UDPNetwork.hpp
        includes/client/Network/NetworkConfig.hpp
        sources/client/UI/Call.cpp
        includes/client/UI/Call.hpp
        sources/client/Network/TCPNetwork.cpp
        includes/client/Network/TCPNetwork.hpp)

add_executable(babel_client ${CLIENT_SRCS} ${COMMON_SRCS})

target_include_directories(babel_client PRIVATE includes/client)

target_link_libraries(babel_client ${CONAN_LIBS} Qt5::Widgets Qt5::Core Qt5::Gui Qt5::Network)

add_custom_command(TARGET babel_client PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/media $<TARGET_FILE_DIR:babel_client>/media)
#############################################

SET(SERVER_SRCS
        sources/server/main.cpp
        sources/server/Server.cpp
        sources/server/Client.cpp
        sources/server/server_commands.cpp)

add_executable(babel_server ${SERVER_SRCS} ${COMMON_SRCS})

target_include_directories(babel_server PRIVATE includes/server)

target_link_libraries(babel_server ${CONAN_LIBS} ${CMAKE_THREAD_LIBS_INIT})
#############################################
