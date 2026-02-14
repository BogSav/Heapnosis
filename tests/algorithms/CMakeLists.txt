file(GLOB ALGORITHMS_TEST_SOURCES CONFIGURE_DEPENDS
	"${CMAKE_CURRENT_SOURCE_DIR}/*_tests.cpp"
)

add_executable(algorithms_tests
	${ALGORITHMS_TEST_SOURCES}
)

target_link_libraries(algorithms_tests
	PRIVATE
		GTest::gtest_main
		heapnosisUtils
		heapnosisAlgorithms
		heapnosisDatastructures
		heapnosisConcurrency
)
heapnosis_apply_warnings(algorithms_tests)

include(GoogleTest)

# Hierarchical grouping in VS Code Testing view.
gtest_discover_tests(algorithms_tests
	TEST_PREFIX "Algorithms/Recursion/"
	TEST_FILTER "RecursionTests.*"
	PROPERTIES LABELS "algorithms\;recursion"
)

gtest_discover_tests(algorithms_tests
	TEST_PREFIX "Algorithms/Search/"
	TEST_FILTER "SearchTests.*"
	PROPERTIES LABELS "algorithms\;search"
)

gtest_discover_tests(algorithms_tests
	TEST_PREFIX "Algorithms/Sorting/"
	TEST_FILTER "SortingTests.*"
	PROPERTIES LABELS "algorithms\;sorting"
)

gtest_discover_tests(algorithms_tests
	TEST_PREFIX "Algorithms/GraphAlgorithms/"
	TEST_FILTER "GraphAlgorithmTests.*"
	PROPERTIES LABELS "algorithms\;graph"
)

gtest_discover_tests(algorithms_tests
	TEST_PREFIX "Algorithms/DynamicProgramming/"
	TEST_FILTER "DynamicProgrammingTests.*"
	PROPERTIES LABELS "algorithms\;dp"
)

gtest_discover_tests(algorithms_tests
	TEST_PREFIX "Algorithms/Geometry/"
	TEST_FILTER "GeometryTests.*"
	PROPERTIES LABELS "algorithms\;geometry"
)

# Catch-all for any future algorithm tests.
gtest_discover_tests(algorithms_tests
	TEST_PREFIX "Algorithms/"
	TEST_FILTER "*-RecursionTests.*:SearchTests.*:SortingTests.*:GraphAlgorithmTests.*:DynamicProgrammingTests.*:GeometryTests.*"
	PROPERTIES LABELS "algorithms"
)
