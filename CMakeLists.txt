cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(variation-gen)

add_executable(variation-gen src/main.cpp src/VariationGenerator.cpp)
set_property(TARGET variation-gen PROPERTY CXX_STANDARD 14)
