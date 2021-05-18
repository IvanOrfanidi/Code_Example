#include <iostream>
#include <string>
#include <type_traits>

// Before C++14.
template <typename T, typename std::enable_if<std::is_integral<T>::value, bool>::type = true>
void swap(T& a, T& b)
{
    a ^= b;
    b ^= a;
    a ^= b;
}

// In C++14 and higher.
template <typename T, std::enable_if_t<std::is_floating_point<T>::value, bool> = true>
void swap(T& a, T& b)
{
    T c = a;
    a = b;
    b = c;
}

template <typename T, std::enable_if_t<std::basic_string<T>::value, bool> = true>
void swap(T& a, T& b)
{
    a.swap(b);
}

int main()
{
    // Integral values.
    {
        int a = 1;
        int b = 2;

        swap(a, b);
        std::cout << "This is integral values: a = " << a << ", b = " << b << "." << std::endl;
    }

    // Floating point values.
    {
        double a = 1.1;
        double b = 2.2;

        swap(a, b);
        std::cout << "This is floating point values: a = " << a << ", b = " << b << "." << std::endl;
    }

    // String values.
    {
        std::string a = "A";
        std::string b = "B";

        swap(a, b);
        std::cout << "This is string values: a = `" << a << "`, b = `" << b << "`." << std::endl;
    }

    return EXIT_SUCCESS;
}