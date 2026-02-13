# Data structures static library
file(GLOB_RECURSE DATA_SOURCES CONFIGURE_DEPENDS
    "*.hpp"
    "*.cpp"
)

add_library(heapnosisDatastructures STATIC)
target_sources(heapnosisDatastructures PRIVATE ${DATA_SOURCES})
target_include_directories(heapnosisDatastructures PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(heapnosisDatastructures PRIVATE heapnosisUtils)

heapnosis_apply_warnings(heapnosisDatastructures)
