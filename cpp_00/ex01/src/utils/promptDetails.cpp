/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   promptDetails.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 19:04:27 by vvoronts          #+#    #+#             */
/*   Updated: 2025/09/02 12:05:36 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "main.h"
#include "PrettyPrint.h"

static void prompt(std::string& userInput, const std::string promptText)
{
	bool warning = false;

	while (userInput.empty())
	{
		if (warning == true)
			std::cout << WARNING << std::endl;
		std::cout << PROMPT;
		std::cout << promptText;
		std::getline(std::cin, userInput);
		warning = true;
	}
}

/**
 * Prompt user for contact details
 * @param userInput - vector to store input
 * @param i - index of the current prompt
 *
 * @retval void
 */
void promptForDetails(Contact& contact)
{
	std::string name, lastname, nickname, phone, secret;

	std::cout << ADDING << std::endl;

	prompt(name, NAME);
	prompt(lastname, LASTNAME);
	prompt(nickname, NICKNAME);
	prompt(phone, PHONE);
	prompt(secret, SECRET);

	contact.setFirstName(name);
	contact.setLastName(lastname);
	contact.setNickName(nickname);
	contact.setPhoneNumber(phone);
	contact.setDarkestSecret(secret);
}
