/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printHeader.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 11:19:00 by vvoronts          #+#    #+#             */
/*   Updated: 2025/09/02 12:05:39 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "main.h"
#include "PrettyPrint.h"

/**
 * Print table header for PhoneBook display
 *
 * @retval void
 */
 void printHeader()
 {
	const int headersCount = 4;
	std::string headers[headersCount];

	headers[0] = "index";
	headers[1] = "first name";
	headers[2] = "last name";
	headers[3] = "nickname";
	
	std::cout << ROW << std::endl << "|";
	for (size_t i = 0; i < headersCount; i++)
		align(headers[i], WIDTH);
	std::cout << std::endl << ROW << std::endl;
 }