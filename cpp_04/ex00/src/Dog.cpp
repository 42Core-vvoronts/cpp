/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 12:50:27 by vvoronts          #+#    #+#             */
/*   Updated: 2025/11/22 12:42:53 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
	std::cout << "...Dog Constructor" << std::endl;
	this->type = "Dog";
}

Dog::Dog(const Dog &src) : Animal(src) {
	std::cout << "...Dog Copy constructor" << std::endl;
	*this = src;
}

Dog &Dog::operator=(const Dog &src) {
	if (this != &src) {
		this->setType(src.getType()); 
	}
	return (*this);
}

Dog::~Dog() {
	std::cout << "...Dog Destructor" << std::endl;
}

void Dog::makeSound() const {
	std::cout << this->getType() << ": Woof" << std::endl;
}
