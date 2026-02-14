file(GLOB_RECURSE ALGO_SOURCES CONFIGURE_DEPENDS
    "*.hpp"
    "*.cpp"
)

add_library(heapnosisAlgorithms STATIC)

target_sources(heapnosisAlgorithms PRIVATE ${ALGO_SOURCES})
target_include_directories(heapnosisAlgorithms PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(heapnosisAlgorithms PUBLIC heapnosisUtils heapnosisDatastructures)

heapnosis_apply_warnings(heapnosisAlgorithms)
