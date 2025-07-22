
#include "ScalarConverter.hpp"

int main(int argc, char **argv) {

    std::string str;

    if (argc != 2)
    {
        std::cout << "Invalid usage of ./convert" << std::endl;
        return (1);
    }

    str = argv[1];
    ScalarConverter::convert(str);

    return (0);
}