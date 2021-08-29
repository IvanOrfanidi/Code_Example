#include <iostream>
#include <vector>

#include "type_index.h"

int main()
{
    // For std::vector
    const std::vector<int> vec = { 1, 2, 3 };
    std::cout << "For std::vector<int>:" << '\n'
              << "    T = " << getType(vec) << '\n'
              << "    param = " << getParamType(vec) << '\n'
              << "    T = " << getType(*vec.begin()) << '\n'
              << "    param = " << getParamType(*vec.begin()) << '\n'
              << std::endl;

    // For std::initializer_list
    const auto initializerList = { 1, 2, 3 };
    std::cout << "For std::initializer_list<int>:" << '\n'
              << "    T = " << getType(initializerList) << '\n'
              << "    param = " << getParamType(initializerList) << '\n'
              << "    T = " << getType(*initializerList.begin()) << '\n'
              << "    param = " << getParamType(*initializerList.begin()) << '\n'
              << std::endl;

    return EXIT_SUCCESS;
}