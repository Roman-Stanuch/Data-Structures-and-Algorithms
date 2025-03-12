cmake_minimum_required(VERSION 3.30)
project(Hashmap C)

set(CMAKE_C_STANDARD 11)

add_executable(Hashmap src/main.c
        src/hashmap.h
        src/hashmap.c)
