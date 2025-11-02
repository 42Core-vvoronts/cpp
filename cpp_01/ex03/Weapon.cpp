/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 13:56:21 by vvoronts          #+#    #+#             */
/*   Updated: 2025/11/02 14:18:48 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 13:56:21 by vvoronts          #+#    #+#             */
/*   Updated: 2025/11/02 14:20:00 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <string>
#include <iostream>

Weapon::Weapon(std::string weaponType) : _weapon(weaponType) {
	std::cout << "...Weapon Constructor" << std::endl;
}

Weapon::~Weapon(){
	std::cout << "...Weapon Destructor" << std::endl;
}

std::string const &Weapon::getType(){
	return (this->_weapon);
}


void Weapon::setType(std::string weaponType){
	this->_weapon = weaponType;
}