/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 12:52:49 by vvoronts          #+#    #+#             */
/*   Updated: 2025/11/22 12:59:09 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include <string>
# include <iostream>

class WrongAnimal {
	public:
		WrongAnimal();
		WrongAnimal(WrongAnimal const &src);
		WrongAnimal& operator=(WrongAnimal const &src);
		virtual ~WrongAnimal();

		void			makeSound(void) const; // non-virtual in WrongAnimal
		std::string		getType(void) const;

	protected:
		void			setType(const std::string& type);
		std::string		type;
};

#endif


