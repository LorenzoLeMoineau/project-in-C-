cmake_minimum_required(VERSION 3.24)
project(Projet_C C)

set(CMAKE_C_STANDARD 11)

add_executable(Projet_C main.c point.c point.h line.c line.h square.c square.h rectangle.c rectangle.h circle.c circle.h polygon.c polygon.h shapes.c shapes.h pixel_structure.c pixel_structure.h)
