cmake_minimum_required(VERSION 3.21)
project(test)

set(CMAKE_CXX_STANDARD 14)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})

include_directories(sciter/include)
add_definitions(${GTK3_CFLAGS_OTHER})

add_executable(test main.cpp sciter/include/sciter-gtk-main.cpp)
