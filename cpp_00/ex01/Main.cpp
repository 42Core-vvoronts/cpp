/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 15:01:12 by vvoronts          #+#    #+#             */
/*   Updated: 2025/11/18 22:33:39 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "PrettyPrint.h"

int main()
{
	std::string	command;
	PhoneBook	myBook;

	std::cout << HELLO << std::endl;
	std::cout << HELP << std::endl;
	while(true)
	{
		std::cout << PROMPT;
		std::cout << ENTER_COMMAND;
		if (!std::getline(std::cin, command))
		{
			// This block executes on EOF (Ctrl+D) or other stream error
			std::cout << std::endl << BYE << std::endl; // exit message
			break;
		}

		if (command == ADD)
			myBook.addContact();
		else if (command == SEARCH)
			myBook.searchContact();
		else if (command == EXIT)
		{
			std::cout << BYE << std::endl;
			break;
		}
	}
	return 0;
}
