cmake_minimum_required(VERSION 3.2)

project(codenuances)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(explicitTemplateInstantiation STATIC explicitTemplateInstantiation.cpp)

add_executable(explicitTemplateInstantiationTest explicitTemplateInstantiationTest.cpp)

target_link_libraries(explicitTemplateInstantiationTest
  explicitTemplateInstantiation)
