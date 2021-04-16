#include <iostream>
#include <vector>

#include "type_index.h"

int main()
{
    std::vector<int> vec = { 1, 2, 3 };

    const auto& i = vec[0];

    std::cout << "T = " << getType(i) << '\n'
              << "param = " << getParamType(i) << '\n'
              << std::endl;
    std::cout << "T = " << getType(vec[0]) << '\n'
              << "param = " << getParamType(vec[0]) << '\n'
              << std::endl;

    return EXIT_SUCCESS;
}