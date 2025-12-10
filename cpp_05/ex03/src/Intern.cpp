/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 19:40:00 by vvoronts          #+#    #+#             */
/*   Updated: 2025/12/10 19:57:57 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

// Local helper creators to avoid big if/else chains
static AForm *createShrubbery(const std::string &target) {
	return new ShrubberyCreationForm(target);
}

static AForm *createRobotomy(const std::string &target) {
	return new RobotomyRequestForm(target);
}

static AForm *createPardon(const std::string &target) {
	return new PresidentialPardonForm(target);
}

const char * Intern::InvalidFormName::what() const throw() {
	return "Intern Error: Invalid form name";
}

Intern::Intern() {}
Intern::~Intern() {}
Intern::Intern(const Intern &src) { (void)src; }
Intern &Intern::operator=(const Intern &src) { (void)src; return *this; }

AForm *Intern::makeForm(const std::string &formName, const std::string &target) const {
	const std::string names[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	AForm *(*creators[3])(const std::string &) = { createShrubbery, createRobotomy, createPardon };

	for (int i = 0; i < 3; ++i) {
		if (formName == names[i]) {
			std::cout << "Intern creates " << formName << std::endl;
			return creators[i](target);
		}
	}
	throw InvalidFormName();
}
