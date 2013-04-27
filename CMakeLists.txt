cmake_minimum_required(VERSION 2.8.9 FATAL_ERROR)
project(NameGenerator)

SET(CMAKE_INCLUDE_CURRENT_DIR ON)
SET(CMAKE_AUTOMOC ON)

find_package(Qt5Widgets REQUIRED)

SET(QT_USE_QTMAIN TRUE)


SET(QtApp_RCCS resources.qrc)
set(CMAKE_CXX_FLAGS_COVERAGE "${CMAKE_CXX_FLAGS_RELEASE} -fprofile-arcs -ftest-coverage")

# set up a mapping so that the Release configuration for the Qt imported target is
# used in the COVERAGE CMake configuration.
set_target_properties(Qt5::Widgets PROPERTIES MAP_IMPORTED_CONFIG_COVERAGE "RELEASE")
qt5_add_resources(QtApp_RCC_SRCS ${QtApp_RCCS})
# Tell CMake to create the helloworld executable


add_executable(NameGenerator
        main.cpp
        namegenerator.h
        namegenerator.cpp
        namegenerator.ui
        namesgenerator.h
        namesgenerator.cpp
        ${QtApp_RCC_SRCS}
        )

#set_target_properties(NameGenerator PROPERTIES POSITION_INDEPENDENT_CODE ON)

# Use the Widgets module from Qt 5
qt5_use_modules(NameGenerator Widgets)

# Support UI files
qt5_wrap_ui(ui_namegenerator.h namegenerator.ui)
TARGET_LINK_LIBRARIES(NameGenerator ${QT_LIBRARIES})