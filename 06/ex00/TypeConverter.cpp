

#include "TypeConverter.hpp"

TypeConverter::TypeConverter() {

};

TypeConverter::TypeConverter(std::string input, std::string typeValue): 
    originalValue(input), isChar(false), isInt(false), isFloat(false), isDouble(false), charDisplayable(true), charPossible(true), intPossible(true), floatPseudoLiteral(false), doublePseudoLiteral(false) {

    if (typeValue == "char")
        this->isChar = true;
    else if (typeValue == "int")
        this->isInt = true;
    else if (typeValue == "float")
        this->isFloat = true;
    else if (typeValue == "double")
        this->isDouble = true;

};

void TypeConverter::setCharPossible(bool value) {

    this->charPossible = value;
}

void TypeConverter::setCharDisplayable(bool value) {

    this->charDisplayable = value;
};


void TypeConverter::setIntValue(int value) {

    this->intValue = value;
};
void TypeConverter::setCharValue(char value) {

    this->charValue = value;
};
void TypeConverter::setFloatValue(float value) {

    this->floatValue = value;
};
void TypeConverter::setDoubleValue(double value) {

    this->doubleValue = value;
};

void TypeConverter::setIntPossible(bool value) {

    this->intPossible = value;
};

void TypeConverter::setFloatPseudoLiteral(bool value) {
    this->floatPseudoLiteral = value;
};

void TypeConverter::setDoublePseudoLiteral(bool value) {
    this->doublePseudoLiteral = value;
};

int TypeConverter::getIntValue() const {
    return this->intValue;
};
char TypeConverter::getCharValue() const {
    return this->charValue;
};
float TypeConverter::getFloatValue() const {
    return this->floatValue;
};
double TypeConverter::getDoubleValue() const {
    return this->doubleValue;
};

void TypeConverter::convertFromChar(char c) {

    // Converter para int

    this->intValue = static_cast<int>(c);

    // Converter para float

    this->floatValue = static_cast<float>(c);
    // Converter para double

    this->doubleValue = static_cast<double>(c);

};

void TypeConverter::convertFromInt(long i) {

    // Converter pra char
    if (!this->intPossible || (i < 0 || i > 127)) {
        this->charPossible = false;
    } else if (!isprint(i)) {
        this->charDisplayable = false;
    } else {
        this->charValue = static_cast<char>(i);
    }

    // Converter para float
    if (!this->intPossible){
        this->floatValue = strtof(this->originalValue.c_str(), NULL);
    } else {
        this->floatValue = static_cast<float>(i);
    }


    // Converter para double

    if (!this->intPossible){
        this->doubleValue = strtod(this->originalValue.c_str(), NULL);
    } else {
        this->doubleValue = static_cast<double>(i);
    }
};

void TypeConverter::convertFromFloat(float f) {

    // Converter para int

    if (this->floatPseudoLiteral || (f < INT_MIN || f > INT_MAX)) {
        this->intPossible = false;
    } else {
        this->intValue = static_cast<int>(f);
    }

    // Converter para char

    if (!this->intPossible || (f < 0 || f > 127)) {
        this->charPossible = false;
    } else if (!isprint(f)) {
        this->charDisplayable = false;
    } else {
        this->charValue = static_cast<char>(f);
    }

    // Converter para double
    if (this->floatPseudoLiteral) {
        this->doubleValue = 0;
    } else if (f == std::numeric_limits<float>::infinity() || f == -std::numeric_limits<float>::infinity()){
        this->doubleValue = strtod(this->originalValue.c_str(), NULL);
    } else {
        this->doubleValue = static_cast<double>(f);
    }
};

void TypeConverter::convertFromDouble(double d) {

    // Converter para int

    if (this->doublePseudoLiteral || (d < INT_MIN || d > INT_MAX)) {
        this->intPossible = false;
    } else {
        this->intValue = static_cast<int>(d);
    }

    // Converter para char

    if (!this->intPossible || (d < 0 || d > 127)) {
        this->charPossible = false;
    } else if (!isprint(d)) {
        this->charDisplayable = false;
    } else {
        this->charValue = static_cast<char>(d);
    }

    // Converter para float
    if (floatPseudoLiteral) {
        this->floatValue = 0;
    } else {
        this->floatValue = static_cast<float>(d);
    }
};

void TypeConverter::printValues() {


    // Printar char

    if (!this->charDisplayable) {
        std::cout << "char: Non displayable" << std::endl;
    } else if (!this->charPossible) {
        std::cout << "char: impossible" << std::endl;
    } else {
        std::cout << "char: '" << this->charValue << "'" << std::endl;
    }

    // Printar int
    if (!this->intPossible) {
        std::cout << "int: impossible" << std::endl;
    } else {
        std::cout << "int: " << this->intValue << std::endl;
    }
    
    // Printar float

    if (this->doublePseudoLiteral) {
        PseudoLiteralMap map[4] = {
            { "nanf", "nan" },
            { "+inff", "+inf" },
            { "-inff", "-inf" },
            { "inff", "inf" }
        };

        for (int i = 0; i < 4; i++) {
            if (map[i].doubleLiteral == originalValue) {
                std::cout << "float: " << map[i].floatLiteral << std::endl;
                break ;
            }
        }
    } else if (this->floatPseudoLiteral) {
        std::cout << "float: " << this->originalValue << std::endl;
    } else {
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << this->floatValue << "f" << std::endl;
    }

    // Printar double

    if (this->floatPseudoLiteral) {
        PseudoLiteralMap map[4] = {
            { "nanf", "nan" },
            { "+inff", "+inf" },
            { "-inff", "-inf" },
            { "inff", "inf" }
        };

        for (int i = 0; i < 4; i++) {
            if (map[i].floatLiteral == originalValue) {
                std::cout << "double: " << map[i].doubleLiteral << std::endl;
                break ;
            }
        }
    } else if (this->doublePseudoLiteral) {
        std::cout << "double: " << this->originalValue << std::endl;
    } 
    else {
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "double: " << this->doubleValue << std::endl;
    }

};

