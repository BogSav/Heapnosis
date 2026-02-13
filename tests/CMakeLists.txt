include(FetchContent)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
FetchContent_MakeAvailable(googletest)

foreach(gtest_target gtest gtest_main gmock gmock_main)
    if (TARGET ${gtest_target})
        set_target_properties(${gtest_target} PROPERTIES FOLDER "External/Gtests")
    endif()
endforeach()

add_executable(sample_tests
    sample_tests.cpp
	list_tests.cpp
)

target_link_libraries(sample_tests
    PRIVATE
        GTest::gtest_main
        heapnosisUtils
        heapnosisAlgorithms
        heapnosisDatastructures
        heapnosisConcurrency
)
heapnosis_apply_warnings(sample_tests)

include(GoogleTest)
gtest_discover_tests(sample_tests)
