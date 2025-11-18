/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 15:02:43 by vvoronts          #+#    #+#             */
/*   Updated: 2025/11/18 22:38:16 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PHONE_BOOK_HPP__
# define __PHONE_BOOK_HPP__

#include "Contact.hpp"
#include <iostream> //cin, cout
#include <limits> // cin fail numeric limits

class PhoneBook
{
	public:
		// Constructors
		PhoneBook();
		~PhoneBook();
		// Getters, setters
		int					getContactCount(void) const;
		int					getContactIndex(void) const;
		// int					getMaxContacts(void) const;
		Contact*			getContactsArray(void) const;
		void				setContactCount(int count);
		void				setContactIndex(int index);
		void				setContact(Contact& contact, int index);
		// Methods
		void				addContact(void);
		void				searchContact(void);

	private:		
		int					_contactIndex;
		int					_contactCount;
		Contact				_contacts[8];
};

#endif