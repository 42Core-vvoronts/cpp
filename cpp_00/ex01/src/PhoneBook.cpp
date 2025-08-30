/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 15:02:39 by vvoronts          #+#    #+#             */
/*   Updated: 2025/08/27 14:10:15 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "main.h"

void PhoneBook::addContact(const Contact& contact)
{
	if (_contactCount < MAX_CONTACTS)
	{
		_contacts[_contactCount] = contact;
		_contactCount++;
	}
	else
	{
		//add logic for replacing the oldest contact
	}
}

