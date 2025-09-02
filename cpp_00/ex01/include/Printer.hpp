/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Printer.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 12:09:51 by vvoronts          #+#    #+#             */
/*   Updated: 2025/09/02 14:22:15 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PRINTER_HPP__
# define __PRINTER_HPP__

#include "PrettyPrint.h"
class PhoneBook;
class Contact;

class Printer
{
public:
	Printer();
	~Printer();

	bool displayPhoneBook(PhoneBook& phoneBook);
	void displayContactDetails(Contact& contact);
};

#endif