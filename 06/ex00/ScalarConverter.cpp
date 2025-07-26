#include "ScalarConverter.hpp"
#include "TypeConverter.hpp"

static bool isChar(std::string str)
{

    if (str.length() == 1 && !isdigit(str[0]))
        return (true);

    return (false);
}

static bool isInt(std::string str)
{

    size_t i = 0;

    if (str[i] == '-' || str[i] == '+')
        i++;

    for (; i < str.length(); i++)
    {
        if (!isdigit(str[i]))
        {
            return (false);
        }
    }

    long long value = atol(str.c_str());

    if (value < std::numeric_limits<int>::min() 
        || value > std::numeric_limits<int>::max()) {
            return (false);
    }

    return (true);
}

static bool isFloat(std::string str)
{

    size_t i = 0;
    bool hasDot = false;

    if (str == "nanf" || str == "+inff" || str == "-inff" || str == "inff")
        return (true);

    if ((str[i] == '-' || str[i] == '+') && isdigit(str[i + 1]))
        i++;

    if (!(str.length() >= 2 && str[str.length() - 1] == 'f'))
        return (false);

    for (; i < str.length() - 1; i++)
    {

        if (!isdigit(str[i]))
        {
            if (str[i] == '.' && !hasDot && (isdigit(str[i + 1]) || str[i + 1] == 'f'))
            {
                hasDot = true;
                continue;
            }
            return (false);
        }
    }
    

    return (true);
}

static bool isDouble(std::string str)
{

    size_t i = 0;
    bool hasDot = false;


    if (str == "nan" || str == "+inf" || str == "-inf" || str == "inf")
        return (true);

    if (str.length() == 1 && str[0] == '.')
        return (false);

    if ((str[i] == '-' || str[i] == '+') && isdigit(str[i + 1]))
        i++;

    for (; i < str.length(); i++)
    {

        if (!isdigit(str[i]))
        {
            if (str[i] == '.' && !hasDot)
            {
                hasDot = true;
                continue;
            }
            return (false);
        }
    }
    return (true);
}

static void charVerification(unsigned char c, TypeConverter &converter)
{

    if (c > 127)
    {
        converter.setCharDisplayable(false);
        converter.setCharPossible(false);
    }
    else if (!isprint(c))
    {
        converter.setCharDisplayable(false);
        converter.setCharPossible(true);
    }
    else
    {
        converter.setCharDisplayable(true);
        converter.setCharPossible(true);
        converter.setCharValue(c);
    }
}

static void intVerification(std::string str, TypeConverter &converter)
{
    long intConvert = atol(str.c_str());

    if (intConvert < INT_MIN || intConvert > INT_MAX)
        converter.setIntPossible(false);
    else
    {
        converter.setIntPossible(true);
        converter.setIntValue(static_cast<int>(intConvert));
    }
}

static void floatVerification(std::string str, TypeConverter &converter)
{
    float floatValue;

    if (str == "nanf" || str == "+inff" || str == "-inff" || str == "inff") {
        converter.setFloatPseudoLiteral(true);
        return ;
    }
    floatValue = strtof(str.c_str(), NULL);
    converter.setFloatValue(floatValue);
}

static void doubleVerification(std::string str, TypeConverter &converter)
{
    double doubleValue;

    if (str == "nan" || str == "+inf" || str == "-inf" || str == "inf") {
        converter.setDoublePseudoLiteral(true);
        return ;
    }
    doubleValue = strtod(str.c_str(), NULL);
    converter.setDoubleValue(doubleValue);
}

void ScalarConverter::convert(std::string str)
{

    
    if (isChar(str))
    {
        TypeConverter converter(str);
        charVerification(str[0], converter);
        converter.convertFromChar(str[0]);
        converter.printValues();
    }
    else if (isInt(str))
    {
        TypeConverter converter(str);
        intVerification(str, converter);
        converter.convertFromInt(converter.getIntValue());
        converter.printValues();
    }
    else if (isFloat(str))
    {
        TypeConverter converter(str);
        floatVerification(str, converter);
        converter.convertFromFloat(converter.getFloatValue());
        converter.printValues();
    }
    else if (isDouble(str))
    {
        std::cout << "Foi se embora" << std::endl;
        TypeConverter converter(str);
        doubleVerification(str, converter);
        converter.convertFromDouble(converter.getDoubleValue());
        converter.printValues();
    } else {
        std::cout << "This is not a literal value" << std::endl;
    }
};