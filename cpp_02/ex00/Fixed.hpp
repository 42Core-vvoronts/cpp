/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 11:28:40 by vvoronts          #+#    #+#             */
/*   Updated: 2025/11/04 13:43:26 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <string>

/**
 * @class Fixed
 * @brief Represents a fixed-point number in Orthodox Canonical Form
 * 
 * OCF
 * 	default constructor: 
 * 	copy constructor:
 * 	copy assignment operator overload:
 * 	default destructor:
 * Methods:
 * 		To get the raw value of the fixed-point value.
 * 		To set the raw value of the fixed-point number.
 * Attributes:
 * 		Store the fixed-point number.
 * 		Store the number of fractional bits.
 * 
 * Notes:
 * const used to prevent modification and accept temporary objects (rvalues)
 */
class Fixed
{
	public:
		Fixed(); // default constructor
		Fixed (const Fixed &object); // copy constructor
		Fixed& operator=(const Fixed &object);
		~Fixed(); //default destructor

		int getRawBits (void) const;
		void setRawBits (int const raw);
		
	private:
		int 				_value;
		static int const	_bits = 8;
};

#endif