#include "Algorithms.hpp"

#include "Benchmark.hpp"

#include <algorithm>
#include <iostream>
#include <vector>

namespace algorithms
{

void run_algorithms_demo()
{
	std::cout << "Algorithms playground" << std::endl;

	std::vector<int> v{5, 1, 4, 2, 3};

	algoforge::Benchmark::run(
		"std::sort",
		[&]()
		{
			auto copy = v;
			std::sort(copy.begin(), copy.end());
		},
		1000);
}

}  // namespace algorithms
