#pragma once


#include <cfloat>
#include <cmath>
#include <iostream>
#include <cctype>
#include <iomanip>
#include <climits>

class ScalarConverter {

    private:
        ScalarConverter();

    public:
        static void convert(std::string str);
};