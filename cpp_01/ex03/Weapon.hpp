/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 15:24:21 by vvoronts          #+#    #+#             */
/*   Updated: 2025/11/02 14:42:15 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <string>

/**
 * @class Weapon
 * @brief Represents a weapon with a type
 *
 * Getters and setters for the weapon type
 */
class Weapon {
	public:
		Weapon(std::string weaponType);
		~Weapon();
		std::string const&	getType();
		void				setType(std::string weaponType);
	private:
		std::string _weapon;
};

#endif