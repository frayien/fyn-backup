cmake_minimum_required(VERSION 3.27.0)

project(fynBackup VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_VERBOSE_MAKEFILE ON)

include(FetchContent)

FetchContent_Declare(
  Boost
  URL https://github.com/boostorg/boost/releases/download/boost-1.86.0/boost-1.86.0-cmake.tar.gz
  URL_HASH SHA256=c62ce6e64d34414864fef946363db91cea89c1b90360eabed0515f0eda74c75c
  SYSTEM
)

FetchContent_MakeAvailable(Boost)

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
target_link_libraries(${PROJECT_NAME} PRIVATE Boost::program_options)
