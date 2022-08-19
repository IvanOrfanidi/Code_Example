
#include <chrono>
#include <iostream>
#include <iterator>
#include <list>
#include <thread>
#include <vector>

#include "thread_safe_queue.h"

void first(threadsafe_queue<std::vector<int>>& source)
{
    std::vector<int> data;

    std::cout << "wait data from second thread\n";
    source.wait_and_pop(data);

    for (const auto& i : data) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

void second(threadsafe_queue<std::vector<int>>& destination)
{
    const std::vector data{ 0, 1, 2, 3, 4 };

    std::cout << "send data to first thread\n";
    destination.push(data);
}

int main()
{
    threadsafe_queue<std::vector<int>> data; // Общая для процессов защищённая очередь.

    std::vector<std::thread> threads; // Вектор процессов.

    threads.emplace_back(first, std::ref(data));
    threads.emplace_back(second, std::ref(data));

    for (auto& thr : threads) {
        thr.join();
    }
}
