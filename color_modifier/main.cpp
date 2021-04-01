#include <iostream>

#include "color_modifier.h"

int main()
{
    Color::Modifier red(Color::FG_RED);
    Color::Modifier green(Color::FG_GREEN);
    Color::Modifier yellow(Color::FG_YELLOW);
    Color::Modifier blue(Color::FG_BLUE);
    Color::Modifier magenta(Color::FG_MAGENTA);
    Color::Modifier cyan(Color::FG_CYAN);
    Color::Modifier white(Color::FG_WHITE);
    Color::Modifier def(Color::FG_DEFAULT);

    std::cout << red << "red" << def << std::endl;
    std::cout << green << "green" << def << std::endl;
    std::cout << yellow << "yellow" << def << std::endl;
    std::cout << blue << "blue" << def << std::endl;
    std::cout << magenta << "magenta" << def << std::endl;
    std::cout << cyan << "cyan" << def << std::endl;
    std::cout << white << "white" << def << std::endl;
}