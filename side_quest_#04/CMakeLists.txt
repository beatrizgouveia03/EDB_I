cmake_minimum_required(VERSION 3.5)

project(exercises VERSION 1.0 LANGUAGES CXX)

add_executable( program 
                src/main.cpp)
set_property(TARGET program PROPERTY CXX_STANDARD 20)