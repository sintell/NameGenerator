 cmake_minimum_required(VERSION 2.8.9 FATAL_ERROR)
 project(namegenerator)

 # Find includes in corresponding build directories
 set(CMAKE_INCLUDE_CURRENT_DIR ON)
 # Instruct CMake to run moc automatically when needed
 set(CMAKE_AUTOMOC ON)

 set(CMAKE_PREFIX_PATH "/home/sintell/Qt5.0.2/5.0.2/gcc")
 # Find the QtWidgets library
 find_package(Qt5Widgets REQUIRED)

 # Tell CMake to create the helloworld executable
 add_executable(namegenerator
     main.cpp
     namegenerator.h
     namegenerator.cpp
     namegenerator.ui
     namesgenerator.h
     namesgenerator.cpp
 )

 # Use the Widgets module from Qt 5
 qt5_use_modules(namegenerator Widgets)

 # Support UI files
 qt5_wrap_ui(ui_namegenerator.h namegenerator.ui)
