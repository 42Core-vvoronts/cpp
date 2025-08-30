/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 15:01:12 by vvoronts          #+#    #+#             */
/*   Updated: 2025/08/27 14:31:41 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "main.h"

void	print_contact(void)
{
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	std::cout << "|     index|first name| last name|  nickname|" << std::endl;
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	
	std::cout << "+----------+----------+----------+----------+" << std::endl;
}

/**
 * Search for an existing contact
 * @param
 * @return
 */
void search()
{
	std::cout << PROMPT, std::cout << SEARCHING << std::endl;
    std::getline(std::cin, index);
	showContact(index);
}

/**
 * Add a new contact
 * @param 
 */
void add(PhoneBook& phoneBook)
{
    std::string name, lastname, nickname, phone, secret;

	std::cout << ADDING << std::endl;
    std::cout << PROMPT, std::cout << NAME;
    std::getline(std::cin, name);
    std::cout << PROMPT, std::cout << LASTNAME;
    std::getline(std::cin, lastname);
    std::cout << PROMPT, std::cout << NICKNAME;
    std::getline(std::cin, nickname);
    std::cout << PROMPT, std::cout << PHONE;
    std::getline(std::cin, phone);
    std::cout << PROMPT, std::cout << SECRET;
    std::getline(std::cin, secret);
	// add contact
	phoneBook.addContact(name, lastname, nickname, phone, secret);
    std::cout << SUCCESS << std::endl;
}

/**
 * Main function
 * @return 0 on success
 */
int main()
{
	std::string command;
	PhoneBook phoneBook;
	
	

	std::cout << HELLO << std::endl;
	std::cout << HELP << std::endl;
	while(true)
	{
		std::cout << PROMPT, std::cout << ENTER_COMMAND;
		std::getline(std::cin, command);
		if (command == ADD)
			add(phoneBook);
		else if (command == SEARCH)
			search();
		else if (command == EXIT)
		{
			std::cout << BYE << std::endl;
			break;
		}
	}
	return 0;
}
