/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 15:01:12 by vvoronts          #+#    #+#             */
/*   Updated: 2025/09/01 20:36:05 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "main.h"
#include "PrettyPrint.h"

/**
 * Main function
 * @return 0 on success
 */
int main()
{
	std::string	command;
	PhoneBook	myBook;

	std::cout << HELLO << std::endl;
	std::cout << HELP << std::endl;
	while(true)
	{
		std::cout << PROMPT, std::cout << ENTER_COMMAND;
		std::getline(std::cin, command);
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
