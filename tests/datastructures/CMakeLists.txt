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

gtest_discover_tests(datastructures_tests
	TEST_PREFIX "Trees/BST/"
	TEST_FILTER "BinarySearchTreeTests.*"
	PROPERTIES LABELS "trees\;bst"
)

gtest_discover_tests(datastructures_tests
	TEST_PREFIX "Trees/RedBlack/"
	TEST_FILTER "RedBlackTreeTests.*"
	PROPERTIES LABELS "trees\;redblack"
)

gtest_discover_tests(datastructures_tests
	TEST_PREFIX "Trees/Splay/"
	TEST_FILTER "SplayTreeTests.*"
	PROPERTIES LABELS "trees\;splay"
)

gtest_discover_tests(datastructures_tests
	TEST_PREFIX "Trees/BTree/"
	TEST_FILTER "BTreeTests.*"
	PROPERTIES LABELS "trees\;btree"
)

gtest_discover_tests(datastructures_tests
	TEST_PREFIX "Trees/BPlusTree/"
	TEST_FILTER "BPlusTreeTests.*"
	PROPERTIES LABELS "trees\;bplustree"
)

gtest_discover_tests(datastructures_tests
	TEST_PREFIX "Tries/Trie/"
	TEST_FILTER "TrieTests.*"
	PROPERTIES LABELS "tries\;trie"
)

gtest_discover_tests(datastructures_tests
	TEST_PREFIX "Tries/RadixTree/"
	TEST_FILTER "RadixTreeTests.*"
	PROPERTIES LABELS "tries\;radix"
)

gtest_discover_tests(datastructures_tests
	TEST_PREFIX "Tries/TST/"
	TEST_FILTER "TernarySearchTreeTests.*"
	PROPERTIES LABELS "tries\;tst"
)

gtest_discover_tests(datastructures_tests
	TEST_PREFIX "Stacks/"
	TEST_FILTER "ArrayStackTests.*:LinkedListStackTests.*"
	PROPERTIES LABELS "stacks"
)

gtest_discover_tests(datastructures_tests
	TEST_PREFIX "Queues/"
	TEST_FILTER "ArrayQueueTests.*:LinkedListQueueTests.*"
	PROPERTIES LABELS "queues"
)

gtest_discover_tests(datastructures_tests
	TEST_PREFIX "Hashing/"
	TEST_FILTER "OpenHashTableTests.*:ClosedHashTableTests.*:ClosedHashTableBucketTests.*"
	PROPERTIES LABELS "hashing"
)

gtest_discover_tests(datastructures_tests
	TEST_PREFIX "Heaps/"
	TEST_FILTER "BinaryHeapTests.*:BinomialQueueTests.*:FibonacciHeapTests.*:LeftistHeapTests.*:SkewHeapTests.*"
	PROPERTIES LABELS "heaps"
)

gtest_discover_tests(datastructures_tests
	TEST_PREFIX "Graph/"
	TEST_FILTER "GraphTests.*"
	PROPERTIES LABELS "graph"
)

gtest_discover_tests(datastructures_tests
	TEST_PREFIX "DisjointSets/"
	TEST_FILTER "DisjointSetsTests.*"
	PROPERTIES LABELS "disjointsets"
)

# Any other datastructures tests (future files) will appear under this group.
gtest_discover_tests(datastructures_tests
	TEST_PREFIX "Datastructures/"
	TEST_FILTER "*-ForwardListTests.*:DoublyLinkedListTests.*:CircularLinkedListTests.*:AVLTreeTests.*:BinarySearchTreeTests.*:RedBlackTreeTests.*:SplayTreeTests.*:BTreeTests.*:BPlusTreeTests.*:TrieTests.*:RadixTreeTests.*:TernarySearchTreeTests.*:ArrayStackTests.*:LinkedListStackTests.*:ArrayQueueTests.*:LinkedListQueueTests.*:OpenHashTableTests.*:ClosedHashTableTests.*:ClosedHashTableBucketTests.*:BinaryHeapTests.*:BinomialQueueTests.*:FibonacciHeapTests.*:LeftistHeapTests.*:SkewHeapTests.*:GraphTests.*:DisjointSetsTests.*"
	PROPERTIES LABELS "datastructures"
)
