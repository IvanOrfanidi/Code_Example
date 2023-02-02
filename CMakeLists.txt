# Version CMake
cmake_minimum_required(VERSION 3.10)

# Project name
project(code_example)

# Options
set(CMAKE_CXX_STANDARD 20)

# Compiler-specific options
add_compile_options(
    -Werror
    -Wall
    -Wextra
    -Wpedantic
)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    add_compile_options(
        -fconcepts
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

set(CONCEPT "concept")
file(GLOB_RECURSE CONCEPT_SOURCES
    concept/*.cpp
)

set(STRUCT_TO_COUT "struct_to_cout")
file(GLOB_RECURSE STRUCT_TO_COUT_SOURCES
    struct_to_cout/*.cpp
)

set(CAST "cast")
file(GLOB_RECURSE CAST_SOURCES
    cast/*.cpp
)

set(REDIRECT_COUT_TO_FILE "redirect_cout_to_file")
file(GLOB_RECURSE REDIRECT_COUT_TO_FILE_SOURCES
    redirect_cout_to_file/*.cpp
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
add_executable(${CONCEPT} ${CONCEPT_SOURCES})
add_executable(${STRUCT_TO_COUT} ${STRUCT_TO_COUT_SOURCES})
add_executable(${CAST} ${CAST_SOURCES})
add_executable(${REDIRECT_COUT_TO_FILE} ${REDIRECT_COUT_TO_FILE_SOURCES})

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
