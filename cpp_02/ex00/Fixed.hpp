/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 11:28:40 by vvoronts          #+#    #+#             */
/*   Updated: 2025/11/04 11:50:48 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <string>

/**
 * @class Fixed
 * @brief Represents a fixed-point number in Orthodox Canonical Form
 * 
 * default constructor: 
 * copy constructor: 
 * copy assignment operator overload: 
 * default destructor: 
 * methods: 
 * 		To get the raw value of the fixed-point value.
 * 		To set the raw value of the fixed-point number.
 * private attributes:
 * 		Store the fixed-point number.
 * 		Store the number of fractional bits.
 */
class Fixed
{
	public:
		Fixed(); // default constructor
		Fixed (Fixed &src); // copy constructor

		Fixed& operator=(Fixed const &src);

		~Fixed(); //default destructor

		int getRawBits (void) const;
		void setRawBits (int const raw);
		
	private:
		int 				_fixedNumber;
		static int const	_bits = 8;
};

#endif