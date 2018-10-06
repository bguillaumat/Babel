cmake_minimum_required(VERSION 3.10)
project(CPP_babel_2018
        VERSION 1.0.0
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

SET(COMMON_SRCS
        sources/common/Factory.cpp
        sources/common/IObservable.cpp
        sources/common/PrintVector.cpp
        includes/common/Factory.hpp
        includes/common/IObservable.hpp
        includes/common/IObservateur.hpp
        includes/common/PrintVector.hpp)

############################################

SET(CLIENT_INC
        includes/client/Core.hpp
        includes/client/DecodedSound.hpp
        includes/client/EncodedSound.hpp
        includes/client/IAudio.hpp
        includes/client/ICompressor.hpp
        includes/client/INetwork.hpp
        includes/client/Opus.hpp
        includes/client/PaInput.hpp
        includes/client/PaOutput.hpp
        includes/client/SoundDeviceSettings.hpp
        includes/client/UI/Login.hpp
        includes/client/UI/Home.hpp
        includes/client/UI/Call.hpp
        includes/client/Network/UDPNetwork.hpp
        includes/client/Network/NetworkConfig.hpp
        includes/client/Network/TCPNetwork.hpp)

SET(CLIENT_SRCS
        sources/client/main.cpp
        sources/client/Opus.cpp
        sources/client/PaInput.cpp
        sources/client/PaOutput.cpp
        sources/client/Core.cpp
        sources/client/UI/Login.cpp
        sources/client/UI/Home.cpp
        sources/client/Network/UDPNetwork.cpp
        sources/client/UI/Call.cpp
        sources/client/Network/TCPNetwork.cpp)

add_executable(babel_client ${CLIENT_SRCS} ${COMMON_SRCS} ${CLIENT_INC})

target_link_libraries(babel_client ${CONAN_LIBS} Qt5::Widgets Qt5::Core Qt5::Gui Qt5::Network)

add_custom_command(TARGET babel_client PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/media $<TARGET_FILE_DIR:babel_client>/media)
#[[
if (UNIX)
    add_custom_command(TARGET babel_client
            POST_BUILD
            COMMAND ${CMAKE_SOURCE_DIR}/configure/export_path ${CONAN_QT_ROOT}/plugins)
endif (UNIX)
]]

if (MSVC)
    add_custom_command(TARGET babel_client POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${CONAN_BIN_DIRS_QT} $<TARGET_FILE_DIR:babel_client>)

    add_custom_command(TARGET babel_client POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${CONAN_QT_ROOT}/plugins/platforms $<TARGET_FILE_DIR:babel_client>/platforms)

    add_custom_command(TARGET babel_client POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${CONAN_PORTAUDIO_ROOT}/bin $<TARGET_FILE_DIR:babel_client>)

endif(MSVC)

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
