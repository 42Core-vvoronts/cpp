/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 12:45:50 by vvoronts          #+#    #+#             */
/*   Updated: 2025/11/16 12:48:11 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <string>
# include <iostream>

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