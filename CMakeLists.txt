# Version CMake
cmake_minimum_required(VERSION 3.10)

# Project name
project(code_example)

# Options
set(CMAKE_CXX_STANDARD 17)

# Compiler-specific options
if((CMAKE_CXX_COMPILER_ID MATCHES "GNU") OR (CMAKE_CXX_COMPILER_ID MATCHES "Clang"))
    add_compile_options(
        -Werror

        -Wall
        -Wextra
        -Wpedantic

        -Wcast-align
        -Wcast-qual
        -Wenum-compare
        -Wfloat-equal
        -Wnon-virtual-dtor
        -Woverloaded-virtual
        -Wredundant-decls
        -Wsign-promo
    )
endif()

# Thread Safe Queue
set(THREAD_SAFE_QUEUE "thread_safe_queue")
file(GLOB_RECURSE THREAD_SAFE_QUEUE_SOURCES
    thread_safe_queue/*.cpp
    thread_safe_queue/*.hpp
)

# Wait Time Period
set(WAIT_TIME_PERIOD "wait_time_period")
file(GLOB_RECURSE WAIT_TIME_PERIOD_SOURCES
    wait_time_period/*.cpp
)

# Move Semantics
set(MOVE_SEMANTICS "move_semantics")
file(GLOB_RECURSE MOVE_SEMANTICS_SOURCES
    move_semantics/*.cpp
    move_semantics/*.hpp
)

# Set build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif(NOT CMAKE_BUILD_TYPE)

# Compiling target
add_executable(${THREAD_SAFE_QUEUE} ${THREAD_SAFE_QUEUE_SOURCES})
add_executable(${WAIT_TIME_PERIOD} ${WAIT_TIME_PERIOD_SOURCES})
add_executable(${MOVE_SEMANTICS} ${MOVE_SEMANTICS_SOURCES})

if(UNIX)
    find_package(Threads)
    target_link_libraries(${THREAD_SAFE_QUEUE} ${CMAKE_THREAD_LIBS_INIT})
    target_link_libraries(${WAIT_TIME_PERIOD} ${CMAKE_THREAD_LIBS_INIT})
endif()
