

#include "TypeConverter.hpp"

TypeConverter::TypeConverter() {

};

TypeConverter::TypeConverter(std::string input, std::string typeValue): 
    originalValue(input), isChar(false), isInt(false), isFloat(false), isDouble(false), charDisplayable(false), charPossible(false), intPossible(false) {

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

void TypeConverter::convertFromChar(char c) {

    // Converter para int

    this->intPossible = true;
    this->intValue = static_cast<int>(c);

    // Converter para float

    this->floatValue = static_cast<float>(c);
    // Converter para double

    this->doubleValue = static_cast<double>(c);

};

void TypeConverter::convertFromInt(int i) {

    // Converter pra char

    // Converter para float

    // Converter para double
};

void TypeConverter::convertFromFloat(float f) {

    // Converter para int

    // Converter para char

    // Converter para double
};

void TypeConverter::convertFromDouble(double d) {

    // Converter para int

    // Converter para char

    // Converter para float
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

    if (originalValue == "nanf") {

    } else if (originalValue == "+inff") {
        
    }

    // Printar double
};

