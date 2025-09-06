#pragma once

#include <iostream>


class PmergeMe {

    private:

        PmergeMe();
    public:

        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();
};