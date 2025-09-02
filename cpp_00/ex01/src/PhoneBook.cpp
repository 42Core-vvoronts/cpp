/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 15:02:39 by vvoronts          #+#    #+#             */
/*   Updated: 2025/09/02 12:35:17 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "Printer.hpp"
#include "PrettyPrint.h"
#include "main.h"

PhoneBook::PhoneBook()
{
	_contactIndex = 0;
	_contactCount = 0;
	// std::cout << "A PhoneBook has been constructed." << std::endl;
}

PhoneBook::~PhoneBook()
{
	// std::cout << "A PhoneBook has been destructed." << std::endl;
}

// Getters
int	PhoneBook::getContactCount(void)
{
	return this->_contactCount;
}

int	PhoneBook::getContactIndex(void)
{
	return this->_contactIndex;
}

int	PhoneBook::getMaxContacts(void)
{
	return this->_maxContacts;
}

Contact* PhoneBook::getContactsArray(void)
{
	return this->_contacts;
}

// Setters
void PhoneBook::setContactCount(int count)
{
	this->_contactCount = count;
}

void PhoneBook::setContactIndex(int index)
{
	this->_contactIndex = index;
}

void PhoneBook::setContact(Contact& contact, int index)
{
	_contacts[index] = contact;
}

/**
 * Search existing contact in PhoneBook
 *
 * @retval void
 * Display whole PhoneBook and prompt user to enter index of chosen contact
 * to view full details or exit if PhoneBook is empty
 */
void PhoneBook::searchContact(void)
{
	int	index = 0;
	bool isempty;
	Printer printer;

	isempty = printer.displayPhoneBook(*this);
	if (isempty)
		return ;
	
	while (index < 1 || index > _contactCount)
	{
		std::cout << PROMPT, std::cout << SEARCHING;
		std::cin >> index;

		// check if cin fails with huge input
		if (std::cin.fail())
		{
			std::cout << INVALID_INPUT << std::endl;
			std::cin.clear(); // Clear the fail state
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Remove the bad input
			continue; // Restart the loop immediately
		}
		if (index >= 1 && index <= _contactCount)
		{
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			break ;
		}
		std::cout << INVALID_INDEX << std::endl;
	}
	printer.displayContactDetails(this->_contacts[index-1]);
}

/**
 * Create new contact and save entry
 * @retval void
 * Prompt user input, instanciate Contact object and add it to PhoneBook
 */
void PhoneBook::addContact(void)
{
	Contact		contact;
	const int	max = getMaxContacts();
	int			index = getContactIndex();
	int			total = getContactCount();

	promptForDetails(contact);
	setContact(contact, index);
	setContactIndex((index + 1) % max);
	if (total < max)
		setContactCount(total + 1);

    std::cout << SUCCESS << std::endl;
}
