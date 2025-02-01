

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream> 
# include <iomanip>
#include <limits>
# include <string>


class PhoneBook {
    public:
        PhoneBook(void);
        void addContact();
        void add(Contact contact);
        void setMaxContacts(int max);
        void listContacts(void);
        void selectContact(void);
        std::string formmatStr(std::string str);
        int validOption(std::string option);
        void introduction(void);
        void menu(void);

    private:
        int maxContacts;
        int currentContact;
        Contact contact[8];
};


#endif