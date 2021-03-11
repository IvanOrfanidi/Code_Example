#pragma once

template <class T>
class MemoryBlock {
public:
    MemoryBlock() = default;
    explicit MemoryBlock(size_t size)
        : _data(::new T[size])
        , _size(size)
    {
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
        std::copy(other._data, (other._data + other._size), _data);
    }

    // Copy assignment operator
    MemoryBlock& operator=(const MemoryBlock& other)
    {
        if (this != &other) {
            // Free the existing resource
            ::delete[] _data;

            _size = other._size;
            _data = new T[other._size];

            std::copy(other._data, (other._data + other._size), _data);
        }
        return *this;
    }

    // Move constructor
    MemoryBlock(MemoryBlock&& other)
    {
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
        _size = size;
    }
    size_t size() const
    {
        return _size;
    }

private:
    T* _data = nullptr;
    size_t _size = 0;
};
