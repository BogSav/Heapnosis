#include "datastructures.hpp"

#include "List.hpp"

#include "../utils/benchmark.hpp"

#include <iostream>
#include <vector>

namespace datastructures
{

void run_datastructures_demo()
{
	ForwardList<int> list;
	list.PushBack(10);
	list.PushBack(20);
}

}  // namespace datastructures
