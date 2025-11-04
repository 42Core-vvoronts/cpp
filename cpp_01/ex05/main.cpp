/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 03:35:26 by vvoronts          #+#    #+#             */
/*   Updated: 2025/11/04 11:19:17 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

/**
 * @brief Testing levels
 */
int	main(void)
{
	Harl harl;

	std::cout << "-Debug level: " << std::endl;
	harl.complain("DEBUG");
	std::cout << "\n-Info level: " << std::endl;
	harl.complain("INFO");
	std::cout << "\n-Warning level: " << std::endl;
	harl.complain("WARNING");
	std::cout << "\n-Error level: " << std::endl;
	harl.complain("ERROR");
	std::cout << "\n-Invalid level: " << std::endl;
	harl.complain("INVALIDSTRING");
	std::cout << "\n-Empty level: " << std::endl;
	harl.complain("");
	std::cout << std::endl;
	return (0);
}
