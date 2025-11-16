/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 12:45:50 by vvoronts          #+#    #+#             */
/*   Updated: 2025/11/16 14:24:56 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <string>
# include <iostream>

/*
 * @class Animal
 * @brief Base class representing a generic animal.
 *
 * For polymorphic deletion (deleting a derived object through a base pointer), 
 * the base class must have a virtual destructor for the derived destructor to be invoked
*/
class Animal {
	public:
		Animal();
		Animal(Animal const &src);
		Animal& operator=(Animal const &src);
		virtual ~Animal();

		virtual void	makeSound(void) const;
		std::string		getType(void) const;

	protected:
		std::string type;
};

#endif