/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   align.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 16:50:13 by vvoronts          #+#    #+#             */
/*   Updated: 2025/09/02 13:16:48 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "PrettyPrint.h"

/**
 * Align string display by width
 * @param str - string to align
 * @param width - width to align to
 *
 * @retval void
 */
void align(std::string str, unsigned int width)
{
	if (str.length() > width)
		std::cout << str.substr(0, 9) << ".|";
	else
		std::cout << std::setw(width) << str << "|";
}
