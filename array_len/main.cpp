#include <array>
#include <cstddef>
#include <iostream>
#include <vector>

template <class T, size_t N>
constexpr size_t length(T (&)[N]) noexcept
{
    return N;
}

template <class T>
typename T::size_type length(T const& c) noexcept
{
    return c.size();
}

int main()
{
    uint8_t array[] = { 1, 2, 3 };
    std::cout << "Length for array = " << length(array) << std::endl;

    std::array<uint16_t, 5> stdArray = { 1, 2, 3, 4, 5 };
    std::cout << "Length for stdArray = " << length(stdArray) << std::endl;

    std::vector<uint32_t> stdVector = { 1, 2, 3, 4, 5, 6, 7 };
    std::cout << "Length for stdVector = " << length(stdVector) << std::endl;

    return EXIT_SUCCESS;
}