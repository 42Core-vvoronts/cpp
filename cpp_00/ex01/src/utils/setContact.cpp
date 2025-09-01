/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setContact.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 19:12:11 by vvoronts          #+#    #+#             */
/*   Updated: 2025/09/01 19:48:16 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "main.h"

void setContactInfo(Contact& contact, std::vector<std::string>& userInput)
{
	contact.setFirstName(userInput[0]);
	contact.setLastName(userInput[1]);
	contact.setNickName(userInput[2]);
	contact.setPhoneNumber(userInput[3]);
	contact.setDarkestSecret(userInput[4]);
}
	