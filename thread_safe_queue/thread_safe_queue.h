#pragma once

#include <condition_variable>
#include <functional>
#include <mutex>
#include <queue>

template <typename T>
class threadsafe_queue {
public:
    threadsafe_queue() = default;
    threadsafe_queue& operator=(const threadsafe_queue&) = delete;

    threadsafe_queue(const threadsafe_queue& other)
    {
        std::lock_guard<std::mutex> lock(_mtx);
        _data_queue = other._data_queue;
    }

    void push(T value)
    {
        std::lock_guard<std::mutex> lock(_mtx);
        _data_queue.push(value);
        _cv.notify_one();
    }

    void wait_and_pop(T& value)
    {
        std::unique_lock<std::mutex> lock(_mtx);
        _cv.wait(lock, [this] { return !_data_queue.empty(); });
        value = _data_queue.front();
        _data_queue.pop();
    }

    std::shared_ptr<T> wait_and_pop()
    {
        std::unique_lock<std::mutex> lock(_mtx);
        _cv.wait(lock, [this] { return !_data_queue.empty(); });
        std::shared_ptr<T> res(std::make_shared<T>(_data_queue.front()));
        _data_queue.pop();
        return res;
    }

    bool try_pop(T& value)
    {
        std::lock_guard<std::mutex> lock(_mtx);
        if (_data_queue.empty()) {
            return false;
        }
        value = _data_queue.front();
        _data_queue.pop();
        return true;
    }

    std::shared_ptr<T> try_pop()
    {
        std::lock_guard<std::mutex> lock(_mtx);
        if (_data_queue.empty()) {
            return std::shared_ptr<T>();
        }
        std::shared_ptr<T> res(std::make_shared<T>(_data_queue.front()));
        _data_queue.pop();
        return res;
    }

    bool empty() const
    {
        std::lock_guard<std::mutex> lock(_mtx);
        return _data_queue.empty();
    }

    size_t size() const
    {
        std::lock_guard<std::mutex> lock(_mtx);
        return _data_queue.size();
    }

private:
    std::queue<T> _data_queue;
    mutable std::mutex _mtx;
    std::condition_variable _cv;
};
