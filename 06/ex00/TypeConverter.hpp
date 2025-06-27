#pragma once

#include <iostream>

class TypeConverter {

    private:

        bool isInt;
        bool isChar;
        bool isFloat;
        bool isDouble;
        bool charPossible;
        bool charDisplayable;
        bool intPossible;

        int intValue;
        char charValue;
        float floatValue;
        double doubleValue;

        std::string originalValue;

    public:

        TypeConverter();
        TypeConverter(std::string input, std::string typeValue);
        void setCharPossible(bool value);
        void setCharDisplayable(bool value);
        void setIntValue(int value);
        void setCharValue(char value);
        void setFloatValue(float value);
        void setDoubleValue(double value);
        void convertFromChar(char c);
        void convertFromInt(int i);
        void convertFromFloat(float f);
        void convertFromDouble(double d);
        void printValues();
};


/*

Entrada da string, já entra sabendo o que é, depois precisa fazer as verificações pra os outros tipos

*/