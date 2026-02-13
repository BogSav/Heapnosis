#include "Concurrency.hpp"

#include "Benchmark.hpp"

#include <chrono>
#include <iostream>
#include <thread>
#include <vector>


namespace concurrency
{

void run_concurrency_demo()
{
	using namespace std::chrono_literals;

	std::cout << "Concurrency playground" << std::endl;

	algoforge::Benchmark::run(
		"spawn threads",
		[]()
		{
			std::vector<std::thread> threads;
			for (int i = 0; i < 4; ++i)
			{
				threads.emplace_back([] { std::this_thread::sleep_for(1ms); });
			}
			for (auto& t : threads)
			{
				t.join();
			}
		},
		10);
}

}  // namespace concurrency
