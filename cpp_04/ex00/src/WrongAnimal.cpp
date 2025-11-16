/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 12:51:25 by vvoronts          #+#    #+#             */
/*   Updated: 2025/11/16 14:32:27 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	std::cout << "...WrongAnimal Constructor" << std::endl;
	this->type = "WrongAnimal";
}

WrongAnimal::~WrongAnimal() {
	std::cout << "...WrongAnimal Destructor" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src) {
	std::cout << "...WrongAnimal Copy constructor" << std::endl;
	*this = src;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &src) {
	this->type = src.type;
	return (*this);
}

void WrongAnimal::makeSound() const {
	std::cout << this->type << ": General wrong animal sound" << std::endl;
}

std::string WrongAnimal::getType() const {
	return (this->type);
}