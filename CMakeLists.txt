cmake_minimum_required(VERSION 3.1)
project(HORT_V2)


add_library(${PROJECT_NAME} src/main.cpp src/EZ-Template/auton_drive_functions.cpp src/EZ-Template/joystick_control.cpp src/EZ-Template/setup.cpp src/EZ-Template/util.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC include)