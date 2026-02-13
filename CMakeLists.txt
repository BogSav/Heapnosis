cmake_minimum_required(VERSION 3.20)

project(Heapnosis LANGUAGES CXX)

option(HEAPNOSIS_ENABLE_WARNINGS "Enable strict warnings" ON)

function(heapnosis_apply_warnings target)
    if (NOT HEAPNOSIS_ENABLE_WARNINGS)
        return()
    endif()

    if (MSVC)
        target_compile_options(${target} PRIVATE /W4 /permissive-)
    else()
        target_compile_options(${target} PRIVATE -Wall -Wextra -Wpedantic)
    endif()
endfunction()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable folder organization for IDEs
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

add_subdirectory(sources)
add_subdirectory(runtime)

enable_testing()
add_subdirectory(tests)
