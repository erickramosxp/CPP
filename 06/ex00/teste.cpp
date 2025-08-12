#include <iostream>
#include <cstdlib>
#include <cctype>
#include <string>
#include <iomanip>

bool isChar(const std::string &s) {
    return (s.length() == 1 && !isdigit(s[0]));
}

bool isInt(const std::string &s) {
    if (s.empty()) return false;
    size_t i = 0;
    if (s[0] == '-' || s[0] == '+') i = 1;
    for (; i < s.length(); ++i) {
        if (!isdigit(s[i])) return false;
    }
    return true;
}

bool isFloatOrDouble(const std::string &s) {
    bool hasDecimal = false;
    if (s.empty()) return false;
    size_t i = 0;
    if (s[0] == '-' || s[0] == '+') i = 1;
    for (; i < s.length(); ++i) {
        if (s[i] == '.') {
            if (hasDecimal) return false;
            hasDecimal = true;
        } else if (!isdigit(s[i])) {
            return false;
        }
    }
    return hasDecimal;
}

void printChar(char c, long nb) {


    if (nb < 0 || nb > 127) {
        std::cout << "-> char: impossible" << std::endl;
    } else if (!isprint(c)) {
        std::cout << "-> char: Non displayable" << std::endl;
    } else {
        std::cout << "-> char: '" << c << "'" << std::endl;
    }
};

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Uso: " << argv[0] << " <valor>" << std::endl;
        return 1;
    }

    std::string input = argv[1];

    std::cout << std::endl;
    std::cout << "--- Testing implict conversion ---" << std::endl;

    std::cout << std::fixed << std::setprecision(7);
    if (isChar(input)) {
        char c = input[0]; // char original
        int i = c;        // conversão implícita char -> int
        float f = c;       // conversão implícita char -> float
        double d = c;      // conversão implícita char -> double

        std::cout << "Tipo original: char ('" << c << "')" << std::endl;
        std::cout << "-> int: " << i << std::endl;
        std::cout << "-> float: " << f << "f" << std::endl;
        std::cout << "-> double: " << d << std::endl;
    }
    else if (isInt(input)) {
        int i = atoi(input.c_str()); // int original
        char c = i;                  // conversão implícita int -> char
        float f = i;                  // conversão implícita int -> float
        double d = i;                 // conversão implícita int -> double

        std::cout << "Tipo original: int (" << i << ")" << std::endl;
        printChar(c, i);
        std::cout << "-> float: " << f << "f" << std::endl;
        std::cout << "-> double: " << d << std::endl;
    }
    else if (isFloatOrDouble(input)) {
        double d = atof(input.c_str()); // double original
        char c = d;                     // conversão implícita double -> char (trunca)
        int i = d;                      // conversão implícita double -> int (trunca)
        float f = d;                    // conversão implícita double -> float

        std::cout << "Tipo original: double (" << d << ")" << std::endl;
        printChar(c, d);
        std::cout << "-> int: " << i << std::endl;
        std::cout << "-> float: " << f << "f" << std::endl;
    }
    else {
        std::cerr << "Formato inválido! Use char, int, float ou double." << std::endl;
        return 1;
    }

    return 0;
}