/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AddContact.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 19:21:51 by vvoronts          #+#    #+#             */
/*   Updated: 2025/09/01 19:46:39 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "main.h"

/**
 * Create new contact and save entry
 * @retval void
 * Prompt user input, instanciate Contact object and add it to PhoneBook
 */
void PhoneBook::addContact(void)
{
	Contact contact;
	std::string name, lastname, nickname, phone, secret;
	std::vector <std::string> userInput;
	userInput.push_back(name);
	userInput.push_back(lastname);
	userInput.push_back(nickname);
	userInput.push_back(phone);
	userInput.push_back(secret);
	
	promptForDetails(userInput);
	setContactInfo(contact, userInput);

	_contacts[_contactIndex] = contact;
	_contactIndex = (_contactIndex + 1) % _maxContacts;
	if (_contactCount < _maxContacts)
		_contactCount++;

    std::cout << SUCCESS << std::endl;
}
