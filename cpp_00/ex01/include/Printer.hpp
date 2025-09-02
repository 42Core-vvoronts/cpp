/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Printer.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 12:09:51 by vvoronts          #+#    #+#             */
/*   Updated: 2025/09/02 13:14:20 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTER_HPP
# define PRINTER_HPP

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