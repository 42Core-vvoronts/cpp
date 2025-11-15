/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 23:47:02 by vvoronts          #+#    #+#             */
/*   Updated: 2025/11/16 00:33:46 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(std::string name) : _name (name), _hitPoints (10), _energyPoints (10), _attackDamage (0) {
	std::cout << "...Default Constructor " << this->_name << " called" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "...Destructor for ClapTrap " << this->_name << " called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &source) {
	std::cout << "...Copy constructor ClapTrap called" << std::endl;
	*this = source;
}

ClapTrap& ClapTrap::operator=(ClapTrap const &src) {
	std::cout << "...Assignment operator called" << std::endl;

	this->_name = src._name;
	this->_hitPoints = src._hitPoints;
	this->_energyPoints = src._energyPoints;
	this->_attackDamage = src._attackDamage;

	return (*this);
}

std::string ClapTrap::getName() {
	return (this->_name);
}

int ClapTrap::getDamage(){
	return (this->_attackDamage);
}


void ClapTrap::attack(const std::string &target){
	if (this->_energyPoints <= 0)
	{
		std::cout << "ClapTrap: " << this->_name << " can't attack due to lack of energy points!" << std::endl;
		this->_attackDamage = -1;
	}
	else if (this->_hitPoints <= 0)
	{
		std::cout << "ClapTrap: " << this->_name << " can't attack because it is out of hit points!" << std::endl;
		this->_attackDamage = -1;
	}
	else if (this->_attackDamage == 0)
		std::cout << "ClapTrap: " << this->_name << " attacks with no damage!" << std::endl;
	else
	{
		std::cout << "ClapTrap: " << this->_name << " attacks " << target << " causing " << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints -= 1;
		std::cout << "ClapTrap: " << this->_name << " has " << this->_energyPoints << " energy points" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount){
	if (this->_hitPoints > 0 && amount > 0)
	{
		std::cout << "ClapTrap: " << this->_name << " tooks " << amount << " points of damage" << std::endl;
		this->_hitPoints -= amount;
		if (this->_hitPoints < 0)
			std::cout << "ClapTrap: " << this->_name << " died!" << std::endl;
		else
			std::cout << "ClapTrap: " << this->_name << " has " << this->_hitPoints << " hit points" << std::endl;
	}
	else if (this->_hitPoints <= 0)
		std::cout << "ClapTrap: " << this->_name << "already dead" << std::endl;
	else if (amount <= 0)
		std::cout << "ClapTrap: " << this->_name << " can't take zero or negative damage" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->_energyPoints <= 0)
		std::cout << "ClapTrap: " << this->_name << " can't repair, not enough energy points" << std::endl;
	else {
		std::cout << "ClapTrap: " << this->_name << " repaired with " << amount << " points" << std::endl;
		this->_energyPoints -= 1;
		this->_hitPoints += amount;
	}
}

void ClapTrap::showStat()
{
	std::cout << "Stat ";
	std::cout << this->_name << ": ";
	std::cout << " hit: " << this->_hitPoints << ",";
	std::cout << " energy : " << this->_energyPoints << std::endl;
}