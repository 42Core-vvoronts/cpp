/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 11:28:38 by vvoronts          #+#    #+#             */
/*   Updated: 2025/11/15 23:10:48 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

/**
 * @brief Default constructor 
 * initializes fixed-point number to 0
*/
Fixed::Fixed(void) : _value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int intValue) {
	std::cout << "Int constructor called" << std::endl;
	this->_value = intValue << _bits;
}


Fixed::Fixed(const float floatValue) {
	std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(floatValue * (1 << _bits));
}

/**
* @brief Copy constructor
* @param object Reference to another Fixed object to copy from
* @note Uses the assignment operator to perform the copy
*
* Calls the copy assignment operator to avoid code duplication
* 
*/
Fixed::Fixed (const Fixed &object) {
	std::cout << "Copy constructor called" << std::endl;
	*this = object;
}

/**
 * @brief Copy assignment operator overload
 * @param object Constant reference to the source Fixed object
 *
 * Assigns the value of the 'other' object to the current object
 *
 * @return Reference to the current object (*this).
 */
Fixed & Fixed::operator=(Fixed const &object){
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &object)
		this->_value = object.getRawBits();
	return *this;
}

/**
 * @brief Destructor
 */
Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

/**
 * @brief Gets the raw value of the fixed-point number
 * @return The raw fixed-point value as an integer
 */
int Fixed::getRawBits (void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

/**
 * @brief Sets the raw value of the fixed-point number
 * @param raw The raw fixed-point value to set
 */
void Fixed::setRawBits (int const raw) {
	this->_value = raw;
}

// 
float Fixed::toFloat(void) const {
	return (float)this->_value / (1 << _bits);
}

// t
int Fixed::toInt(void) const {
	return this->_value >> _bits;
}

// operator<< overload implementation
std::ostream& operator<<(std::ostream &out, const Fixed &value) {
	out << value.toFloat();
	return out;
}
