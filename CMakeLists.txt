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
    )
endif()

set(THREAD_SAFE_QUEUE "thread_safe_queue")
file(GLOB_RECURSE THREAD_SAFE_QUEUE_SOURCES
    thread_safe_queue/*.cpp
)

set(WAIT_TIME_PERIOD "wait_time_period")
file(GLOB_RECURSE WAIT_TIME_PERIOD_SOURCES
    wait_time_period/*.cpp
)

set(MOVE_SEMANTICS "move_semantics")
file(GLOB_RECURSE MOVE_SEMANTICS_SOURCES
    move_semantics/*.cpp
)

set(COLOR_MODIFIER "color_modifier")
file(GLOB_RECURSE COLOR_MODIFIER_SOURCES
    color_modifier/*.cpp
)

set(IS_STL_CONTAINER "is_stl_container")
file(GLOB_RECURSE IS_STL_CONTAINER_SOURCES
    is_stl_container/*.cpp
)

set(TYPE_INDEX "type_index")
file(GLOB_RECURSE TYPE_INDEX_SOURCES
    type_index/*.cpp
)

# Set build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif(NOT CMAKE_BUILD_TYPE)

# Compiling target
add_executable(${THREAD_SAFE_QUEUE} ${THREAD_SAFE_QUEUE_SOURCES})
add_executable(${WAIT_TIME_PERIOD} ${WAIT_TIME_PERIOD_SOURCES})
add_executable(${MOVE_SEMANTICS} ${MOVE_SEMANTICS_SOURCES})
add_executable(${COLOR_MODIFIER} ${COLOR_MODIFIER_SOURCES})
add_executable(${IS_STL_CONTAINER} ${IS_STL_CONTAINER_SOURCES})
add_executable(${TYPE_INDEX} ${TYPE_INDEX_SOURCES})

if(UNIX)
    find_package(Threads)
    target_link_libraries(${THREAD_SAFE_QUEUE} ${CMAKE_THREAD_LIBS_INIT})
    target_link_libraries(${WAIT_TIME_PERIOD} ${CMAKE_THREAD_LIBS_INIT})
endif()

# Find boost
if(WIN32)
    find_package(Boost)
elseif(UNIX)
    # Boost components
    set(BOOST_COMPONENTS
        system
        filesystem
        date_time
        chrono
        serialization
    )
    find_package(Boost COMPONENTS ${BOOST_COMPONENTS} REQUIRED)
endif()

target_link_libraries(${TYPE_INDEX} ${Boost_LIBRARIES})
