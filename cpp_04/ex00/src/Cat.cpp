/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 12:48:25 by vvoronts          #+#    #+#             */
/*   Updated: 2025/11/20 21:57:21 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
	std::cout << "...Cat Constructor" << std::endl;
	this->type = "Cat";
}

Cat::Cat(const Cat &src) : Animal(src) {
	std::cout << "...Cat Copy constructor" << std::endl;
	*this = src;
}

Cat &Cat::operator=(const Cat &src) {
	if (this != &src) {
		this->setType(src.getType()); 
	}
	return (*this);
}

Cat::~Cat() {
	std::cout << "...Cat Destructor" << std::endl;
}

void Cat::makeSound() const {
	std::cout << this->getType() << ": Meow" << std::endl;
}
