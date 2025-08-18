/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 15:01:12 by vvoronts          #+#    #+#             */
/*   Updated: 2025/08/18 10:49:54 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "main.h"

void search()
{
	std::cout << "Searching for contacts..." << std::endl;
	// Implement search functionality here
}

void add()
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
    std::cout << SUCCESS << std::endl;
}

// ADD SEARCH EXIT 
int main()
{
	std::string command;

	std::cout << HELLO << std::endl;
	std::cout << HELP << std::endl;
	while(true)
	{
		std::cout << PROMPT, std::cout << ENTER_COMMAND;
		std::getline(std::cin, command);
		if (command == ADD)
			add();
		else if (command == SEARCH)
			std::cout << "search";
		else if (command == EXIT)
		{
			std::cout << BYE << std::endl;
			break;
		}
	}
}
