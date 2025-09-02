/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 18:43:35 by vvoronts          #+#    #+#             */
/*   Updated: 2025/09/02 13:17:16 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "PrettyPrint.h"
#include "main.h"

/**
 * Display phonebook entries in a table format
 * @param contacts - array of contacts
 * @param index - current contact
 *
 * @retval void
 */
void printBook(Contact *contacts, int contactCount)
{
	for (int i = 0; i < contactCount; i++)
	{
		std::cout << "|";
		std::stringstream itoa;
		itoa << (i + 1);
		align(itoa.str(), WIDTH);
		align(contacts[i].getFirstName(), WIDTH);
		align(contacts[i].getLastName(), WIDTH);
		align(contacts[i].getNickName(), WIDTH);
		std::cout << std::endl;
	}
}
