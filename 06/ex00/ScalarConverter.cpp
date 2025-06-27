#include "ScalarConverter.hpp"
#include "TypeConverter.hpp"

static bool isChar(std::string str)
{

    if (str.length() == 1 && !isdigit(str[0]))
    {
        std::cout << "is char" << std::endl;
        return (true);
    }

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

    std::cout << "is integer" << std::endl;
    return (true);
}

static bool isFloat(std::string str)
{

    size_t i = 0;
    bool hasDot = false;

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

    std::cout << "is float" << str[str.length()] << std::endl;
    return (true);
}

static bool isDouble(std::string str)
{

    size_t i = 0;
    bool hasDot = false;

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
    if (hasDot)
        std::cout << "is double" << std::endl;
    return (hasDot);
}

static void charVerification(unsigned char c, TypeConverter &converter)
{

    if (c < 0 || c > 127)
    {
        converter.setCharDisplayable(false);
        converter.setCharPossible(false);
    }
    else if (!isprint(c)) {
        converter.setCharDisplayable(false);
        converter.setCharPossible(true);
    } else {
        converter.setCharDisplayable(true);
        converter.setCharPossible(true);
        converter.setCharValue(c);
    }
}

static void intVerification(std::string str)
{
    long intConvert = atol(str.c_str);

    if (intConvert < INT_MIN || intConvert > INT_MAX)
    {
        std::cout << "int: impossible" << std::endl;
    }
    else
        std::cout << "int: " << static_cast<int>(intConvert) << std::endl;
}

static void floatVerification(std::string str)
{
    float floating;

    if (str == "nanf")
    floating = strtof(str.c_str(), NULL);
}

static void doubleVerification(std::string str)
{
    float floating;

    if (str == "nanf")
    floating = strtof(str.c_str(), NULL);
}

void ScalarConverter::convert(std::string str)
{

    unsigned char cshar;
    int integer;
    float floating;
    double doubli;

    if (isChar(str))
    {
        TypeConverter converter(str, "char");
        charVerification(str[0], converter);
        converter.convertFromChar(str[0]);
        converter.printValues();
    }
    if (isInt(str))
    {
        TypeConverter converter(str, "int");

        integer = atoi(str.c_str());

        if (!isprint(integer))
        {
            std::cout << "não imprimivel" << std::endl;
        }

        cshar = static_cast<char>(integer);
        floating = static_cast<float>(integer);
        doubli = static_cast<double>(integer);
    }
    if (isFloat(str))
    {
        TypeConverter converter(str, "float");

        floating = strtof(str.c_str(), NULL);

        cshar = static_cast<char>(floating);
        integer = static_cast<int>(floating);
        doubli = static_cast<double>(floating);
    };

    if (isDouble(str))
    {
        TypeConverter converter(str, "double");
        doubli = DBL_MAX * 2.0;

        floating = static_cast<double>(doubli);
        cshar = static_cast<char>(doubli);
        integer = static_cast<int>(doubli);
    };

    std::cout << "char: " << cshar << std::endl;
    std::cout << "int: " << integer << std::endl;
    std::cout << "float: " << floating << std::endl;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "double: " << doubli << std::endl;
};