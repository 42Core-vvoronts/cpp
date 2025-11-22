/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 12:54:22 by vvoronts          #+#    #+#             */
/*   Updated: 2025/11/22 17:07:38 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
	std::cout << "...WrongCat Constructor" << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal(src) {
	std::cout << "...WrongCat Copy constructor" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &src) {
	std::cout << "...WrongCat Copy assignment" << std::endl;
	if (this != &src)
		this->setType(src.getType());
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << "...WrongCat Destructor" << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << this->getType() << ": Wrong meow" << std::endl;
}
