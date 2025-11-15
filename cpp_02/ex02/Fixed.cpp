/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 11:28:38 by vvoronts          #+#    #+#             */
/*   Updated: 2025/11/15 23:37:10 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

/**
* @brief Default constructor 
* initializes fixed-point number to 0
*/
Fixed::Fixed() : _fixedNumber(0) {}

Fixed::Fixed(int const number) {
	this->_fixedNumber = (number << this->_bits);
	// std::cout << "Int Constructor called" << std::endl;
}

Fixed::Fixed(float const number) {
	// std::cout << "Float Constructor called" << std::endl;
	this->_fixedNumber = static_cast<int>(roundf(number*(1 << this->_bits)));
}

Fixed::Fixed (const Fixed &constructor) {
	// std::cout << "Copy constructor for Fixed called" << std::endl;
	*this = constructor;
}

Fixed & Fixed::operator=(Fixed const &src){
	// std::cout << "Assignment operator called" << std::endl;
	if (this != &src)
		_fixedNumber = src.getRawBits();
	return *this;
}

Fixed::~Fixed(){
	// std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits (void) const {
	return (this->_fixedNumber);
}

void	Fixed::setRawBits (int const raw) {
	this->_fixedNumber = raw;
}

float	Fixed::toFloat (void) const {
	return (static_cast<float>(this->_fixedNumber)) / (1 << this->_bits);
}

int	Fixed::toInt (void) const {
	return (static_cast<int>((this->_fixedNumber) >> this->_bits));
}

bool	Fixed::operator>(const Fixed &fixed) const
{
	return (this->toFloat() > fixed.toFloat());
}

bool	Fixed::operator<(const Fixed &fixed) const {
	return (this->toFloat() < fixed.toFloat());
}

bool	Fixed::operator>=(const Fixed &fixed) const{
	return (this->toFloat() >= fixed.toFloat());
}

bool	Fixed::operator<=(const Fixed &fixed) const{
	return (this->toFloat() <= fixed.toFloat());
}

bool	Fixed::operator==(const Fixed &fixed) const{
	return (this->toFloat()== fixed.toFloat());
}

bool	Fixed::operator!=(const Fixed &fixed) const{
	return (this->toFloat() != fixed.toFloat());
}

Fixed	Fixed::operator+(const Fixed &fixed) const{
	return (this->toFloat() + fixed.toFloat());
}

Fixed	Fixed::operator-(const Fixed &fixed) const{
	return (this->toFloat() - fixed.toFloat());
}

Fixed	Fixed::operator*(const Fixed &fixed) const{
	return (this->toFloat() * fixed.toFloat());
}

Fixed	Fixed::operator/(const Fixed &fixed) const{
	return (this->toFloat() / fixed.toFloat());
}

Fixed&  Fixed::operator++(void) {
	this->_fixedNumber++;
	return (*this);
}

Fixed   Fixed::operator++(int)
{
	Fixed	temp(*this);

	_fixedNumber++;
	return (temp);
}

Fixed&  Fixed::operator--(void) {
	this->_fixedNumber--;
	return (*this);
}

Fixed   Fixed::operator--(int){
	Fixed	temp(*this);

	_fixedNumber++;
	return (temp);
}

Fixed &Fixed::min(Fixed &fixed1, Fixed &fixed2){
	if (fixed1 > fixed2)
		return (fixed2);
	else
		return (fixed1);
}

const Fixed &Fixed::min(const Fixed &fixed1, const Fixed &fixed2){
	if (fixed1 > fixed2)
		return (fixed2);
	else
		return (fixed1);
}

Fixed	&Fixed::max(Fixed &fixed1, Fixed &fixed2){
	if (fixed1 > fixed2)
		return (fixed1);
	else
		return (fixed2);
}

const	Fixed &Fixed::max(const Fixed &fixed1, const Fixed &fixed2){
	if (fixed1 > fixed2)
		return (fixed1);
	else
		return (fixed2);
}

std::ostream & operator<<(std::ostream &os, const Fixed &src) {
	// std::cout << "Assigment overload called" << std::endl;

	os << src.toFloat();
	return (os);
}

