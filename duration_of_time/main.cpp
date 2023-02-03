#include <algorithm>
#include <chrono>
#include <iostream>
#include <limits>
#include <random>
#include <vector>

template <typename T>
T generate_data(size_t size)
{
    static std::uniform_int_distribution<typename T::value_type> distribution(
        std::numeric_limits<typename T::value_type>::min(),
        std::numeric_limits<typename T::value_type>::max());
    static std::default_random_engine generator;

    T data(size);
    std::generate(data.begin(), data.end(), []() {
        return distribution(generator);
    });
    return data;
}

volatile int sink;
int main()
{
    const std::chrono::microseconds startMs = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch());
    const auto start = std::chrono::high_resolution_clock::now();

    // Generate and sort data
    std::vector<int> vec = generate_data<std::vector<int>>(1'000);
    std::sort(vec.begin(), vec.end());

    const std::chrono::microseconds endMs = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch());
    const auto end = std::chrono::high_resolution_clock::now();

    const auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    const auto durationMs = endMs - startMs;

    std::cout << "Time to fill and sort a vector of " << vec.size() << " ints : " << duration.count() << " us" << std::endl;
    std::cout << "Time to fill and sort a vector of " << vec.size() << " ints : " << durationMs.count() << " us" << std::endl;
}