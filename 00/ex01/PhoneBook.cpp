/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erramos <erramos@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:07:34 by erramos           #+#    #+#             */
/*   Updated: 2025/02/24 19:07:36 by erramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

std::string PhoneBook::getInput(std::string text_input) {
    
	std::string input;
    
	std::cout << text_input;
    std::getline(std::cin, input);
    if (std::cin.eof()) {
        return "";
	}
    return (input);
}

int    PhoneBook::addContact() {

	std::string input;
	Contact contact;

	if (!contact.handle_input_name())
		return (0);
	if (!contact.handle_input_last_name())
		return (0);
	if (!contact.handle_input_number())
		return (0);
	if (!contact.handle_input_nickname())
		return (0);
	if (!contact.handle_input_darkestsecret())
		return (0);
	this->add(contact);
	return (1);
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

void	PhoneBook::print_contact(int index) {
	
	std::cout << "\nName: " +  this->contact[index].getFirstName() << std::endl;
	std::cout << "Last Name: " +  this->contact[index].getLastName() << std::endl;
	std::cout << "Nickname : " +  this->contact[index].getNickName() << std::endl;
	std::cout << "Phone number : " +  this->contact[index].getNumber() << std::endl;
	std::cout << "DarkestSecret : " +  this->contact[index].getDarkestSecret() << std::endl;
}

int PhoneBook::selectContact(void) {

	int index;
	std::string number;

	std::cout << "Enter the index: ";
	std::cin >> index;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.clear();
	if (index >= this->currentContact || index < 0) {
		std::cout << "Not valid index!";
		return (0);
	}
	print_contact(index);
	std::cin.clear();
	return (1);
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

int	PhoneBook::option_chosen(std::string option) {
	
	if (!option.compare("ADD")) {
        if (!this->addContact())
            return (2);
    } else if (!option.compare("SEARCH")) {
        this->listContacts();
    if (!this->selectContact())
            return (2);
    } else if (!option.compare("EXIT")) {
        std::cout << "See you son" << std::endl;
        return (3);
    } else {
        this->validOption(option);
    }
	return (0);
}
