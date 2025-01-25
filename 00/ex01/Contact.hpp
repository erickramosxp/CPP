

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream> 

class Contact {
    public:
        Contact();
        Contact(std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber, std::string darkestSecret);
        std::string getName();
        std::string getNumber();

    private:
        std::string firstName;
        std::string lastName;
        std::string nickName;
        std::string phoneNumber;
        std::string darkestSecret;
};


#endif