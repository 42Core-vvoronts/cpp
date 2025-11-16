/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 12:45:47 by vvoronts          #+#    #+#             */
/*   Updated: 2025/11/16 12:59:49 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() {
	std::cout << "..Animal Constructor" << std::endl;
	this->type = "Animal";
}

Animal::~Animal() {
	std::cout << "..Animal Destructor" << std::endl;
}

Animal::Animal(const Animal &src) {
	std::cout << "..Animal Copy constructor" << std::endl;
	*this = src;
}

Animal &Animal::operator=(const Animal &src) {
	this->type = src.type;
	return (*this);
}

void Animal::makeSound() const {
	std::cout << "General animal sound" << std::endl;
}

std::string Animal::getType() const {
	return (this->type);
}