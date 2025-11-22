/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 19:51:32 by vvoronts          #+#    #+#             */
/*   Updated: 2025/11/22 17:19:30 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << "...Brain constructor called." << std::endl;
	const std::string default_ideas[] = {
		"ZzzZzz...",
		"Play",
		"Go for a walk",
		".....",
		"Food",
		"Hmmm...", 
		"blabla"
	};
	
	// Initialize all 100 ideas cycling through the defaults
	for (int i = 0; i < 100; ++i) {
		this->_ideas[i] = default_ideas[i % 7];
	}
}

Brain::Brain(const Brain& src) {
	for (int i = 0; i < 100; i++) {
		this->_ideas[i] = src.getIdea(i);
	}
	std::cout << "...Brain Copy Constructor" << std::endl;
}

Brain& Brain::operator=(const Brain &src) {
	std::cout << "Brain copy assignment operator called" << std::endl;
	
	if (this != &src)
	{
		for (int i = 0; i < 100; i++) {
			this->_ideas[i] = src.getIdea(i);
		}
	}
	return *this;
}

Brain::~Brain(){
	std::cout << "...Brain destructor called." << std::endl;
}

const std::string& Brain::getIdea(unsigned int index) const {
	return this->_ideas[index % 100];
}
