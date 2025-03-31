/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erramos <erramos@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:07:55 by erramos           #+#    #+#             */
/*   Updated: 2025/02/24 19:08:00 by erramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <iomanip>
# include <limits>

# define EXIT 3
# define ENDFILE 2

class PhoneBook {
    public:
        PhoneBook(void);
        int	addContact();
        void	add(Contact contact);
        void	setMaxContacts(int max);
        void	listContacts(void);
        int selectContact(void);
        std::string	formmatStr(std::string str);
        void	print_contact(int index);
        int	validOption(std::string option);
        int option_chosen(std::string option);
        void	introduction(void);
        void	menu(void);

    private:
        int	maxContacts;
        int	currentContact;
        Contact	contact[8];
};


#endif
