# Add subdirectories for each component (each defines a STATIC library)
add_subdirectory(utils)
add_subdirectory(algorithms)
add_subdirectory(datastructures)
add_subdirectory(concurrency)

# Set folder organization for IDE navigation
set_target_properties(heapnosisUtils PROPERTIES FOLDER "Sources")
set_target_properties(heapnosisAlgorithms PROPERTIES FOLDER "Sources")
set_target_properties(heapnosisDatastructures PROPERTIES FOLDER "Sources")
set_target_properties(heapnosisConcurrency PROPERTIES FOLDER "Sources")