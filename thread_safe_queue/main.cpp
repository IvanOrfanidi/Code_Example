
#include <chrono>
#include <iostream>
#include <iterator>
#include <list>
#include <thread>
#include <vector>

#include "thread_safe_queue.h"

void first()
{
    std::cout << "From First Thread ID : " << std::this_thread::get_id() << "\n";
}

void second()
{
    std::cout << "From Second Thread ID : " << std::this_thread::get_id() << "\n";
}

int main()
{
    std::vector<std::thread> threads;
    threads.emplace_back(first);
    threads.emplace_back(second);

    for (auto& thr : threads) {
        thr.join();
    }

    return 0;
}
