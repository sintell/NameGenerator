cmake_minimum_required(VERSION 2.8.9 FATAL_ERROR)
project(namegenerator)
SET(CMAKE_INCLUDE_CURRENT_DIR ON)
SET(CMAKE_AUTOMOC ON)
set(CMAKE_PREFIX_PATH "/home/sintell/Qt5.0.2/5.0.2/gcc")
find_package(Qt5Widgets REQUIRED)
SET(QtApp_RCCS resources.qrc)

qt5_add_resources(QtApp_RCC_SRCS ${QtApp_RCCS})
# Tell CMake to create the helloworld executable
add_executable(namegenerator
        main.cpp
        namegenerator.h
        namegenerator.cpp
        namegenerator.ui
        namesgenerator.h
        namesgenerator.cpp
        ${QtApp_RCC_SRCS}
        )

# Use the Widgets module from Qt 5
qt5_use_modules(namegenerator Widgets)

# Support UI files
qt5_wrap_ui(ui_namegenerator.h namegenerator.ui)

TARGET_LINK_LIBRARIES( namegenerator ${QT_LIBRARIES}  )
