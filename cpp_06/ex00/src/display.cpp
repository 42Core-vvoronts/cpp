/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 19:31:24 by vvoronts          #+#    #+#             */
/*   Updated: 2025/12/17 19:44:49 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Types.h"
#include <iostream>

void displayPseudo(double& base) {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: " << static_cast<float>(base) << "f" << std::endl;
    std::cout << "double: " << base << std::endl;
}

