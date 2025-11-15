/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 01:27:44 by vvoronts          #+#    #+#             */
/*   Updated: 2025/11/16 01:38:14 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	std::cout << "...Constructor for FragTrap " << this->_name << " called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::~FragTrap() {
	std::cout << "...Destructor for FragTrap " << this->_name << " called" << std::endl;
} 

FragTrap::FragTrap(const FragTrap &source) : ClapTrap(source) {
	std::cout << "...Copy constructor FragTrap called" << std::endl;
	*this = source;
}

FragTrap& FragTrap::operator=(FragTrap const &src) {
	std::cout << "...Assignment operator called for FragTrap" << std::endl;
	
	ClapTrap::operator=(src);

	this->_name = src._name;
	this->_hitPoints = src._hitPoints;
	this->_energyPoints = src._energyPoints;
	this->_attackDamage = src._attackDamage;

	return (*this);
}


void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap: High-fives guys" << std::endl;
}
