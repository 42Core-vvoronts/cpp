/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 23:47:04 by vvoronts          #+#    #+#             */
/*   Updated: 2025/11/16 01:00:51 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
	ClapTrap	clap1("ClapGuy1");
	ClapTrap	clap2("ClapGuy2");
	ScavTrap	scav3("ScavGuy3");
	ScavTrap	scav4("ScavGuy4");

	std::cout << std::endl;
	clap1.showStat();
	clap2.showStat();
	scav3.showStat();
	scav4.showStat();
	std::cout << std::endl;

	clap1.attack(clap2.getName());
	clap2.takeDamage(clap1.getDamage());
	scav3.attack(scav4.getName());
	scav4.takeDamage(scav3.getDamage());
	clap1.beRepaired(5);
	scav3.beRepaired(10);
	scav4.guardGate();
	clap2.attack(clap1.getName());
	
	
	std::cout << std::endl;
	clap1.showStat();
	clap2.showStat();
	scav3.showStat();
	scav4.showStat();
	std::cout << std::endl;

	return (0);
}