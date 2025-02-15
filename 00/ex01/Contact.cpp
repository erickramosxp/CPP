#include "Contact.hpp"

Contact::Contact(){}

Contact::Contact(std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber, std::string darkestSecret)
{
    this->firstName = firstName;
    this->lastName = lastName;
    this->nickName = nickName;
    this->phoneNumber = phoneNumber;
    this->darkestSecret = darkestSecret;
}


void Contact::setFirstName(std::string input){
    this->firstName = input;
}

void Contact::setLastName(std::string input){
    this->lastName = input;
}

void Contact::setNumber(std::string input){
    this->phoneNumber = input;
}

void Contact::setNickName(std::string input){
    this->nickName = input;
};

void Contact::setDarkestSecret(std::string input){
    this->darkestSecret = input;
}

std::string Contact::getFirstName(){
    return this->firstName;
}

std::string Contact::getLastName(){
    return this->lastName;
}

std::string Contact::getNumber(){
    return this->phoneNumber;
}

std::string Contact::getNickName(){
    return this->nickName;
};

std::string Contact::getDarkestSecret(){
    return this->darkestSecret;
}


int Contact::handle_input_name() {
    
    std::string input;

    while (input.empty())
    {
        std::cout << "Enter your first name: ";
        std::getline(std::cin, input);
        if (std::cin.eof()) {
            return (0);
        }
        if (input.empty()) {
            std::cout << "The field cannot be coming out!" << std::endl;
        }
    }
    this->setFirstName(input);
    return (1);
}

int Contact::handle_input_last_name() {
    
    std::string input;

    while (input.empty())
    {
        std::cout << "Enter your last name: ";
        std::getline(std::cin, input);
        if (std::cin.eof()) {
            return (0);
        }
        if (input.empty()) {
            std::cout << "The field cannot be coming out!" << std::endl;
        }
    }
    this->setLastName(input);
    return (1);
}

int Contact::handle_input_number() {
        
    std::string input;

    while (input.empty())
    {
        std::cout << "Enter your Phone number: ";
        std::getline(std::cin, input);
        if (std::cin.eof()) {
            return (0);
        }
        if (input.empty()) {
            std::cout << "The field cannot be coming out!" << std::endl;
        }
    }
    this->setNumber(input);
    return (1);
}

int Contact::handle_input_nickname() {
        
    std::string input;

    while (input.empty())
    {
        std::cout << "Enter your Nickname: ";
        std::getline(std::cin, input);
        if (std::cin.eof()) {
            return (0);
        }
        if (input.empty()) {
            std::cout << "The field cannot be coming out!" << std::endl;
        }
    }
    this->setNickName(input);
    return (1);
}

int Contact::handle_input_darkestsecret() {

    std::string input;

    while (input.empty())
    {
        std::cout << "Enter your Darkest Secret: ";
        std::getline(std::cin, input);
        if (std::cin.eof()) {
            return (0);
        }
        if (input.empty()) {
            std::cout << "The field cannot be coming out!" << std::endl;
        }
    }
    this->setDarkestSecret(input);
    return (1);
}