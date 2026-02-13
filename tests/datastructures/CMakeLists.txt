file(GLOB DATASTRUCTURES_TEST_SOURCES CONFIGURE_DEPENDS
	"${CMAKE_CURRENT_SOURCE_DIR}/*_tests.cpp"
)

add_executable(datastructures_tests
	${DATASTRUCTURES_TEST_SOURCES}
)

target_link_libraries(datastructures_tests
	PRIVATE
		GTest::gtest_main
		heapnosisUtils
		heapnosisAlgorithms
		heapnosisDatastructures
		heapnosisConcurrency
)
heapnosis_apply_warnings(datastructures_tests)

include(GoogleTest)

# Keep hierarchical grouping in VS Code Testing view even though everything is one executable.
gtest_discover_tests(datastructures_tests
	TEST_PREFIX "Lists/"
	TEST_FILTER "ForwardListTests.*:DoublyLinkedListTests.*:CircularLinkedListTests.*"
	PROPERTIES LABELS "lists"
)

gtest_discover_tests(datastructures_tests
	TEST_PREFIX "Trees/AVL/"
	TEST_FILTER "AVLTreeTests.*"
	PROPERTIES LABELS "trees\;avl"
)

# Any other datastructures tests (future files) will appear under this group.
gtest_discover_tests(datastructures_tests
	TEST_PREFIX "Datastructures/"
	TEST_FILTER "*-ForwardListTests.*:DoublyLinkedListTests.*:CircularLinkedListTests.*:AVLTreeTests.*"
	PROPERTIES LABELS "datastructures"
)
