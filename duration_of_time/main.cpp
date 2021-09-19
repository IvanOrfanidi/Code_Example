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
    std::generate(data.begin(), data.end(), []() { return distribution(generator); });
    return data;
}

volatile int sink;
int main()
{
    const std::chrono::milliseconds start = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());

    std::vector<int> vec = generate_data<std::vector<int>>(100'000);
    std::sort(vec.begin(), vec.end());

    std::chrono::milliseconds end = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());

    const std::chrono::milliseconds diff = end - start;
    std::cout << "Time to fill and sort a vector of " << vec.size() << " ints : " << diff.count() << " ms\n";

    return EXIT_SUCCESS;
}