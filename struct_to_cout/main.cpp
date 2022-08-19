#include <iostream>
#include <string>

#include "struct_to_cout.hpp"

struct Foo {
    int a = 0;
    unsigned b = 0;
    double c = 0;
    char d = '\0';
    bool e = false;
    std::string f{};
};

template <class Stream>
Stream& operator<<(Stream& stream, const Foo& foo)
{
    stream << to_tuple(foo);
    return stream;
}

int main()
{
    Foo foo;
    foo = {
        -100,
        12'345,
        3.14,
        '%',
        true,
        "hello",
    };
    std::cout << foo << std::endl;

    foo = {
        987,
        256,
        -1.23,
        'A',
        false,
        "world"
    };
    std::cout << foo << std::endl;
}