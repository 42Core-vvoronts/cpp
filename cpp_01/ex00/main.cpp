/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 03:35:26 by vvoronts          #+#    #+#             */
/*   Updated: 2025/09/05 04:03:55 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie* zombieHeap = newZombie("Heap guy");
	zombieHeap->announce();
	delete zombieHeap;

	randomChump("Stack guy");
	return 0;
}