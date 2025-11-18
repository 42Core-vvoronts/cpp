/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 11:28:38 by vvoronts          #+#    #+#             */
/*   Updated: 2025/11/17 23:07:16 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

#include "Fixed.hpp"
#include <iostream>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Fixed::Fixed() : _fixedNumber(0) {
}

Fixed::Fixed(int const number) {
	this->_fixedNumber = (number << _bits);
}


/*
 * float scaled = number * (1 << _bits);
 * scales the float up by multiplying it by 256 (since _bits is 8). 
 * This moves the fractional part of the number into the integer part for storage
 * 
 * Manual rounding
 * 
*/
Fixed::Fixed(float const number) {
	float scaled = number * (1 << _bits);

	if (scaled >= 0.0f) {
		this->_fixedNumber = static_cast<int>(scaled + 0.5f);
	} else {
		this->_fixedNumber = static_cast<int>(scaled - 0.5f);
	}
}

Fixed::Fixed(const Fixed & src) {
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Fixed::~Fixed() {
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Fixed& Fixed::operator=(Fixed const & rhs) {
	if ( this != &rhs ) {
		this->_fixedNumber = rhs.getRawBits();
	}
	return *this;
}

std::ostream & operator<<(std::ostream & os, const Fixed & src) {
	os << src.toFloat();
	return os;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

int	Fixed::getRawBits(void) const {
	return this->_fixedNumber;
}

void Fixed::setRawBits(int const raw) {
	this->_fixedNumber = raw;
}

float Fixed::toFloat(void) const {
	return static_cast<float>(this->_fixedNumber) / (1 << _bits);
}

int	Fixed::toInt(void) const {
	return this->_fixedNumber >> _bits;
}


/*
** ----------------------------- COMPARISON OPERATORS ---------------------------
*/

bool Fixed::operator>(const Fixed &fixed) const {
	return this->_fixedNumber > fixed.getRawBits();
}

bool Fixed::operator<(const Fixed &fixed) const {
	return this->_fixedNumber < fixed.getRawBits();
}

bool Fixed::operator>=(const Fixed &fixed) const {
	return this->_fixedNumber >= fixed.getRawBits();
}

bool Fixed::operator<=(const Fixed &fixed) const {
	return this->_fixedNumber <= fixed.getRawBits();
}

bool Fixed::operator==(const Fixed &fixed) const {
	return this->_fixedNumber == fixed.getRawBits();
}

bool Fixed::operator!=(const Fixed &fixed) const {
	return this->_fixedNumber != fixed.getRawBits();
}


/*
** ------------------------------ ARITHMETIC OPERATORS ----------------------------
*/

Fixed Fixed::operator+(const Fixed &fixed) const {
	Fixed result;
	result.setRawBits(this->_fixedNumber + fixed.getRawBits());
	return result;
}

Fixed Fixed::operator-(const Fixed &fixed) const {
	Fixed result;
	result.setRawBits(this->_fixedNumber - fixed.getRawBits());
	return result;
}

Fixed Fixed::operator*(const Fixed &fixed) const {
	Fixed result;
	long product = static_cast<long>(this->_fixedNumber) * fixed.getRawBits();
	result.setRawBits(static_cast<int>(product >> _bits));
	return result;
}

Fixed Fixed::operator/(const Fixed &fixed) const {
	Fixed result;
	long dividend = static_cast<long>(this->_fixedNumber) << _bits;
	result.setRawBits(static_cast<int>(dividend / fixed.getRawBits()));
	return result;
}


/*
** -------------------------- INCREMENT/DECREMENT OPERATORS -----------------------
*/

Fixed& Fixed::operator++(void) { // Pre-increment
	this->_fixedNumber++;
	return *this;
}

Fixed Fixed::operator++(int) { // Post-increment
	Fixed temp(*this);
	this->_fixedNumber++;
	return temp;
}

Fixed& Fixed::operator--(void) { // Pre-decrement
	this->_fixedNumber--;
	return *this;
}

Fixed Fixed::operator--(int) { // Post-decrement
	Fixed temp(*this);
	this->_fixedNumber--;
	return temp;
}

/*
** -------------------------------- MIN/MAX FUNCTIONS -----------------------------
*/

Fixed& Fixed::min(Fixed &fixed1, Fixed &fixed2) {
	if (fixed1 < fixed2)
		return fixed1;
	else
		return fixed2;
}

const Fixed& Fixed::min(const Fixed &fixed1, const Fixed &fixed2) {
	if (fixed1 < fixed2)
		return fixed1;
	else
		return fixed2;
}

Fixed& Fixed::max(Fixed &fixed1, Fixed &fixed2) {
	if (fixed1 > fixed2)
		return fixed1;
	else
		return fixed2;
}

const Fixed& Fixed::max(const Fixed &fixed1, const Fixed &fixed2) {
	if (fixed1 > fixed2)
		return fixed1;
	else
		return fixed2;
}
