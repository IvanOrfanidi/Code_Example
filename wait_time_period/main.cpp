#include <chrono>
#include <condition_variable>
#include <cstdio>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

/* Рекомендуемый способ ожидания для условных переменных с ограничением по времени,
 если функции ожидания `wait` не передается никакого предиката.
 При этом ограничивается общая продолжительность цикла. Как показано
 применение цикла тогда, когда используются условные переменные
 и функции не передается предикат, обусловливается необходимостью обработки
 ложных пробуждений. Если в цикле воспользоваться функцией `wait_for()`, ожидание
 может продлиться почти все отведенное время, прежде чем произойдет ложное
 пробуждение, после чего при следующем прохождении цикла отсчет времени на­
 чнется заново. Это может повторяться произвольное количество раз, аннулируя все
 границы времени ожидания. */

int main()
{
    std::cout << "Start Waiting" << std::endl;
    std::size_t count = 0;

    bool done = false;
    std::condition_variable cv;
    std::mutex mtx;
    while (count < 10) {
        const auto timeout = std::chrono::steady_clock::now() + std::chrono::seconds(5);
        std::unique_lock<std::mutex> lock(mtx);
        while (!done) {
            if (cv.wait_until(lock, timeout) == std::cv_status::timeout) {
                break;
            }
        }
        count++;
        std::cout << "Counter: " << count << ". Time: " << std::time(nullptr) << "." << std::endl;

        // Имитация срабатывания done при делении count без остатка на 3
        if (!(count % 3)) {
            done = true;
        } else {
            done = false;
        }
    }

    return EXIT_SUCCESS;
}
