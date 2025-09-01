/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DisplayContact.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 19:40:01 by vvoronts          #+#    #+#             */
/*   Updated: 2025/09/01 20:38:20 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "main.h"

/**
 * Display full details of chosen contact
 *
 * @retval bool - true if PhoneBook is empty
 */
bool PhoneBook::displayPhoneBook()
{
	bool isempty = true;

	std::vector<std::string> headers;
	headers.push_back("index");
	headers.push_back("first name");
	headers.push_back("last name");
	headers.push_back("nickname");

	std::cout << ROW << std::endl << "|";
	for (size_t i = 0; i < headers.size(); i++)
		align(headers[i], WIDTH);
	std::cout << std::endl << ROW << std::endl;
	if (getContactCount() == 0)
	{
		printEmptyBook();
		return isempty;
	}
	for (int i = 0; i < _contactCount; i++)
		printBook(_contacts, i);

	std::cout << ROW << std::endl;
	return not isempty;
}

/**
 * Display full details of chosen contact
 * @param contact - chosen contact
 *
 * @retval void
 */
void PhoneBook::displayContactDetails(Contact& contact)
{
	std::cout << std::endl << ROW << std::endl;
	std::cout << "               Contact Details       ";
	std::cout << std::endl << ROW;
	std::cout << std::endl;
	std::cout << "First Name:     " << contact.getFirstName() << std::endl;
	std::cout << "Last Name:      " << contact.getLastName() << std::endl;
	std::cout << "Nickname:       " << contact.getNickName() << std::endl;
	std::cout << "Phone Number:   " << contact.getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
	std::cout << ROW << std::endl;
}
