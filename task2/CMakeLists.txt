cmake_minimum_required(VERSION 3.5)
project(SORT)

IF(NOT CMAKE_BUILD_TYPE)
  SET(CAMKE_BUILD_TYPE Release)
ENDIF()

add_executable(SORT sort-1.cpp)