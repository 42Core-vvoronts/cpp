/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 12:50:27 by vvoronts          #+#    #+#             */
/*   Updated: 2025/11/16 12:59:21 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
	std::cout << "...Dog Constructor" << std::endl;
	this->type = "Dog";
}

Dog::~Dog() {
	std::cout << "..Dog Destructor" << std::endl;
}

Dog::Dog(const Dog &src) : Animal(src) {
	std::cout << "..Dog Copy constructor" << std::endl;
	*this = src;
}

Dog &Dog::operator=(const Dog &src) {
	this->type = src.type;
	return (*this);
}

void Dog::makeSound() const {
	std::cout << "Woof" << std::endl;
}
