/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 12:45:47 by vvoronts          #+#    #+#             */
/*   Updated: 2025/11/22 16:56:29 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal() {
	std::cout << "...Animal Constructor" << std::endl;
	this->type = "Animal";
}

Animal::Animal(const Animal &src) {
	std::cout << "...Animal Copy constructor" << std::endl;
	*this = src;
}

Animal &Animal::operator=(const Animal &src) {
	std::cout << "...Animal Copy assignment operator" << std::endl;
	if (this != &src) 
		this->setType(src.getType());
	return (*this);
}

Animal::~Animal() {
	std::cout << "...Animal Destructor" << std::endl;
}

std::string Animal::getType() const {
	return (this->type);
}

void Animal::setType(const std::string& type) {
	this->type = type;
}

void Animal::makeSound() const {
	std::cout << this->getType() << ": General animal sound" << std::endl;
}
