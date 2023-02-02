#include <fstream>
#include <iostream>

int main()
{
    std::ofstream out("out.txt"); // Backup cout buffer and redirect to out.txt

    std::streambuf* currentStreamBuffer = std::cout.rdbuf();

    std::cout.rdbuf(out.rdbuf());
    std::cout << "This will be redirected to file out.txt" << std::endl;

    // Reset cout buffer
    std::cout.rdbuf(currentStreamBuffer);
    std::cout << "This will be printed on console" << std::endl;
}