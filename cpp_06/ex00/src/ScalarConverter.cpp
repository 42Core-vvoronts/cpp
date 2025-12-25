/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:58:52 by vvoronts          #+#    #+#             */
/*   Updated: 2025/12/25 09:27:40 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "Types.h"
#include <cctype>
#include <limits>
#include <iostream>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &src) { *this = src; }
ScalarConverter::~ScalarConverter() {}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src) {
    if (this != &src) {
        (void)src;
    }
    return *this;
}

/*
* @brief Convert the given literal string to all scalar types and display the results.
* @param literal The string representation of the literal to convert.
* @return void
* 
* will take as a parameter a string representation of a C++ literal in its most common
* form and output its value in the following series of scalar types: char, int, float, double
*/
void ScalarConverter::convert(const std::string& literal) {
    char*       flag;
    double      base;
    const char* err;
    t_type      type;

    base = parseToDouble(literal, &flag);
    err = verifyInput(literal, flag);
    if (err) {
        std::cout << err << literal << std::endl;
        return;
    }

    type = detectType(base);
    switch (type) {
        case PSEUDO:
            displayPseudo(base);
            break;
        default:
            convertChar(base);
            convertInt(base);
            convertFloat(base);
            convertDouble(base);
    }
}
