
#include "ScalarConverter.hpp"

int main(int argc, char **argv) {

    std::string str;

    if (argc != 2)
    {
        std::cout << "Invalid" << std::endl;
        return (1);
    }

    str = argv[1];
    double t = .100;
    // float a = .100f;
    ScalarConverter::convert(str);

    // std::cout << t * 3.5 << std::endl;
    std::cout << t << std::endl;

    return (0);
}