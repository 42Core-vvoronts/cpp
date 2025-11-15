/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 23:47:04 by vvoronts          #+#    #+#             */
/*   Updated: 2025/11/16 00:39:00 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
int main() {
	ClapTrap	clap1("Guy1");
	ClapTrap	clap2 = clap1;
	ClapTrap	clap3("Guy3");
	ClapTrap	clap4("Guy4");

	std::cout << std::endl;
	clap1.showStat();
	clap2.showStat();
	clap3.showStat();
	clap4.showStat();
	std::cout << std::endl;


	clap1.beRepaired(5);
	clap1.attack("Guy3");
	clap3.takeDamage(clap1.getDamage());
	clap4.takeDamage(5);
	clap1.attack("Guy3");
	clap3.takeDamage(clap1.getDamage());
	clap1.attack("Guy3");
	clap3.takeDamage(clap1.getDamage());
	clap1.attack("Guy3");
	clap3.takeDamage(clap1.getDamage());
	clap1.attack("Guy3");
	clap3.takeDamage(clap1.getDamage());
	clap3.beRepaired(5);
	clap4.beRepaired(3);
	clap4.attack("Guy1");
	clap1.takeDamage(clap4.getDamage());
	clap2.attack("Guy4");
	clap4.takeDamage(clap2.getDamage());
	clap3.beRepaired(10);
	
	std::cout << std::endl;
	clap1.showStat();
	clap2.showStat();
	clap3.showStat();
	clap4.showStat();
	std::cout << std::endl;

	return (0);
}