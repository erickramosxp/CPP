#pragma once

#include <iostream>
#include <climits>
#include <iomanip>
#include <stdlib.h>
#include <limits>

class TypeConverter {

    private:

        std::string originalValue;

        bool isChar;
        bool isInt;
        bool isFloat;
        bool isDouble;
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

    public:

        TypeConverter();
        TypeConverter(std::string input, std::string typeValue);
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
        void printValues();
};


/*

Entrada da string, já entra sabendo o que é, depois precisa fazer as verificações pra os outros tipos

*/