/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 19:44:41 by vvoronts          #+#    #+#             */
/*   Updated: 2025/12/25 09:27:25 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "Types.h"
#include <string>
#include <cctype>
#include <limits>
#include <climits>
#include <cstdlib>

// Convert t_type enum to string for display purposes
std::string stringType(t_type type) {
    switch (type) {
        case CHAR:
            return "char";
        case INT:
            return "int";
        case FLOAT:
            return "float";
        case DOUBLE:
            return "double";
        default:
            return "invalid type";
    }
}

t_type detectType(double& literal) {
    if (isPseudo(literal)) {
        return PSEUDO;
    }
    else {
        return CHAR;
    }
}


// // Helper to check for special double values
// static bool isSpecialDouble(const std::string& literal) {
//     return (literal == stringSpec(NAN) || literal == stringSpec(P_INF) || literal == stringSpec(N_INF));
// }


/*Examples of char literals: ’c’, ’a’, ...
To make things simple, please note that non-displayable characters shouldn’t be used as
inputs. If a conversion to char is not displayable, print an informative message.
*/
// bool isChar(const std::string& literal) {

// }

// /* 
// Examples of int literals: 0, -42, 42...
// */
// bool isInt(const std::string& literal) {
// }

// /*Examples of float literals: 0.0f, -4.2f, 4.2f...
// You have to handle these pseudo-literals as well (you know, for science): -inff, +inff,
// and nanf*/
// bool isFloat(const std::string& literal) {
// }

// /* Examples of double literals: 0.0, -4.2, 4.2...
// You have to handle these pseudo-literals as well (you know, for fun): -inf, +inf, and
// nan.*/
// bool isDouble(const std::string& literal) {
// }


/*
 * @brief Detect the type of the given literal string.
 * @param literal The string representation of the literal.
 * @return The detected type as a t_type enum value.
 *
 * You have to first detect the type of the literal passed as a parameter
 * Except for char parameters, only the decimal notation will be used.
char: Non displayable
int: 0
float: 0.0f
double: 0.0
./convert nan
char: impossible
int: impossible
float: nanf
double: nan
./convert 42.0f
char: '*'
int: 42
float: 42.0f
double: 42.0
*/
// t_type detectType(const std::string& literal) {
//     if (isChar(literal)) return CHAR;
//     if (isInt(literal)) return INT;
//     if (isFloat(literal)) return FLOAT;
//     if (isDouble(literal)) return DOUBLE;
//     return INVALID;
// }
