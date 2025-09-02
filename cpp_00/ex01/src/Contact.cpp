/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 15:01:05 by vvoronts          #+#    #+#             */
/*   Updated: 2025/09/02 12:48:06 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
	// std::cout << "A Contact has been constructed." << std::endl;
}

Contact::~Contact()
{
	// std::cout << "A Contact has been destructed." << std::endl;
}

// Getters
std::string Contact::getFirstName(void)
{
	return this->_firstName;
}

std::string Contact::getLastName(void)
{
	return this->_lastName;
}

std::string Contact::getNickName(void)
{
	return this->_nickName;
}

std::string Contact::getPhoneNumber(void)
{
	return this->_phoneNumber;
}

std::string Contact::getDarkestSecret(void)
{
	return this->_darkestSecret;
}

// Setters
void Contact::setFirstName(std::string firstName)
{
	this->_firstName = firstName;
}

void Contact::setLastName(std::string lastName)
{
	this->_lastName = lastName;
}

void Contact::setNickName(std::string nickName)
{
	this->_nickName = nickName;
}

void Contact::setPhoneNumber(std::string phoneNumber)
{
	this->_phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(std::string darkestSecret)
{
	this->_darkestSecret = darkestSecret;
}
