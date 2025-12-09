/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:52:38 by vvoronts          #+#    #+#             */
/*   Updated: 2025/12/09 18:27:48 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	std::cout << "=== Test 1: ShrubberyCreationForm success ===" << std::endl;
	try {
		ShrubberyCreationForm shrubbery("garden");
		Bureaucrat alice("Alice", 137);
		std::cout << "Alice grade: " << alice.getGrade() << std::endl;
		alice.signForm(shrubbery);
		alice.executeForm(shrubbery);
	} catch (const std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 2: ShrubberyCreationForm execution fails (not signed) ===" << std::endl;
	try {
		ShrubberyCreationForm tree("forest");
		Bureaucrat bob("Bob", 137);
		std::cout << "Bob grade: " << bob.getGrade() << std::endl;
		bob.executeForm(tree);
	} catch (const std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 3: ShrubberyCreationForm signing fails (grade too low) ===" << std::endl;
	try {
		ShrubberyCreationForm park("park");
		Bureaucrat charlie("Charlie", 150);
		std::cout << "Charlie grade: " << charlie.getGrade() << std::endl;
		charlie.signForm(park);
	} catch (const std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 4: RobotomyRequestForm with multiple executions ===" << std::endl;
	try {
		RobotomyRequestForm robotomy1("Alice");
		RobotomyRequestForm robotomy2("Bob");
		RobotomyRequestForm robotomy3("Charlie");
		Bureaucrat david("David", 45);
		
		std::cout << "David grade: " << david.getGrade() << std::endl;
		david.signForm(robotomy1);
		david.signForm(robotomy2);
		david.signForm(robotomy3);
		
		david.executeForm(robotomy1);
		david.executeForm(robotomy2);
		david.executeForm(robotomy3);
	} catch (const std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 5: RobotomyRequestForm execution fails (grade too low) ===" << std::endl;
	try {
		RobotomyRequestForm robotomy("Target");
		Bureaucrat eve("Eve", 72);
		std::cout << "Eve grade: " << eve.getGrade() << std::endl;
		eve.signForm(robotomy);
		eve.executeForm(robotomy);
	} catch (const std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 6: PresidentialPardonForm success ===" << std::endl;
	try {
		PresidentialPardonForm pardon("Alice");
		Bureaucrat frank("Frank", 5);
		std::cout << "Frank grade: " << frank.getGrade() << std::endl;
		frank.signForm(pardon);
		frank.executeForm(pardon);
	} catch (const std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 7: PresidentialPardonForm signing fails (grade too low) ===" << std::endl;
	try {
		PresidentialPardonForm pardon("Bob");
		Bureaucrat grace("Grace", 150);
		std::cout << "Grace grade: " << grace.getGrade() << std::endl;
		grace.signForm(pardon);
	} catch (const std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 8: Multiple bureaucrats with different grades ===" << std::endl;
	try {
		ShrubberyCreationForm shrub("test");
		RobotomyRequestForm robot("target");
		PresidentialPardonForm pres("criminal");
		
		Bureaucrat intern("Intern", 150);
		Bureaucrat manager("Manager", 45);
		Bureaucrat ceo("CEO", 1);
		
		std::cout << "Intern grade: " << intern.getGrade() << std::endl;
		intern.signForm(shrub);
		
		std::cout << "\nManager grade: " << manager.getGrade() << std::endl;
		manager.signForm(shrub);
		manager.signForm(robot);
		manager.signForm(pres);
		
		std::cout << "\nCEO grade: " << ceo.getGrade() << std::endl;
		ceo.signForm(shrub);
		ceo.signForm(robot);
		ceo.signForm(pres);
		
		ceo.executeForm(shrub);
		ceo.executeForm(robot);
		ceo.executeForm(pres);
	} catch (const std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 9: Boundary grades (1 and 150) ===" << std::endl;
	try {
		ShrubberyCreationForm highShrub("high");
		ShrubberyCreationForm lowShrub("low");
		PresidentialPardonForm highPardon("high_target");
		PresidentialPardonForm lowPardon("low_target");
		
		Bureaucrat topBoss("Top Boss", 1);
		Bureaucrat lowWorker("Low Worker", 150);
		
		std::cout << "Top Boss grade: " << topBoss.getGrade() << std::endl;
		topBoss.signForm(highShrub);
		topBoss.signForm(lowShrub);
		topBoss.signForm(highPardon);
		topBoss.signForm(lowPardon);
		
		topBoss.executeForm(highShrub);
		topBoss.executeForm(lowShrub);
		topBoss.executeForm(highPardon);
		topBoss.executeForm(lowPardon);
		
		std::cout << "\nLow Worker grade: " << lowWorker.getGrade() << std::endl;
		lowWorker.signForm(lowPardon);
	} catch (const std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}

