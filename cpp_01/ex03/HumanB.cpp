/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 16:04:12 by vvoronts          #+#    #+#             */
/*   Updated: 2025/11/02 14:23:04 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name) {
	std::cout << "...HumanB Constructor" << std::endl;
	this->_weapon = 0;
}

HumanB::~HumanB(){
	std::cout << "...HumanB Destructor" << std::endl;
}

void HumanB::attack(){
	if (this->_weapon)
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
	else
		std::cout << this->_name << " is not armed" << std::endl;
}

void HumanB::setWeapon(Weapon &weapon){
	this->_weapon = &weapon;
}