# Utils static library
file(GLOB_RECURSE UTILS_SOURCES CONFIGURE_DEPENDS
    "*.hpp"
    "*.cpp"
)

add_library(heapnosisUtils STATIC)
target_sources(heapnosisUtils PRIVATE ${UTILS_SOURCES})
target_include_directories(heapnosisUtils PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

heapnosis_apply_warnings(heapnosisUtils)