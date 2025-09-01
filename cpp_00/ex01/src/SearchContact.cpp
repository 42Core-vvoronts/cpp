/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SearchContact.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 19:21:31 by vvoronts          #+#    #+#             */
/*   Updated: 2025/09/01 20:39:19 by vvoronts         ###   ########.fr       */
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
	int	index = 0;
	bool isempty;

	isempty = displayPhoneBook();
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
	displayContactDetails(this->_contacts[index-1]);
}
