# Data structures static library
file(GLOB_RECURSE ALGOFORGE_DATASTRUCTURES_SOURCES
    "*.hpp"
    "*.cpp"
)
add_library(algoforge_datastructures STATIC ${ALGOFORGE_DATASTRUCTURES_SOURCES})

target_include_directories(algoforge_datastructures PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
set_target_properties(algoforge_datastructures PROPERTIES CXX_STANDARD 20 CXX_STANDARD_REQUIRED YES)

target_link_libraries(algoforge_datastructures PUBLIC algoforge_utils)
