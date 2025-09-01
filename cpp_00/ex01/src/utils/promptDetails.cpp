/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   promptDetails.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 19:04:27 by vvoronts          #+#    #+#             */
/*   Updated: 2025/09/01 19:45:00 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "main.h"

/**
 * Prompt user for contact details
 * @param userInput - vector to store input
 * @param i - index of the current prompt
 *
 * @retval void
 */
void promptForDetails(std::vector<std::string>& userInput)
{
	bool warning;
	std::vector <std::string> promptText;
	promptText.push_back(NAME);
	promptText.push_back(LASTNAME);
	promptText.push_back(NICKNAME);
	promptText.push_back(PHONE);
	promptText.push_back(SECRET);

	std::cout << ADDING << std::endl;
	for (size_t i = 0; i < promptText.size(); i++)
	{
		warning = false;
		while (userInput[i].empty())
		{
			if (warning == true)
				std::cout << WARNING << std::endl;
			std::cout << PROMPT;
			std::cout << promptText[i];
			std::getline(std::cin, userInput[i]);
			warning = true;
		}
	}
}
