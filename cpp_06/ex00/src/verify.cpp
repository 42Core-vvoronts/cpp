/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 19:14:20 by vvoronts          #+#    #+#             */
/*   Updated: 2025/12/17 19:28:14 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "Types.h"
#include <limits>
#include <cctype>
#include <cmath>
#include <cerrno>

bool isValidChar(char c) { 
    return (std::isprint(c)); 
}

bool isPseudo(double& base) {
    return !std::isfinite(base) && (errno != ERANGE);
}

const char* verifyInput(const std::string& literal, char* flag) {
    if (std::isprint(*flag) && *(flag + 1) == '\0' && literal.size() == 1)
      return NULL;
    if (*flag == 'f' && *(flag + 1) == '\0' && literal.size() > 1) return NULL;
    if (*flag != '\0' && literal.size() > 0) return ERR_INVALID_INPUT;
    return NULL;
}

bool isOverflow(const double& base, t_type type) {
    switch (type) {
      case DOUBLE: {
        bool overflow = errno;
        errno = 0;
        return (overflow);
      }
      case FLOAT:
        return (base < -std::numeric_limits<float>::max() || base > std::numeric_limits<float>::max());
      case INT:
        return (base < std::numeric_limits<int>::min() || base > std::numeric_limits<int>::max());
      case CHAR:
        return (base < std::numeric_limits<char>::min() ||
                base > std::numeric_limits<char>::max());
      default:
          return (false);
    }
}