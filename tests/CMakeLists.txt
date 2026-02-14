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

add_subdirectory(datastructures)
add_subdirectory(algorithms)