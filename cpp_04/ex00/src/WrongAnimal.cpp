/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 12:51:25 by vvoronts          #+#    #+#             */
/*   Updated: 2025/11/20 21:57:05 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	std::cout << "...WrongAnimal Constructor" << std::endl;
	this->type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal &src) {
	std::cout << "...WrongAnimal Copy constructor" << std::endl;
	*this = src;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &src) {
	if (this != &src) {
		this->setType(src.getType()); 
	}
	return (*this);
}

WrongAnimal::~WrongAnimal() {
	std::cout << "...WrongAnimal Destructor" << std::endl;
}

std::string WrongAnimal::getType() const {
	return (this->type);
}

void WrongAnimal::setType(const std::string& type) {
	this->type = type; 
}

void WrongAnimal::makeSound() const {
	std::cout << this->type << ": General wrong animal sound" << std::endl;
}
