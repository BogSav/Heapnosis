#include "src/algorithms/algorithms.hpp"
#include "src/concurrency/concurrency.hpp"
#include "src/datastructures/datastructures.hpp"
#include "src/playground/playground.hpp"
#include "src/utils/ScopedTimer.hpp"

#include <iostream>

int main()
{
	bool enableTimers = true;
	{
		SCOPED_TIMER("Playground", enableTimers);
		playground::run_playground();
	}

	{
		SCOPED_TIMER("Datastructures", enableTimers);
		datastructures::run_datastructures_demo();
	}

	{
		SCOPED_TIMER("Algorithms", enableTimers);
		algorithms::run_algorithms_demo();
	}

	{
		SCOPED_TIMER("Concurrency", enableTimers);
		concurrency::run_concurrency_demo();
	}

	return 0;
}
