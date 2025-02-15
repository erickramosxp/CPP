#include "PhoneBook.hpp"

int main(void)
{
    PhoneBook book;
    std::string option;
    int stop;

    book.introduction();
    stop = 0;
    while (!stop)
    {
        if (std::cin.eof()) {
            break ;
        }
        while (option.empty())
        {
            book.menu();
            std::getline(std::cin, option);
            if (std::cin.eof()) {
                break ;
            }
            if (!option.compare("ADD")) {
                if (!book.addContact())
                    break ;
            } else if (!option.compare("SEARCH")) {
                book.listContacts();
                if (!book.selectContact())
                    return (1);
            } else if (!option.compare("EXIT")) {
                std::cout << "See you son" << std::endl;
                stop = 1;
                break ;
            } else {
                book.validOption(option);
            }
            option.clear();
        }
    }
    return (0);
}