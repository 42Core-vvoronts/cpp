/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Printer.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 12:13:38 by vvoronts          #+#    #+#             */
/*   Updated: 2025/09/02 12:37:23 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Printer.hpp"
#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "main.h"
#include "PrettyPrint.h"

Printer::Printer() {}
Printer::~Printer() {}

/**
 * Display full details of chosen contact
 *
 * @retval bool - true if PhoneBook is empty
 */
bool Printer::displayPhoneBook(PhoneBook& phoneBook)
{
	bool isempty = true;

	printHeader();
	if (phoneBook.getContactCount() == 0)
	{
		printEmptyBook();
		return isempty;
	}
	printBook(phoneBook.getContactsArray(), phoneBook.getContactCount());
	std::cout << ROW << std::endl;
	return not isempty;
}

/**
 * Display full details of chosen contact
 * @param contact - chosen contact
 *
 * @retval void
 */
void Printer::displayContactDetails(Contact& contact)
{
	std::cout << "\nContact Details:\n";
	std::cout << std::endl;
	std::cout << NAME << contact.getFirstName() << std::endl;
	std::cout << LASTNAME << contact.getLastName() << std::endl;
	std::cout << NICKNAME << contact.getNickName() << std::endl;
	std::cout << PHONE << contact.getPhoneNumber() << std::endl;
	std::cout << SECRET << contact.getDarkestSecret() << std::endl;
	std::cout << std::endl;
}
