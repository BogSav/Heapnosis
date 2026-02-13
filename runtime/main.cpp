#include "SandApp.hpp"

#include "Algorithms.hpp"
#include "Concurrency.hpp"
#include "DataStructures.hpp"
#include "ScopedTimer.hpp"

int main()
{
	bool enableTimers = true;

	{
		SCOPED_TIMER("Sandbox", enableTimers);
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
