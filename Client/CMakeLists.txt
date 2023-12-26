cmake_minimum_required(VERSION 3.26)
project(Client)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "C:/Programming/CLion/Libraries/Qt/Qt5.12.12/5.12.12/mingw73_64/")

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(Client main.cpp
        Client.cpp
        Client.h
        WindowSetup.cpp
        WindowSetup.h
        UserActivityHandler.cpp
        UserActivityHandler.h
        ResponseHandler.cpp
        ResponseHandler.h
        Client.cpp
        Client.h
        ResponseHandler.cpp
        ResponseHandler.h
        UserActivityHandler.cpp
        UserActivityHandler.h
        WindowSetup.cpp
        WindowSetup.h)
target_link_libraries(Client
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)

if (WIN32 AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(DEBUG_SUFFIX)
    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif ()
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB Core Gui Widgets)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt5${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()


set(BOOST_ROOT "C:/Programming/CLion/Libraries/boost_1_82_0/boost_1_82_0")
include_directories("C:/Programming/CLion/Libraries/boost_1_82_0/boost_1_82_0")
include_directories(${Boost_INCLUDE_DIRS})
find_package(Boost REQUIRED)
target_include_directories(Client PRIVATE ${Boost_INCLUDE_DIRS})
target_link_libraries(Client ${Boost_LIBRARIES})

if(MINGW)
    target_link_libraries(Client ws2_32)
endif()