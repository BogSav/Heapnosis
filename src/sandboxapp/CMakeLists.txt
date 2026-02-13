# Playground static library
file(GLOB_RECURSE SANDAPP_SOURCES
    "*.hpp"
    "*.cpp"
)
add_library(sandapp STATIC ${SANDAPP_SOURCES})

target_include_directories(sandapp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
set_target_properties(sandapp PROPERTIES CXX_STANDARD 20 CXX_STANDARD_REQUIRED YES)

target_link_libraries(sandapp PUBLIC algoforge_utils)
