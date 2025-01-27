#include <iostream>
#include <string>

void upperCase(char *str)
{
    int i;
    std::string myStr = str;

    i = 0;
    while (i < (int) myStr.length())
    {
        myStr[i] = std::toupper(myStr[i]); 
        i++;
    }
    std::cout << myStr;
}

int main(int argc, char **argv)
{
    int i;

    i = 1;
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
        while (argv[i])
            upperCase(argv[i++]);
    std::cout << std::endl;
    return (0);
}