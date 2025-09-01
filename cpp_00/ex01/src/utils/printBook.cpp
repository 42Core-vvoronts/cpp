/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 18:43:35 by vvoronts          #+#    #+#             */
/*   Updated: 2025/09/01 18:53:44 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "main.h"

/**
 * Display phonebook entries in a table format
 * @param contacts - array of contacts
 * @param index - current contact
 *
 * @retval void
 */
void printBook(Contact *contacts, int index)
{
	std::cout << "|";
	std::stringstream itoa;
	itoa << (index + 1);
	align(itoa.str(), WIDTH);
	align(contacts[index].getFirstName(), WIDTH);
	align(contacts[index].getLastName(), WIDTH);
	align(contacts[index].getNickName(), WIDTH);
	std::cout << std::endl;
}
