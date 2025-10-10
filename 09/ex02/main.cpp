#include "PmergeMe.hpp"

int main(int argc, char** argv) {

    PmergeMe merge;

    if (argc < 3) {
        std::cout << "Invalid argument!" << std::endl;
        return (1);
    }
    merge.initContainers(argv + 1);
    return (0);
}