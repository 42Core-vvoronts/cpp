/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 03:27:32 by vvoronts          #+#    #+#             */
/*   Updated: 2025/09/05 04:48:40 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>


class Zombie
{
public: 
	Zombie(std::string name);
	~Zombie(void);

	void announce(void);
private:
	std::string name;	
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif