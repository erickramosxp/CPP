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
            if (std::cin.eof()) {
                break ;
            }
            book.menu();
            std::getline(std::cin, option);
            if (!option.compare("ADD")) {
                book.addContact();
            } else if (!option.compare("SEARCH")) {
                book.listContacts();
                book.selectContact();
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