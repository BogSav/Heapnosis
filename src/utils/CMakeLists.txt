# Utils static library
file(GLOB_RECURSE ALGOFORGE_UTILS_SOURCES
    "*.hpp"
)

# If a ScopedTimer.cpp exists, add it
if (EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/ScopedTimer.cpp")
    list(APPEND ALGOFORGE_UTILS_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/ScopedTimer.cpp")
endif()

# Also include other cpp files if present
file(GLOB_RECURSE UTILS_CPP_FILES "*.cpp")
foreach(f IN LISTS UTILS_CPP_FILES)
    if (NOT f STREQUAL "${CMAKE_CURRENT_SOURCE_DIR}/ScopedTimer.cpp")
        list(APPEND ALGOFORGE_UTILS_SOURCES ${f})
    endif()
endforeach()

add_library(algoforge_utils STATIC ${ALGOFORGE_UTILS_SOURCES})

target_include_directories(algoforge_utils PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
set_target_properties(algoforge_utils PROPERTIES CXX_STANDARD 20 CXX_STANDARD_REQUIRED YES)
