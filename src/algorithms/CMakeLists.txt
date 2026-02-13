# Algorithms static library
file(GLOB_RECURSE ALGOFORGE_ALGORITHMS_SOURCES
    "*.hpp"
    "*.cpp"
)
add_library(algoforge_algorithms STATIC ${ALGOFORGE_ALGORITHMS_SOURCES})

target_include_directories(algoforge_algorithms PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
set_target_properties(algoforge_algorithms PROPERTIES CXX_STANDARD 20 CXX_STANDARD_REQUIRED YES)

target_link_libraries(algoforge_algorithms PUBLIC algoforge_utils)
