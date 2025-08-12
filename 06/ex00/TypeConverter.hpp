#pragma once

#include <iostream>
#include <climits>
#include <iomanip>
#include <cctype>

class TypeConverter {

    private:

        std::string originalValue;

        bool charDisplayable;
        bool charPossible;
        bool intPossible;
        bool floatPseudoLiteral;
        bool doublePseudoLiteral;

        int intValue;
        char charValue;
        float floatValue;
        double doubleValue;

        struct PseudoLiteralMap {
            std::string floatLiteral;
            std::string doubleLiteral;
        };

        enum Literal {
            DOUBLE_LITERAL,
            FLOAT_LITERAL
        };

        TypeConverter(const TypeConverter&);
        TypeConverter& operator=(const TypeConverter&);

    public:

        TypeConverter();
        ~TypeConverter();
        TypeConverter(std::string input);
        void printLiteral(Literal typeLiteral);
        void setCharPossible(bool value);
        void setCharDisplayable(bool value);
        void setIntPossible(bool value);
        void setIntValue(int value);
        void setCharValue(char value);
        void setFloatValue(float value);
        void setDoubleValue(double value);
        void setFloatPseudoLiteral(bool value);
        void setDoublePseudoLiteral(bool value);
        int getIntValue() const;
        char getCharValue() const;
        float getFloatValue() const;
        double getDoubleValue() const;
        void convertFromChar(char c);
        void convertFromInt(long i);
        void convertFromFloat(float f);
        void convertFromDouble(double d);
        void printChar();
        void printInt();
        void printFloat();
        void printDouble();
        void printValues();
};


/*

Entrada da string, já entra sabendo o que é, depois precisa fazer as verificações pra os outros tipos

*/