cmake_minimum_required(VERSION 3.21)
project(test)

set(CMAKE_CXX_STANDARD 20)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK REQUIRED gtk+-3.0)

include_directories(${GTK_INCLUDE_DIRS})
link_directories(${GTK_LIBRARY_DIRS})
add_definitions(${GTK_CFLAGS_OTHER})

include_directories(sciter-js-sdk/include)
add_executable(test sciter-js-sdk/include/sciter-gtk-main.cpp usciter.cpp)

#include_directories(sciter/include)
#add_executable(test sciter/include/sciter-gtk-main.cpp usciter.cpp)
target_link_libraries(test ${GTK_LIBRARIES})

