/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 12:48:25 by vvoronts          #+#    #+#             */
/*   Updated: 2025/11/16 12:48:58 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
	std::cout << "...Cat Constructor" << std::endl;
	this->type = "Cat";
}

Cat::~Cat() {
	std::cout << "...Cat Destructor" << std::endl;
}

Cat::Cat(const Cat &src) : Animal(src) {
	std::cout << "...Cat Copy constructor" << std::endl;
	*this = src;
}

Cat &Cat::operator=(const Cat &src) {
	this->type = src.type;
	return (*this);
}

void Cat::makeSound() const {
	std::cout << "Meow" << std::endl;
}