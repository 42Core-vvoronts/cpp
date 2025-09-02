/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printEmpty.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 16:58:58 by vvoronts          #+#    #+#             */
/*   Updated: 2025/09/02 13:57:25 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "main.h"
#include "PrettyPrint.h"

/**
 * Display phonebook with no entries
 * @param str - string to align
 * @param width - width to align to
 *
 * @retval void
 */
void printEmptyBook(void)
{	
	std::cout << "|";
	align("", WIDTH * 4 + 3);
	std::cout << std::endl << ROW << std::endl;
	std::cout << BOOK_IS_EMPTY << std::endl;
}
