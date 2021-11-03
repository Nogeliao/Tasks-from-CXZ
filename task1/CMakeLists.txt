cmake_minimum_required(VERSION 3.5)
project(POINTER)

IF(NOT CMAKE_BUILD_TYPE)
  SET(CAMKE_BUILD_TYPE Release)
ENDIF()

add_executable(POINTER pointer.cpp)