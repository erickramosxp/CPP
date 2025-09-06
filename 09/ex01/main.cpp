#include "RPN.hpp"


int main(int argc, char** argv) {

    if (argc != 2) {
        std::cout << "Erro in input" << std::endl;
        return (1);
    }
    if (argv[1] == NULL)
        return 1;
    RPN polishNotation(argv[1]);
    return (0);
}