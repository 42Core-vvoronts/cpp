/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 11:28:40 by vvoronts          #+#    #+#             */
/*   Updated: 2025/11/17 18:41:59 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <string>
# include <iostream>
# include <cmath>

/**
* @class Fixed
* @brief Represents a fixed-point number in Orthodox Canonical Form
* 
* OCF
* 	default constructors: int and float
* 	copy constructor
* 	copy overload assignment operator =
* 	default destructor
* Methods:
* 		To get the raw value of the fixed-point value.
* 		To set the raw value of the fixed-point number.
* Attributes:
* 		Store the fixed-point number.
* 		Store the number of fractional bits.
* Overload Insertion
* 
* Notes:
* const used to prevent modification and accept temporary objects (rvalues)
*/
class Fixed {
	public:
		Fixed();
		Fixed(int const number);
		Fixed(float const number);
		Fixed(const Fixed &src);
		Fixed& operator=(Fixed const &src);
		~Fixed();

		bool	operator>(const Fixed &fixed) const;
		bool	operator<(const Fixed &fixed) const;
		bool	operator>=(const Fixed &fixed) const;
		bool	operator<=(const Fixed &fixed) const;
		bool	operator==(const Fixed &fixed) const;
		bool	operator!=(const Fixed &fixed) const;

		Fixed	operator+(const Fixed &fixed) const;
		Fixed	operator-(const Fixed &fixed) const;
		Fixed	operator*(const Fixed &fixed) const;
		Fixed	operator/(const Fixed &fixed) const;
	
		Fixed&	operator++(void);
		Fixed	operator++(int);
		Fixed&	operator--(void);
		Fixed	operator--(int);

		static	Fixed &min(Fixed &fixed1, Fixed &fixed2);
		static	const Fixed &min(const Fixed &fixed1, const Fixed &fixed2);
		static	Fixed &max(Fixed &fixed1, Fixed &fixed2);
		static	const Fixed &max(const Fixed &fixed1, const Fixed &fixed2);

		int		getRawBits (void) const;
		void	setRawBits (int const raw);
		float	toFloat (void) const;
		
		int		toInt (void) const;

	private:
		int					_fixedNumber;
		static int const	_bits = 8;
};

// overload << 
std::ostream & operator<<(std::ostream &os, const Fixed &src);

#endif