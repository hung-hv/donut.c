cmake_minimum_required(VERSION 3.15)
project (donut)

include_directories(include)

set(SOURCES src/main.c src/cursor.c src/torus.c src/render_fps.c)

add_executable(donut ${SOURCES})