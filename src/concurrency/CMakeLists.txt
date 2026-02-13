# Concurrency static library
file(GLOB_RECURSE ALGOFORGE_CONCURRENCY_SOURCES
    "*.hpp"
    "*.cpp"
)
add_library(algoforge_concurrency STATIC ${ALGOFORGE_CONCURRENCY_SOURCES})

target_include_directories(algoforge_concurrency PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
set_target_properties(algoforge_concurrency PROPERTIES CXX_STANDARD 20 CXX_STANDARD_REQUIRED YES)

target_link_libraries(algoforge_concurrency PUBLIC algoforge_utils)
