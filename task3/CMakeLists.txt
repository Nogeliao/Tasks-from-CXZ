# CMake 最低版本号要求
cmake_minimum_required (VERSION 2.8)

if(POLICY CMP0042)
  cmake_policy(SET CMP0042 NEW)  # CMake 3.0+ (2.8.12): MacOS "@rpath" in target's install name
endif()

# 项目工程名
project (SORT)
message(STATUS "root This is BINARY dir " ${PROJECT_BINARY_DIR})
message(STATUS "root This is SOURCE dir " ${PROJECT_SOURCE_DIR})

# 添加子目录
# ADD_SUBDIRECTORY(temp)
ADD_SUBDIRECTORY(src)


# #1.cmake verson，指定cmake版本 
# cmake_minimum_required(VERSION 3.5)
# #2.project name，指定项目的名称，一般和项目的文件夹名称对应
# PROJECT(SORT)

# #将可执行文件生成在bin文件夹中
# SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# #包含的头文件目录  
# INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)

# #指定源文件目录并赋值给DIR_SRCS变量
# AUX_SOURCE_DIRECTORY(${PROJECT_SOURCE_DIR}/src DIR_SRCS)


# MESSAGE(STATUS "开始构建")       
# #设置变量TEST_MATH 
# SET(SRC_PATH ${DIR_SRCS})
# #将TEST_MATH变量值作为地址，将地址下的文件编译成文件名为PROJECT_NAME变量值的可执行文件
# ADD_EXECUTABLE(${PROJECT_NAME} ${SRC_PATH})