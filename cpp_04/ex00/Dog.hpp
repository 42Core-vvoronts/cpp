/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 12:49:46 by vvoronts          #+#    #+#             */
/*   Updated: 2025/11/16 12:50:58 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"
# include <string>
# include <iostream>

class Dog : public Animal {
	public:
		Dog();
		Dog(Dog const &src);
		Dog& operator=(Dog const &src);
		virtual ~Dog();

		virtual void	makeSound(void) const;

};

#endif