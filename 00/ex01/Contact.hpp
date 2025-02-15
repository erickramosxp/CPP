

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream> 

class Contact {
    public:
        Contact();
        Contact(std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber, std::string darkestSecret);
        void setFirstName(std::string input);
        void setLastName(std::string input);
        void setNumber(std::string input);
        void setNickName(std::string input);
        void setDarkestSecret(std::string input);
        std::string getNumber(void);
        std::string getFirstName(void);
        std::string getLastName(void);
        std::string getNickName(void);
        std::string getDarkestSecret(void);
        int handle_input_name(void);
        int handle_input_last_name(void);
        int handle_input_number(void);
        int handle_input_nickname(void);
        int handle_input_darkestsecret(void);

    private:
        std::string firstName;
        std::string lastName;
        std::string nickName;
        std::string phoneNumber;
        std::string darkestSecret;

};

#endif