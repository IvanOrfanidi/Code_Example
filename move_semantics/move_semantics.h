#pragma once

#include <cstring>

template <class T>
class MemoryBlock {
public:
    MemoryBlock() = default;
    explicit MemoryBlock(size_t size)
        : _data(::new T[size])
        , _size(size)
    {
        if (_data == nullptr) {
            throw std::runtime_error("insufficient memory");
        }
    }

    ~MemoryBlock()
    {
        ::delete[] _data;
        _data = nullptr;
        _size = 0;
    }

    // Copy constructor
    MemoryBlock(const MemoryBlock& other)
        : _data(::new T[other._size])
        , _size(other._size)
    {
        std::cout << "Copy constructor" << std::endl;

        if (_data == nullptr) {
            throw std::runtime_error("insufficient memory");
        }

        std::copy(other._data, (other._data + other._size), _data);
    }

    // Copy assignment operator
    MemoryBlock& operator=(const MemoryBlock& other)
    {
        std::cout << "Copy assignment operator" << std::endl;

        if (this != &other) {
            // Free the existing resource
            ::delete[] _data;

            _size = other._size;
            _data = new T[other._size];
            if (_data == nullptr) {
                throw std::runtime_error("insufficient memory");
            }

            std::copy(other._data, (other._data + other._size), _data);
        }
        return *this;
    }

    // Move constructor
    MemoryBlock(MemoryBlock&& other)
    {
        std::cout << "Move constructor" << std::endl;

        // Copy the data pointer and its length from the
        // source object.
        _data = other._data;
        _size = other._size;

        // Release the data pointer from the source object so that
        // the destructor does not free the memory multiple times
        other._data = nullptr;
        other._size = 0;

        // Or
        //*this = std::move(other);
    }

    // Move assignment operator
    MemoryBlock& operator=(MemoryBlock&& other)
    {
        std::cout << "Move assignment operator" << std::endl;

        if (this != &other) {
            // Free the existing resource
            ::delete[] _data;

            // Copy the data pointer and its length from the
            // source object
            _data = other._data;
            _size = other._size;

            // Release the data pointer from the source object so that
            // the destructor does not free the memory multiple times
            other._data = nullptr;
            other._size = 0;

            // Or
            //*this = std::move(other);
        }
        return *this;
    }

    void resize(size_t size)
    {
        if (size != _size) {
            T* data = ::new T[size];
            if (_data == nullptr) {
                throw std::runtime_error("insufficient memory");
            }

            std::memset(data, 0, size * sizeof(T));
            std::memcpy(data, _data, (((_size < size) ? _size : size) * sizeof(T)));

            ::delete[] _data;
            _data = data;
            _size = size;
        }
    }

    size_t size() const noexcept
    {
        return _size;
    }

    T& operator[](const size_t index)
    {
        if (index >= _size) {
            throw std::runtime_error("error index out of range");
        }
        return _data[index];
    }

    const T& operator[](const size_t index) const
    {
        if (index >= _size) {
            throw std::runtime_error("error index out of range");
        }
        return _data[index];
    }

    template <class Stream>
    friend Stream& operator<<(Stream& stream, const MemoryBlock& memoryBlock)
    {
        stream << "[ ";
        for (size_t i = 0; i < memoryBlock._size; ++i) {
            stream << memoryBlock._data[i] << " ";
        }
        stream << ']';
        return stream;
    }

private:
    T* _data = nullptr;
    size_t _size = 0;
};
