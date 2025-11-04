/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 11:04:57 by vvoronts          #+#    #+#             */
/*   Updated: 2025/11/04 11:15:30 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <string>
#include <iostream>

Harl::Harl(){
	std::cout << "...Harl Constructor" << std::endl;
}

Harl::~Harl(){
	std::cout << "...Harl Destructor" << std::endl;
}

/**
 * @param level The level of complaint
 * @brief Calls the method based on the level
 *
 * The goal of this exercise is to use pointers to member functions
 */
void Harl::complain(std::string level)
{
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i = 0;
	void (Harl::*fptr[]) (void) = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	if (i == 4)
		std::cout << "Error! Wrong level of instruction." << std::endl;

	while (i < 4){
		if (level == levels[i])
		{
			(this->*fptr[i])();
			break ;
		}
		i++;
	}
}

void Harl::debug(void){
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info(void){
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void){
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
}

void Harl::error(void){
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}