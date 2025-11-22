/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 12:48:25 by vvoronts          #+#    #+#             */
/*   Updated: 2025/11/22 18:22:28 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal(), _brain(new Brain) {
	this->setType("Cat");
	std::cout << "...Cat constructor" << std::endl;
}

Cat::Cat(const Cat& src) : Animal(src), _brain(new Brain) {
	std::cout << "...Cat Copy Constructor" << std::endl;
	*this->_brain = *src._brain;
}
	
Cat& Cat::operator=(const Cat& src) {
	std::cout << "...Cat Copy Assignment" << std::endl;
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

Cat::~Cat() {
	delete this->getBrain();
	std::cout << "...Cat Destructor" << std::endl;
}

void Cat::makeSound() const {
	std::cout << this->getType() << ": Meow" << std::endl;
}

Brain* Cat::getBrain() const { 
	return this->_brain;
};
