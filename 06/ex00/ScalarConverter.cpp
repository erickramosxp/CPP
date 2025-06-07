# include "ScalarConverter.hpp"

static bool isChar(std::string c) {

    if (c.length() == 1 && !isdigit(c[0])) {
        std::cout << "is char" << std::endl;
        return (true);
    }

    return (false);
}

static bool isInt(std::string c) {

    size_t i = 0;

    if (c[i] == '-' || c[i] == '+')
        i++;
    
    for ( ; i < c.length(); i++) {
        if (!isdigit(c[i])) {
            return (false);
        }
    }

    std::cout << "is integer" << std::endl;
    return (true);
}

static bool isFloat(std::string c) {

    size_t i = 0;
    bool    hasDot = false;

    if ((c[i] == '-' || c[i] == '+') && isdigit(c[i + 1]))
        i++;

    if (!(c.length() >= 2 && c[c.length() - 1] == 'f'))
        return (false);
    
    for (; i < c.length() - 1; i++) {

        if (!isdigit(c[i])) {
            if (c[i] == '.' && !hasDot && (isdigit(c[i + 1]) || c[i + 1] == 'f')) {
                hasDot = true;
                continue ;
            }
            return (false);
        }
    }

    std::cout << "is float" << c[c.length()] << std::endl;
    return (true);
}

static bool isDouble(std::string c) {

    size_t i = 0;
    bool    hasDot = false;

    if (c.length() == 1 && c[0] == '.')
        return (false);

    if ((c[i] == '-' || c[i] == '+') && isdigit(c[i + 1]))
        i++;
    
    for (; i < c.length(); i++) {

         if (!isdigit(c[i])) {
            if (c[i] == '.' && !hasDot) {
                hasDot = true;
                continue ;
            }
            return (false);
        }
    }
    if (hasDot)
        std::cout << "is double" << std::endl;
    return (hasDot);
}

void ScalarConverter::convert(std::string c) {

    char cshar;
    int integer;
    float floating;
    double doubli;

    if (isChar(c)) {

        cshar = c[0];

        cshar = static_cast<char>(cshar);
        integer = static_cast<int>(cshar);
        floating = static_cast<float>(cshar);
        doubli = static_cast<double>(cshar);

    }
    isInt(c);
    if (isFloat(c)) {
        
        floating = strtof(c.c_str(), NULL);
        
        cshar = static_cast<char>(floating);
        integer = static_cast<int>(floating);
        doubli = static_cast<double>(floating);
    };
    isDouble(c);

    std::cout << "char: " << cshar << std::endl;
    std::cout << "int: " << integer << std::endl;
    std::cout << "float: " << floating << std::endl;
    std::cout << "double: " << doubli << std::endl;

};