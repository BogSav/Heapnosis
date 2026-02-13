#pragma once

#include <chrono>
#include <iostream>
#include <string>

namespace algoforge
{

class ScopedTimer
{
public:
	explicit ScopedTimer(const std::string& name, bool enabled = true)
		: _name(name),
		  _start(std::chrono::high_resolution_clock::now()),
		  _enabled(enabled)
	{
	}

	~ScopedTimer()
	{
		auto end = std::chrono::high_resolution_clock::now();
		auto duration =
			std::chrono::duration_cast<std::chrono::microseconds>(end - _start).count();
		if (_enabled)
		{
			std::cout << "[SCOPED TIMER] " << _name << " took " << duration << "us"
					  << std::endl;
		}
	}

private:
	std::string _name;
	std::chrono::high_resolution_clock::time_point _start;
	bool _enabled;
};

}  // namespace algoforge

#define SCOPED_TIMER(name, enabled) \
	algoforge::ScopedTimer timer_##__LINE__((name), (enabled))