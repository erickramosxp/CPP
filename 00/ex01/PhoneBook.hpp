

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
        int	addContact();
        void	add(Contact contact);
        void	setMaxContacts(int max);
        void	listContacts(void);
        int selectContact(void);
        std::string	formmatStr(std::string str);
        std::string	getInput(std::string text_input);
        void	print_contact(int index);
        int	validOption(std::string option);
        void	introduction(void);
        void	menu(void);

    private:
        int	maxContacts;
        int	currentContact;
        Contact	contact[8];
};


#endif