#pragma once

#include <stack>
#include <iostream>


class RPN {

    private:
        
        std::stack<int> inputNumbers;
        RPN();

    public:

        RPN(const std::string& input);
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);
        ~RPN();


};