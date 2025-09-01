/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SearchContact.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 19:21:31 by vvoronts          #+#    #+#             */
/*   Updated: 2025/09/01 19:51:13 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "main.h"

/**
 * Search existing contact in PhoneBook
 *
 * @retval void
 * Display whole PhoneBook and prompt user to enter index of chosen contact
 * to view full details or exit if PhoneBook is empty
 */
void PhoneBook::searchContact(void)
{
	int	index;
	bool isempty;

	isempty = displayPhoneBook();
	if (isempty)
		return ;
	
	std::cout << PROMPT, std::cout << SEARCHING;
	std::cin >> index;
	displayContactDetails(this->_contacts[index]);
}
