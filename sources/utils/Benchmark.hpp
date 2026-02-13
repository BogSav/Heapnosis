#pragma once

#include <chrono>
#include <functional>
#include <iostream>
#include <string>

namespace algoforge {

class Benchmark {
public:
    template <typename F>
    static void run(const std::string& name, F&& func, std::size_t iterations = 1) {
        using namespace std::chrono;
        auto start = high_resolution_clock::now();
        for (std::size_t i = 0; i < iterations; ++i) {
            func();
        }
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start).count();
        std::cout << "[BENCH] " << name << " took " << duration << "us for "
                  << iterations << " iterations" << std::endl;
    }
};

} // namespace algoforge
