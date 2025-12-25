/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 19:16:14 by vvoronts          #+#    #+#             */
/*   Updated: 2025/12/25 09:24:44 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "Types.h"

/*
 * @brief Initial parsing of literal string to a double value
*/
double parseToDouble(const std::string& literal, char** flag) {
    double base = std::strtod(literal.c_str(), flag);
    if (base == 0.0 && literal.size() == 1 && literal[0] != '0') base = literal[0];
    return base;
}

void convertChar(const double& base) {
    if (isOverflow(base, CHAR)) {
      std::cout << "char: overflow" << std::endl;
      return;
    }
    char c = static_cast<char>(base);
    if (isValidChar(c))
      std::cout << "char: " << c << std::endl;
    else
      std::cout << "char: Non displayable" << std::endl;
}

void convertInt(const double& base) {
    if (isOverflow(base, INT)) {
      std::cout << "int: overflow" << std::endl;
      return;
    }
    std::cout << "int: " << static_cast<int>(base) << std::endl;
}

void convertFloat(const double& base) {
    if (isOverflow(base, FLOAT)) {
      std::cout << "float: overflow" << std::endl;
      return;
    }
    float f = static_cast<float>(base);
    std::string frc = ".0";
    if (f != trunc(f)) frc = "";
    std::cout << "float: " << f << frc << "f" << std::endl;
}

void convertDouble(const double& base) {
    if (isOverflow(base, DOUBLE)) {
      std::cout << "double: overflow" << std::endl;
      return;
    }
    std::string frc = ".0";
    if (base != trunc(base)) frc = "";
    std::cout << "double: " << base << frc << std::endl;
}
