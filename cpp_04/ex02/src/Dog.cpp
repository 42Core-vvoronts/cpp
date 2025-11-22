/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 12:50:27 by vvoronts          #+#    #+#             */
/*   Updated: 2025/11/22 18:22:56 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal(), _brain(new Brain) {
	std::cout << "...Dog Constructor" << std::endl;
	this->setType("Dog");
}

Dog::Dog(const Dog& src) : Animal(src), _brain(new Brain) {
	std::cout << "...Dog Copy Constructor" << std::endl;
	*(this->_brain) = *src._brain;
}

Dog& Dog::operator=(const Dog& src) {
	std::cout << "...Dog Copy assignment" << std::endl;
	// 1. Self-assignment check
	if (this == &src)
		return *this;
	// 2. Copy Parent attributes
	this->setType(src.getType());
	// 3. Deep Copy the Brain
	// We do NOT use 'new Brain' here because we already have one.
	// We explicitly call Brain::operator= by dereferencing (*) the pointers.
	// This copies the 100 ideas from src to this.
	if (this->_brain && src._brain)
		*this->_brain = *src._brain;
	return *this;
}

Dog::~Dog() {
	std::cout << "...Dog Destructor" << std::endl;
	delete this->_brain;
}

void	Dog::makeSound() const {
	std::cout << this->getType() << ": Woof" << std::endl;
}
Brain*	Dog::getBrain() const {
	return this->_brain;
}
