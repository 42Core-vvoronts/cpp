/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:52:38 by vvoronts          #+#    #+#             */
/*   Updated: 2025/12/10 19:48:23 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
	std::cout << "-------------------------------------------------------------------" << std::endl;
	std::cout << "    Intern ()" << std::endl;
	std::cout << "-------------------------------------------------------------------" << std::endl;
	std::cout << "*\n" << std::endl;

	Intern someRandomIntern;
	AForm *rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	if (rrf) {
		Bureaucrat chief("Chief", 1);
		chief.signForm(*rrf);
		chief.executeForm(*rrf);
		delete rrf;
	}
	std::cout << std::endl;

	AForm *shrub = someRandomIntern.makeForm("shrubbery creation", "garden");
	if (shrub) {
		Bureaucrat alice("Alice", 130);
		alice.signForm(*shrub);
		alice.executeForm(*shrub);
		delete shrub;
	}
	std::cout << std::endl;

	AForm *pardon = someRandomIntern.makeForm("presidential pardon", "Ford Prefect");
	if (pardon) {
		Bureaucrat low("LowGuy", 150);
		Bureaucrat high("HighGuy", 2);
		low.signForm(*pardon);
		low.executeForm(*pardon);
		high.signForm(*pardon);
		high.executeForm(*pardon);
		delete pardon;
	}
	std::cout << std::endl;

	AForm *unknown = someRandomIntern.makeForm("unknown form", "Nobody");
	if (unknown)
		delete unknown;

	std::cout << std::endl;

	return 0;
}

