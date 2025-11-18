/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 16:26:23 by vvoronts          #+#    #+#             */
/*   Updated: 2025/09/28 15:37:20 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string* stringPTR = &str;
	std::string& stringREF = str;

	std::cout << "Memory address of string: " << &str;
	std::cout <<"\nMemory address held by stringPTR: " << stringPTR;
	std::cout << "\nMemory address held by stringREF: " << &stringREF;

	std::cout << "\n\nValue of string variable: " << str;
	std::cout << "\nValue pointed to by stringPTR: " << *stringPTR;
	std::cout << "\nValue pointed to by stringREF: " << stringREF << std::endl;
	return 0;
}
