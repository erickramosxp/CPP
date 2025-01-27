

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream> 

class Contact {
    public:
        Contact();
        Contact(std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber, std::string darkestSecret);
        void setFirstName();
        void setLastName();
        void setNumber();
        void setNickName();
        void setDarkestSecret();
        std::string getNumber();
        std::string getFirstName();
        std::string getLastName();
        std::string getNickName();
        std::string getDarkestSecret();

    private:
        std::string firstName;
        std::string lastName;
        std::string nickName;
        std::string phoneNumber;
        std::string darkestSecret;

};

#endif