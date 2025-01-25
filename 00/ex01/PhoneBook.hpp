

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
# include <iostream> 


class PhoneBook {
    public:
        void addContact(Contact contact);
        void deleteContact(int index);
        Contact searchContact(std::string name);

    private:
        Contact contact[8];
};


#endif