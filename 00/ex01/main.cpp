/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erramos <erramos@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:07:41 by erramos           #+#    #+#             */
/*   Updated: 2025/02/24 19:07:43 by erramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
    PhoneBook book;
    std::string option;
    int stop;

    book.introduction();
    stop = 0;
    while (stop != EXIT && stop != ENDFILE)
    {
        book.menu();
        std::getline(std::cin, option);
        if (std::cin.eof())
            break ;
        stop = book.option_chosen(option);
    }
    return (0);
}
