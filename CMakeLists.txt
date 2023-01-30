cmake_minimum_required(VERSION 3.0.0)
project(Wifi_Management VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(Wifi_Management main.c)
include_directories(include)
include_directories(src)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
