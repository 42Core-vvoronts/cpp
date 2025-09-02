/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 15:02:43 by vvoronts          #+#    #+#             */
/*   Updated: 2025/09/02 14:21:59 by vvoronts         ###   ########.fr       */
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
	int					getContactCount(void);
	int					getContactIndex(void);
	int					getMaxContacts(void);
	Contact*			getContactsArray(void);
	void				setContactCount(int count);
	void				setContactIndex(int index);
	void				setContact(Contact& contact, int index);
	// Methods
	void				addContact(void);
	void				searchContact(void);

private:
	static const int	_maxContacts = 8;
	int					_contactIndex;
	int					_contactCount;
	Contact				_contacts[_maxContacts];		
};

#endif