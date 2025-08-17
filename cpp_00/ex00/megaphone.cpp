/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 18:49:44 by vvoronts          #+#    #+#             */
/*   Updated: 2025/08/17 14:10:39 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

void convert_to_upper(char **argv, int argc)
{
	for (int i = 1; i < argc; i++)
	{
		for (char *c = argv[i]; *c != '\0'; c++)
			std::cout << (char)std::toupper(*c);
	}
}

int main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
		convert_to_upper(argv, argc);
	std::cout << std::endl;
	return 0;
}
