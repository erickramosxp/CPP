#pragma once

#include <stack>
#include <iostream>


class RPN {

    private:
        
        std::stack<int> inputNumbers;
        RPN();

        enum e_operations {
            ADD = '+',
            SUB = '-',
            MUL = '*',
            DIV = '/'
        };

        typedef struct s_mapOperations {
            e_operations operation;
            int (*func)(int a,int b);
        } t_mapOperations;

        t_mapOperations listOperations[4];

        void inicializationListOfOperations();
        int handlerInput(const std::string& symbol);

    public:

        RPN(const std::string& input);
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);
        ~RPN();


};