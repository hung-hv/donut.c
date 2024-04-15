cmake_minimum_required(VERSION 3.15)
project (donut)

include_directories(include)

set(SOURCES src/main.c src/fps.c src/cursor.c src/torus.c)

add_executable(donut ${SOURCES})