/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 15:02:43 by vvoronts          #+#    #+#             */
/*   Updated: 2025/08/27 14:31:13 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP
#include "main.h"

class PhoneBook
{
	public:
		void addContact(const Contact& contact);
		void searchContact() const;

	private:
		Contact	_contacts[MAX_CONTACTS];
		int		_contactCount;
		
};

#endif