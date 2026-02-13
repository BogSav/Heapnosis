# Concurrency static library
file(GLOB_RECURSE CONC_SOURCES CONFIGURE_DEPENDS
    "*.hpp"
    "*.cpp"
)
add_library(heapnosisConcurrency STATIC)

target_sources(heapnosisConcurrency PRIVATE ${CONC_SOURCES})
target_include_directories(heapnosisConcurrency PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(heapnosisConcurrency PRIVATE heapnosisUtils)

heapnosis_apply_warnings(heapnosisConcurrency)
