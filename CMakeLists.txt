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

set(SFINAE "sfinae")
file(GLOB_RECURSE SFINAE_SOURCES
    sfinae/*.cpp
)

set(ARRAY_LEN "array_len")
file(GLOB_RECURSE ARRAY_LEN_SOURCES
    array_len/*.cpp
)

set(DURATION_OF_TIME "duration_of_time")
file(GLOB_RECURSE DURATION_OF_TIME_SOURCES
    duration_of_time/*.cpp
)

# Compiling target
add_executable(${THREAD_SAFE_QUEUE} ${THREAD_SAFE_QUEUE_SOURCES})
add_executable(${WAIT_TIME_PERIOD} ${WAIT_TIME_PERIOD_SOURCES})
add_executable(${MOVE_SEMANTICS} ${MOVE_SEMANTICS_SOURCES})
add_executable(${COLOR_MODIFIER} ${COLOR_MODIFIER_SOURCES})
add_executable(${IS_STL_CONTAINER} ${IS_STL_CONTAINER_SOURCES})
add_executable(${TYPE_INDEX} ${TYPE_INDEX_SOURCES})
add_executable(${SFINAE} ${SFINAE_SOURCES})
add_executable(${ARRAY_LEN} ${ARRAY_LEN_SOURCES})
add_executable(${DURATION_OF_TIME} ${DURATION_OF_TIME_SOURCES})

if(UNIX)
    find_package(Threads)
    target_link_libraries(${THREAD_SAFE_QUEUE} ${CMAKE_THREAD_LIBS_INIT})
    target_link_libraries(${WAIT_TIME_PERIOD} ${CMAKE_THREAD_LIBS_INIT})
endif()

# Boost components
set(BOOST_COMPONENTS
    system
    filesystem
    date_time
    chrono
    serialization
)
# Find boost
find_package(Boost COMPONENTS ${BOOST_COMPONENTS} REQUIRED)

target_link_libraries(${TYPE_INDEX} ${Boost_LIBRARIES})
