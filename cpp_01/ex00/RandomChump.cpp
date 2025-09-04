/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RandomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 04:01:15 by vvoronts          #+#    #+#             */
/*   Updated: 2025/09/05 04:01:51 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

//stack allocated zombie
void randomChump(std::string name)
{
	Zombie zombie(name);
	zombie.announce();
}
