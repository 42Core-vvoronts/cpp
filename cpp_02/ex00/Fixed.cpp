/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 11:28:38 by vvoronts          #+#    #+#             */
/*   Updated: 2025/11/04 11:53:15 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

/**
 * @brief Default constructor initializes fixed-point number to 0
*/
Fixed::Fixed() : _fixedNumber(0) {
	std::cout << "Default constructor called" << std::endl;
}

/**
* @brief Copy constructor creates a new Fixed object as a copy of an existing one
* @param constructor Reference to another Fixed object to copy from
* @note Uses the assignment operator to perform the copy
* 
*/
Fixed::Fixed (Fixed &constructor) {
	std::cout << "Copy constructor called" << std::endl;
	*this = constructor;
}

/**
 * @brief Copy assignment operator assigns one Fixed object to another.
 * @param src Constant reference to the source Fixed object.
 * @return Reference to the current object (*this).
 */
Fixed & Fixed::operator=(Fixed const &src){
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		_fixedNumber = src.getRawBits();
	return *this;
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits (void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedNumber);
}

void Fixed::setRawBits (int const raw) {
	this->_fixedNumber = raw;
}