/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 03:27:32 by vvoronts          #+#    #+#             */
/*   Updated: 2025/11/02 14:43:27 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {
	public: 
		Zombie(void);
		~Zombie(void);
		void announce(void);
		void setName(std::string name);
	private:
		std::string name;
};

Zombie* zombieHorde(int N, std::string name);

#endif