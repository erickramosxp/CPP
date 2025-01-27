#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) {
    this->currentContact = 0;
    this->maxContacts = 8;
}

 void PhoneBook::introduction(void) {
	std::cout << "Welcome to PhoneBook" << std::endl;
    std::cout << "You can select some options" << std::endl;
 }

 void    PhoneBook::menu(void) {
	std::cout << "\n		MENU" << std::endl;
    std::cout << "ADD:      add and save new contact" << std::endl;
    std::cout << "SEARCH:   find a specific contact" << std::endl;
    std::cout << "EXIT:     quits and lost the contacts" << std::endl;
	std::cout << "\nPlease make your choise: ";
}

void    PhoneBook::addContact() {
	std::string input;
	Contact contact;

	contact.setFirstName();
	contact.setLastName();
	contact.setNickName();
	contact.setNumber();
	contact.setDarkestSecret();
	this->add(contact);
}

void    PhoneBook::add(Contact contact) {

    this->contact[this->currentContact % 8] = contact;
	this->currentContact++;
}

void    PhoneBook::setMaxContacts(int max) {
    this->maxContacts = max;
}

std::string PhoneBook::formmatStr(std::string str) {
    if (str.length() > 10) {
        return str.substr(0, 9) + ".";
    }
    return str;
}

void PhoneBook::listContacts(void) {
	int i = 0;

	std::cout << "\n     Index| FirstName|  LastName|  NickName|" << std::endl;
	while (i < this->currentContact && i < this->maxContacts)
	{
		std::cout << "-------------------------------------------" << std::endl;
		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << formmatStr(this->contact[i].getFirstName()) << "|";
		std::cout << std::setw(10) << formmatStr(this->contact[i].getLastName()) << "|";
		std::cout << std::setw(10) << formmatStr(this->contact[i].getNickName()) << "|" << std::endl;
		i++;
	}
	std::cout << std::endl;
}

void PhoneBook::selectContact(void) {

	int index;

	std::cout << "Enter the index: ";
	std::cin.clear();
	std::cin >> index;

	if (index > this->currentContact % 8) {
		std::cout << "Not valid index!";
		return ;
	}
	std::cout << "Name: " +  this->contact[index].getFirstName() << std::endl;
	std::cout << "Last Name: " +  this->contact[index].getLastName() << std::endl;
	std::cout << "Nickname : " +  this->contact[index].getNickName() << std::endl;
	std::cout << "Phone number : " +  this->contact[index].getNumber() << std::endl;
	std::cout << "DarkestSecret : " +  this->contact[index].getDarkestSecret() << std::endl;
	std::cin.clear();
}


int		PhoneBook::validOption(std::string option) {
	if (!option.compare("ADD") || !option.compare("SEARCH") || !option.compare("EXIT")) {
		return (1);
	}
	else {
		std::cout << "Please select valid option" << std::endl;
		return (0);
	}
}
/*
Contact PhoneBook::searchContact(std::string name){
}*/