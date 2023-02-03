#include <any>
#include <iostream>
#include <optional>
#include <sstream>
#include <string>
#include <variant>

int main()
{
    // std::variant
    std::cout << "std::variant" << std::endl;
    std::variant<int, std::string> variant{};
    variant = 1;
    std::cout << "Value variant is '" << std::get<int>(variant) << '\'' << std::endl;

    variant = "one";
    if (std::get_if<int>(&variant) == nullptr) {
        std::cout << "The type variant is not integer." << std::endl;
    }
    if (std::get_if<std::string>(&variant) != nullptr) {
        std::cout << "The type variant is string." << std::endl;
    }
    std::cout << "Value variant is '" << std::get<std::string>(variant) << '\'' << std::endl;
    std::cout << std::endl;

    // std::any
    std::cout << "std::any" << std::endl;
    std::any any{};
    any = 2;
    std::cout << "Value any is '" << std::any_cast<int>(any) << '\'' << std::endl;

    any.reset();
    if (!any.has_value()) {
        std::cout << "No value any after reset." << std::endl;
    }

    any = std::string("two");
    if (any.type() != typeid(int)) {
        std::cout << "The type any is not integer." << std::endl;
    }
    if (any.type() == typeid(std::string)) {
        std::cout << "The type any is string." << std::endl;
    }
    std::cout << "Value any is '" << std::any_cast<std::string>(any) << '\'' << std::endl;
    std::cout << std::endl;

    // std::optional
    std::cout << "std::optional" << std::endl;
    std::optional<std::string> optional{}; // dafault 'std::nullopt'
    if (!optional.has_value()) {
        std::cout << "Value optional not set." << std::endl;
    }

    optional = "string data";
    std::cout << "Value any is '" << optional.value() << '\'' << std::endl;
    std::cout << "Value any is " << optional.value_or("no value") << std::endl;

    optional.reset();
    std::cout << "Value optional after reset is " << optional.value_or("'no value'") << std::endl;
}