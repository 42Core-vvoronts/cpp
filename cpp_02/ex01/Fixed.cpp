/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 11:28:38 by vvoronts          #+#    #+#             */
/*   Updated: 2025/11/18 21:25:31 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : _raw(0) {
	std::cout << "...Default constructor called" << std::endl;
}

/* Shift left by 8 is equivalent to multiplying by 256
 * eg decimal 3 -> 000000011 
 * shifted left by 8 -> 00000001100000000 (which is 768 in decimal)
*/
Fixed::Fixed(int const number) {
	this->_raw = (number << _bits);
	//
	std::cout << "...Int constructor called" << std::endl;
}

/*
 * @brief Convert float to fixed-point representation
 * 
 * Visualize float: https://float.exposed/0x40500000
 * IEEE 32 bits [1][8][0][23] / 64 bits [1][11][0][52]
 * 
 * Scale:
 *		1 << 8 = 0000001 ->  0000000100000000 = 2^8 = 256
 * 		3.25 * 256 = 832.00
 *		3.25 -> 11.01 -> 0 10000000 [1] 10100000000000000000000
 *		832.00 -> 0 10001000 [1] 10100000000000000000000
 * Round:
 * 		roundf(832)
 *		
*/
Fixed::Fixed(float const number) {
	float scaled = number * (1 << _bits);
	this->_raw = static_cast<int>(roundf(scaled));
	//
	std::cout << "...Float constructor called" << std::endl;
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
	std::cout << "...Copy constructor called" << std::endl;
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
	std::cout << "...Copy assignment operator called" << std::endl;
	if (this != &object)
		this->_raw = object.getRawBits();
	return *this;
}

/**
 * @brief Destructor
 */
Fixed::~Fixed(){
	std::cout << "...Destructor called" << std::endl;
}

/**
 * @brief Gets the raw value of the fixed-point number
 * @return The raw fixed-point value as an integer
 */
int Fixed::getRawBits (void) const {
	// std::cout << "...getRawBits member function called" << std::endl;
	return (this->_raw);
}

/**
 * @brief Sets the raw value of the fixed-point number
 * @param raw The raw fixed-point value to set
 */
void Fixed::setRawBits (int const raw) {
	this->_raw = raw;
}

// 
float Fixed::toFloat(void) const {
	return (float)this->_raw / (1 << _bits);
}

// t
int Fixed::toInt(void) const {
	return this->_raw >> _bits;
}

// operator<< overload implementation
std::ostream& operator<<(std::ostream &out, const Fixed &value) {
	out << value.toFloat();
	return out;
}
