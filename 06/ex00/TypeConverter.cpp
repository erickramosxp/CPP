

#include "TypeConverter.hpp"

TypeConverter::TypeConverter() {

};

TypeConverter::~TypeConverter() {
};

TypeConverter::TypeConverter(std::string input): 
    originalValue(input), charDisplayable(true), charPossible(true), intPossible(true), floatPseudoLiteral(false), doublePseudoLiteral(false) {

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

    this->floatValue = static_cast<float>(i);


    // Converter para double
    this->doubleValue = static_cast<double>(i);
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

int countPrecision(const std::string& input) {

    std::string::size_type pos = input.find('.');
    if (pos == std::string::npos)
        return 1; // Não tem ponto, usa 1 casa decimal por padrão
    int count = input.length() - pos - 1;
    if (input.find('f'))
        count--;
    return (count < 1) ? 1 : count;
}

void TypeConverter::printChar() {

    if (!this->charDisplayable) {
        std::cout << "char: Non displayable" << std::endl;
    } else if (!this->charPossible) {
        std::cout << "char: impossible" << std::endl;
    } else {
        std::cout << "char: '" << this->charValue << "'" << std::endl;
    }
};

void TypeConverter::printInt() {

    if (!this->intPossible) {
        std::cout << "int: impossible" << std::endl;
    } else {
        std::cout << "int: " << this->intValue << std::endl;
    }
};

void TypeConverter::printLiteral(Literal typeLiteral) {

    TypeConverter::PseudoLiteralMap map[4] = {
        { "nanf", "nan" },
        { "+inff", "+inf" },
        { "-inff", "-inf" },
        { "inff", "inf" }
    };

    std::string literalValue;
    std::string sufixValue;

    if (typeLiteral == DOUBLE_LITERAL) {
        sufixValue = "double: ";
    } else {
        sufixValue = "float: ";
    }

    for (int i = 0; i < 4; i++) {
        if (typeLiteral == DOUBLE_LITERAL)
            literalValue = map[i].doubleLiteral;
        else
            literalValue = map[i].floatLiteral;
        if (literalValue == originalValue) {
            std::cout << sufixValue << literalValue << std::endl;
            break ;
        }
    }
}

void TypeConverter::printFloat() {

    if (this->doublePseudoLiteral) {
        this->printLiteral(FLOAT_LITERAL);
    } else if (this->floatPseudoLiteral) {
        std::cout << "float: " << this->originalValue << std::endl;
    } else {
        std::cout << std::fixed << std::setprecision(countPrecision(this->originalValue));
        std::cout << "float: " << this->floatValue << "f" << std::endl;
    }
};

void TypeConverter::printDouble() {

     if (this->floatPseudoLiteral) {
        this->printLiteral(DOUBLE_LITERAL);
    } else if (this->doublePseudoLiteral) {
        std::cout << "double: " << this->originalValue << std::endl;
    } 
    else {
        std::cout << std::fixed << std::setprecision(countPrecision(this->originalValue));
        std::cout << "double: " << this->doubleValue << std::endl;
    }
};

void TypeConverter::printValues() {


    // Printar char
    printChar();
    // Printar int
    printInt();
    // Printar float
    printFloat();
    // Printar double
    printDouble();

};

