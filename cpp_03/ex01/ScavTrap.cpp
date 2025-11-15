/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 00:45:45 by vvoronts          #+#    #+#             */
/*   Updated: 2025/11/16 01:24:48 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	std::cout << "...Constructor for ScavTrap " << this->_name << " called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::~ScavTrap() {
	std::cout << "...Destructor for ScavTrap " << this->_name << " called\033[0m" << std::endl;
} 

ScavTrap::ScavTrap(const ScavTrap &source) : ClapTrap(source) {
	std::cout << "...Copy constructor ScavTrap called" << std::endl;
	*this = source;
}

ScavTrap& ScavTrap::operator=(ScavTrap const &src) {
	std::cout << "...Assignment operator called for ScavTrap" << std::endl;
	
	ClapTrap::operator=(src);

	this->_name = src._name;
	this->_hitPoints = src._hitPoints;
	this->_energyPoints = src._energyPoints;
	this->_attackDamage = src._attackDamage;

	return (*this);
}

void ScavTrap::attack(const std::string &target) {
	if (this->_energyPoints <= 0)
	{
		std::cout << "ScavTrap: " << this->_name << " can't attack, not enough energy points!" << std::endl;
		this->_attackDamage = -1;
	}
	else if (this->_hitPoints <= 0)
	{
		std::cout << "ScavTrap: " << this->_name << " can't attack, not enough hit points!" << std::endl;
		this->_attackDamage = -1;
	}
	else if (this->_attackDamage == 0)
		std::cout << "ScavTrap: " << this->_name << " attacks with no damage!" << std::endl;
		else
	{
		std::cout << "ScavTrap: " << this->_name << " attacks " << target << " causing " << this->_attackDamage << " points of damage!" << std::endl; 
		this->_energyPoints -= 1;
	}
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap: " << this->_name << " is now in Gatekeeper mode" << std::endl;
}