#pragma once

#include <iostream>
#include <cctype>
#include <limits>
#include <cstdlib>
#include <climits>

class ScalarConverter {

    private:
        ScalarConverter();

    public:
        static void convert(std::string str);
};