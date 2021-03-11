#include <chrono>
#include <condition_variable>
#include <cstdio>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

/* Waiting for a conditional variable with a specified time period */
int main()
{
    std::cout << "Start Waiting" << std::endl;
    std::size_t count = 0;

    bool done = false;
    std::condition_variable cv;
    std::mutex mtx;
    while (true) {
        auto const timeout = std::chrono::steady_clock::now() + std::chrono::milliseconds(1000);
        std::unique_lock<std::mutex> lock(mtx);
        while (!done) {
            if (cv.wait_until(lock, timeout) == std::cv_status::timeout) {
                break;
            }
        }
        count++;
        std::cout << "Counter: " << count << std::endl;

        // Имитация срабатывания done при делении count без остатка на 3
        if (!(count % 3)) {
            done = true;
        } else {
            done = false;
        }
    }

    return 0;
}
