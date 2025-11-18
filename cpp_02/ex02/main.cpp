/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 11:28:34 by vvoronts          #+#    #+#             */
/*   Updated: 2025/11/18 22:12:42 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int subject_test( void ) {
	
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	
	std::cout << b << std::endl;
	
	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << std::endl;
	return 0;
}

int main( void )
{
	//copy from subject
	subject_test();

	//my own tests
	// --- SECTION 1: CONSTRUCTORS AND INITIALIZATION ---
	std::cout << "\n\n------- TEST ------" << std::endl;
	std::cout << "--- CONSTRUCTORS AND INITIALIZATION ---" << std::endl;
	Fixed a;                // Default constructor
	Fixed const b( 10 );    // Int constructor
	Fixed const c( 42.42f ); // Float constructor
	Fixed const d( b );     // Copy constructor

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << std::endl;

	// --- SECTION 2: ASSIGNMENT AND CONVERSION ---
	std::cout << "--- ASSIGNMENT AND CONVERSION ---" << std::endl;
	a = Fixed( 1234.4321f ); // Assignment operator
	std::cout << "a is assigned " << a << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "a is " << a.toFloat() << " as float" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << std::endl;

	// --- SECTION 3: COMPARISON OPERATORS ---
	std::cout << "--- COMPARISON OPERATORS ---" << std::endl;
	Fixed e(10);
	Fixed f(20);
	std::cout << "e is " << e << ", f is " << f << std::endl;
	std::cout << "e > f is " << (e > f) << std::endl;   // false
	std::cout << "e < f is " << (e < f) << std::endl;   // true
	std::cout << "e >= e is " << (e >= e) << std::endl; // true
	std::cout << "e <= f is " << (e <= f) << std::endl; // true
	std::cout << "e == b is " << (e == b) << std::endl; // true (b is 10)
	std::cout << "e != f is " << (e != f) << std::endl; // true
	std::cout << std::endl;

	// --- SECTION 4: ARITHMETIC OPERATORS ---
	std::cout << "--- ARITHMETIC OPERATORS ---" << std::endl;
	Fixed g(5.5f);
	Fixed h(2);
	std::cout << "g is " << g << ", h is " << h << std::endl;
	std::cout << "g + h = " << g + h << std::endl; // 7.5
	std::cout << "g - h = " << g - h << std::endl; // 3.5
	std::cout << "g * h = " << g * h << std::endl; // 11
	std::cout << "g / h = " << g / h << std::endl; // 2.75
	std::cout << std::endl;
	
	// --- SECTION 5: INCREMENT/DECREMENT OPERATORS ---
	std::cout << "--- INCREMENT/DECREMENT OPERATORS ---" << std::endl;
	Fixed i;
	std::cout << "i starts at: " << i << std::endl;
	// Pre-increment
	std::cout << "Value of ++i: " << ++i << std::endl;
	std::cout << "Value of i after pre-increment: " << i << std::endl;
	// Post-increment
	std::cout << "Value of i++: " << i++ << std::endl;
	std::cout << "Value of i after post-increment: " << i << std::endl;
	// Pre-decrement
	std::cout << "Value of --i: " << --i << std::endl;
	std::cout << "Value of i after pre-decrement: " << i << std::endl;
	// Post-decrement
	std::cout << "Value of i--: " << i-- << std::endl;
	std::cout << "Value of i after post-decrement: " << i << std::endl;
	std::cout << std::endl;
	
	// --- SECTION 6: MIN / MAX STATIC FUNCTIONS ---
	std::cout << "--- MIN / MAX FUNCTIONS ---" << std::endl;
	Fixed val1( 100 );
	Fixed val2( 100.5f );
	const Fixed cval1( -10 );
	const Fixed cval2( -20 );

	std::cout << "val1 is " << val1 << ", val2 is " << val2 << std::endl;
	std::cout << "Min(val1, val2) is " << Fixed::min( val1, val2 ) << std::endl;
	std::cout << "Max(val1, val2) is " << Fixed::max( val1, val2 ) << std::endl;
	std::cout << std::endl;

	std::cout << "cval1 is " << cval1 << ", cval2 is " << cval2 << std::endl;
	std::cout << "Min(cval1, cval2) is " << Fixed::min( cval1, cval2 ) << std::endl;
	std::cout << "Max(cval1, cval2) is " << Fixed::max( cval1, cval2 ) << std::endl;
	std::cout << std::endl;

	return 0;
}
