/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 23:47:04 by vvoronts          #+#    #+#             */
/*   Updated: 2025/11/16 01:35:51 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main() {
	ClapTrap	clap1("ClapGuy1");
	ClapTrap	clap2("ClapGuy2");
	ScavTrap	scav3("ScavGuy3");
	ScavTrap	scav4("ScavGuy4");
	FragTrap	frag5("FragGuy5");
	FragTrap	frag6("FragGuy6");

	std::cout << std::endl;
	clap1.showStat();
	clap2.showStat();
	scav3.showStat();
	scav4.showStat();
	frag5.showStat();
	frag6.showStat();
	std::cout << std::endl;

	clap1.attack(clap2.getName());
	clap2.takeDamage(clap1.getDamage());
	scav3.attack(scav4.getName());
	scav4.takeDamage(scav3.getDamage());
	clap1.beRepaired(5);
	scav3.beRepaired(10);
	scav4.guardGate();
	clap2.attack(clap1.getName());
	frag5.attack(frag6.getName());
	frag6.takeDamage(frag5.getDamage());
	frag6.highFivesGuys();
	frag5.beRepaired(5);
	frag6.attack(frag5.getName());
	frag5.takeDamage(frag6.getDamage());
	frag5.attack(frag6.getName());
	// frag6.guardGate();
	frag6.attack(frag5.getName());
	frag5.takeDamage(frag6.getDamage());
	
	
	std::cout << std::endl;
	clap1.showStat();
	clap2.showStat();
	scav3.showStat();
	scav4.showStat();
	frag5.showStat();
	frag6.showStat();
	std::cout << std::endl;

	return (0);
}