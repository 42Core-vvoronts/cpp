/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 12:54:22 by vvoronts          #+#    #+#             */
/*   Updated: 2025/11/20 21:57:36 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() {
	std::cout << "...WrongCat Constructor" << std::endl;
	this->type = "WrongCat";
}

WrongCat::~WrongCat() {
	std::cout << "...WrongCat Destructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal(src) {
	std::cout << "...WrongCat Copy constructor" << std::endl;
	*this = src;
}

WrongCat &WrongCat::operator=(const WrongCat &src) {
	if (this != &src) {
		this->setType(src.getType()); 
	}
	return (*this);
}

void WrongCat::makeSound() const {
	std::cout << this->type << ": Wrong meow" << std::endl;
}
