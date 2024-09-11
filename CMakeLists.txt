cmake_minimum_required(VERSION 3.27.0)

project(fynBackup VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_VERBOSE_MAKEFILE ON)

include_directories(include)


file(
    GLOB_RECURSE
    SRCS
    src/*.cpp
)

file(
    GLOB_RECURSE 
    HEADERS 
    src/*.hpp
)

add_executable(${PROJECT_NAME} ${SRCS})

target_include_directories(${PROJECT_NAME} PRIVATE src)
target_sources(${PROJECT_NAME} PRIVATE FILE_SET HEADERS BASE_DIRS src FILES ${HEADERS})
