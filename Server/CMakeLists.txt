cmake_minimum_required(VERSION 3.26)
project(Server)

set(CMAKE_CXX_STANDARD 17)

add_executable(Server main.cpp
        Session.cpp
        Session.h
        Server.cpp
        Server.h
        Server.cpp
        Server.h
        Session.cpp
        Session.h
        Storage.cpp
        Storage.h
)

set(BOOST_ROOT "C:/Programming/CLion/Libraries/boost_1_82_0/boost_1_82_0")
include_directories("C:/Programming/CLion/Libraries/boost_1_82_0/boost_1_82_0")
include_directories(${Boost_INCLUDE_DIRS})
find_package(Boost REQUIRED)
target_include_directories(Server PRIVATE ${Boost_INCLUDE_DIRS})
target_link_libraries(Server ${Boost_LIBRARIES})


if(MINGW)
    target_link_libraries(Server ws2_32)
    target_link_libraries(Server wsock32)
endif()



