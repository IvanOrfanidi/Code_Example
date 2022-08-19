#include <iostream>
#include <string>
#include <type_traits>

template <class T>
concept Integral = std::is_integral<T>::value;
template <class T>
concept FloatingPoint = std::is_floating_point<T>::value;
template <class T>
concept BasicString = std::basic_string<T>::value;

template <Integral T>
void swap(T& a, T& b)
{
    a ^= b;
    b ^= a;
    a ^= b;
}

template <FloatingPoint T>
void swap(T& a, T& b)
{
    T c = a;
    a = b;
    b = c;
}

template <BasicString T>
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
}