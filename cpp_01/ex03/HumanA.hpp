/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 15:38:49 by vvoronts          #+#    #+#             */
/*   Updated: 2025/11/02 14:40:09 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP
# include <string>
# include "Weapon.hpp"

/**
 * @class HumanA
 * @brief Represents a human that always has a weapon
 
 * As reference because it can't be null or reassigned
 */
class HumanA {
	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA();
		void attack();
	
	private:
		std::string _name;
		Weapon &_weapon;
};

#endif