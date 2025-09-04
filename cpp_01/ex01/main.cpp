/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 03:35:26 by vvoronts          #+#    #+#             */
/*   Updated: 2025/09/05 05:07:18 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	std::string	name;
	Zombie		*myHorde;
	int			horde_size;

	name = "Zombie";
	horde_size = 5;
	myHorde = zombieHorde(horde_size, name);
	for (int i = 0; i < horde_size; i++)
		myHorde[i].announce();

	delete[] myHorde;
	return 0;
}