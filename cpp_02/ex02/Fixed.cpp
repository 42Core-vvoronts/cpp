/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 11:28:38 by vvoronts          #+#    #+#             */
/*   Updated: 2025/11/18 22:02:04 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

/* ---------------------ORTHODOX CANONICAL FORM---------------------------------------*/

Fixed::Fixed() : _raw(0) {
	std::cout << "...Default constructor called" << std::endl;
}

/**
 * @brief Shift left by 8 is equivalent to multiplying by 256
 * eg decimal 3 -> 000000011 
 * shifted left by 8 -> 00000001100000000 (which is 768 in decimal)
*/
Fixed::Fixed(int const number) {
	this->_raw = (number << _bits);
	//
	std::cout << "...Int constructor called" << std::endl;
}

/**
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
 * 		roundf(832.00) to nearest integer = 832
 *		A direct cast to an integer eg (int)10859.52 would truncate the value to 10859
 *		round the scaled value to the NEAREST integer, providing a more accurate representation
 * Store:
 * 		Store 832 as int in _raw
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

/* ---------------------GETTERS / SETTERS -----------------------------------------------*/

/**
 * @brief Gets the raw value of the fixed-point number
 * @return The raw fixed-point value as an integer
 */
int Fixed::getRawBits (void) const {
	// std::cout << "...getRawBits member function called" << std::endl;
	return (this->_raw);
}

int Fixed::getBits(void) const {
	return this->_bits;
}

/**
 * @brief Sets the raw value of the fixed-point number
 * @param raw The raw fixed-point value to set
 */
void Fixed::setRawBits (int const raw) {
	this->_raw = raw;
}

/* --------------------------CONVERTORS----------------------------------------------*/

float Fixed::toFloat(void) const {
	return (float)this->getRawBits() / (1 << getBits());
}

int Fixed::toInt(void) const {
	return this->getRawBits() >> getBits();
}

/**
 * @brief Overload of the insertion operator for Fixed class
 * @param out Reference to the output stream
 * @param value Constant reference to the Fixed object to output
 * @return Reference to the output stream
 * Outputs the fixed-point number as a float to the stream
 * Uses the toFloat() method for conversion
 *	 Example:
 *		Fixed a(3.25f);
 *		std::cout << a; // Outputs: 3.25
 */
std::ostream& operator<<(std::ostream &out, const Fixed &value) {
	out << value.toFloat();
	return out;
}

/* --------------------------COMPARISON OPERATORS X6---------------------------------- 
The 6 comparison operators: >, <, >=, <=, ==, and !=.*/

bool	Fixed::operator>(const Fixed &fixed) const {
	return this->getRawBits() > fixed.getRawBits();
}

bool	Fixed::operator<(const Fixed &fixed) const {
	return this->getRawBits() < fixed.getRawBits();
}

bool	Fixed::operator>=(const Fixed &fixed) const {
	return this->getRawBits() >= fixed.getRawBits();
}

bool	Fixed::operator<=(const Fixed &fixed) const {
	return this->getRawBits() <= fixed.getRawBits();
}

bool	Fixed::operator==(const Fixed &fixed) const {
	return this->getRawBits() == fixed.getRawBits();
}

bool	Fixed::operator!=(const Fixed &fixed) const {
	return this->getRawBits() != fixed.getRawBits();
}

/* --------------------------ARITHMETIC OPERATORS X4----------------------------------
The 4 arithmetic operators: +, -, *, and /.*/

Fixed	Fixed::operator+(const Fixed &fixed) const {
	Fixed result;
	result.setRawBits(this->getRawBits() + fixed.getRawBits());
	return result;
}

Fixed	Fixed::operator-(const Fixed &fixed) const {
	Fixed result;
	result.setRawBits(this->getRawBits() - fixed.getRawBits());
	return result;
}

/**
 * @brief Multiplies two fixed-point numbers
 * Casting to a wider integer type like long 
* prevents overflow before you scale the result back down by shifting right (>> _bits)
 */
Fixed	Fixed::operator*(const Fixed &fixed) const {
	Fixed result;
	long temp = static_cast<long>(this->getRawBits()) * static_cast<long>(fixed.getRawBits());
	result.setRawBits(static_cast<int>(temp >> this->getBits()));
	return result;
}

/**
 * @brief Divides two fixed-point numbers
 * scale the numerator up by shifting left (<< _bits) 
 * before dividing to preserve the fractional part of the result
 * Casting to long prevents overflow during the division operation
 */
Fixed	Fixed::operator/(const Fixed &fixed) const {
	Fixed result;
	long temp = (static_cast<long>(this->getRawBits()) << this->getBits()) / static_cast<long>(fixed.getRawBits());
	result.setRawBits(static_cast<int>(temp));
	return result;
}

/* -------------------------- INCREMENT/DECREMENT OPERATORS X4---------------------------------*/

Fixed& Fixed::operator++(void) { // Pre-increment
	this->setRawBits(this->getRawBits() + 1);
	return *this;
}

Fixed Fixed::operator++(int) { // Post-increment
	Fixed temp(*this);
	this->setRawBits(this->getRawBits() + 1);
	return temp;
}

Fixed& Fixed::operator--(void) { // Pre-decrement
	this->setRawBits(this->getRawBits() - 1);
	return *this;
}

Fixed Fixed::operator--(int) { // Post-decrement
	Fixed temp(*this);
	this->setRawBits(this->getRawBits() - 1);
	return temp;
}


/* -------------------------- MIN / MAX  X4----------------------------------*/
/* pre-increment and post-increment, pre-decrement and
post-decrement) operators, which will increase or decrease the fixed-point value by
the smallest representable ϵ, such that 1 + ϵ > 1*/

/**A static member function min that takes two references to fixed-point numbers as
* parameters, and returns a reference to the smallest one
*/
Fixed &Fixed::min(Fixed &fixed1, Fixed &fixed2) {
	if (fixed1 < fixed2)
		return fixed1;
	return fixed2;
}

/** A static member function min that takes two references to constant fixed-point
 * numbers as parameters, and returns a reference to the smallest one.
 */
const Fixed &Fixed::min(const Fixed &fixed1, const Fixed &fixed2) {
	if (fixed1 < fixed2)
		return fixed1;
	return fixed2;
}

/** A static member function max that takes two references to fixed-point numbers as
 * parameters, and returns a reference to the greatest one.
 */
Fixed &Fixed::max(Fixed &fixed1, Fixed &fixed2) {
	if (fixed1 > fixed2)
		return fixed1;
	return fixed2;
}

/** A static member function max that takes two references to constant fixed-point
 * numbers as parameters, and returns a reference to the greatest one.
 */
const Fixed &Fixed::max(const Fixed &fixed1, const Fixed &fixed2) {
	if (fixed1 > fixed2)
		return fixed1;
	return fixed2;
}
