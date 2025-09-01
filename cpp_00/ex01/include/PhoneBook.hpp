/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 15:02:43 by vvoronts          #+#    #+#             */
/*   Updated: 2025/09/01 16:00:10 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP
#include "main.h"

class PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();

		void				addContact(void);
		void				searchContact(void);
		int					getContactCount(void);
		bool				displayPhoneBook(void);
		void				displayContactDetails(Contact& contact);

	private:
		static const int	_maxContacts = 8;
		int					_contactIndex;
		int					_contactCount;
		Contact				_contacts[_maxContacts];
		
};

#endif