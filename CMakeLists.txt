cmake_minimum_required(VERSION 3.20)

project(AlgoForge LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(ALGOFORGE_ENABLE_WARNINGS "Enable strict warnings" ON)

add_subdirectory(src)

# Executabil principal care folose?te toate bibliotecile
add_executable(algoforge
    main.cpp
)
target_link_libraries(algoforge PRIVATE 
    algoforge_algorithms
    algoforge_datastructures
    algoforge_concurrency
    algoforge_playground
)

# Warnings pentru executabilul principal
if (ALGOFORGE_ENABLE_WARNINGS)
    if (MSVC)
        target_compile_options(algoforge PRIVATE /W4 /permissive-)
    else()
        target_compile_options(algoforge PRIVATE -Wall -Wextra -Wpedantic)
    endif()
endif()

enable_testing()
add_subdirectory(tests)
