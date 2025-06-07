#include "ScalarConverter.hpp"

static bool isChar(std::string c)
{

    if (c.length() == 1 && !isdigit(c[0]))
    {
        std::cout << "is char" << std::endl;
        return (true);
    }

    return (false);
}

static bool isInt(std::string c)
{

    size_t i = 0;

    if (c[i] == '-' || c[i] == '+')
        i++;

    for (; i < c.length(); i++)
    {
        if (!isdigit(c[i]))
        {
            return (false);
        }
    }

    std::cout << "is integer" << std::endl;
    return (true);
}

static bool isFloat(std::string c)
{

    size_t i = 0;
    bool hasDot = false;

    if ((c[i] == '-' || c[i] == '+') && isdigit(c[i + 1]))
        i++;

    if (!(c.length() >= 2 && c[c.length() - 1] == 'f'))
        return (false);

    for (; i < c.length() - 1; i++)
    {

        if (!isdigit(c[i]))
        {
            if (c[i] == '.' && !hasDot && (isdigit(c[i + 1]) || c[i + 1] == 'f'))
            {
                hasDot = true;
                continue;
            }
            return (false);
        }
    }

    std::cout << "is float" << c[c.length()] << std::endl;
    return (true);
}

static bool isDouble(std::string c)
{

    size_t i = 0;
    bool hasDot = false;

    if (c.length() == 1 && c[0] == '.')
        return (false);

    if ((c[i] == '-' || c[i] == '+') && isdigit(c[i + 1]))
        i++;

    for (; i < c.length(); i++)
    {

        if (!isdigit(c[i]))
        {
            if (c[i] == '.' && !hasDot)
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

static void charVerification(unsigned char c)
{

    if (!isprint(c)) {
        std::cout << "char: Non displayable" << std::endl;
    } else {
        std::cout << "char: " << static_cast<char>(c) << std::endl;
    }
}

static void intVerification(std::string c)
{
    long intConvert = atol(c.c_str);

    if (intConvert < INT_MIN || intConvert > INT_MAX)
    {
        std::cout << "int: impossible" << std::endl;
    }
    else
        std::cout << "int: " << static_cast<int>(intConvert); <<  << std::endl;
}

static void floatVerification(std::string c)
{
    if (c = "nanf")
    floating = strtof(c.c_str(), NULL);
}

void ScalarConverter::convert(std::string c)
{

    unsigned char cshar;
    int integer;
    float floating;
    double doubli;

    if (isChar(c))
    {
        charVerification(c[0]);
        // if (!isprint(cshar)) {
        //     std::cout << "não imprimivel" << std::endl;
        // }

        cshar = static_cast<char>(cshar);
        integer = static_cast<int>(cshar);
        floating = static_cast<float>(cshar);
        doubli = static_cast<double>(cshar);
    }
    if (isInt(c))
    {

        integer = atoi(c.c_str());

        if (!isprint(integer))
        {
            std::cout << "não imprimivel" << std::endl;
        }

        cshar = static_cast<char>(integer);
        floating = static_cast<float>(integer);
        doubli = static_cast<double>(integer);
    }
    if (isFloat(c))
    {

        floating = strtof(c.c_str(), NULL);

        cshar = static_cast<char>(floating);
        integer = static_cast<int>(floating);
        doubli = static_cast<double>(floating);
    };

    if (isDouble(c))
    {

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