/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:52:38 by vvoronts          #+#    #+#             */
/*   Updated: 2025/12/10 18:22:14 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	std::cout << "-------------------------------------------------------------------" << std::endl;
	std::cout << "    ShrubberyCreationForm (Required grades: sign 145, exec 137) " << std::endl;
	std::cout << "-------------------------------------------------------------------" << std::endl;
	std::cout << "*Creates a file <target>_shrubbery in the working directory and writes ASCII trees inside it.\n" << std::endl;

	ShrubberyCreationForm shurb1("first");
	std::cout << shurb1 << std::endl;
	Bureaucrat alice("Alice", 137);
	std::cout << "Alice grade: " << alice.getGrade() << std::endl;
	alice.signForm(shurb1);
	alice.executeForm(shurb1);
	std::cout << std::endl;

	ShrubberyCreationForm shurb2("second");
	Bureaucrat bob("Bob", 145);
	std::cout << "Bob grade: " << bob.getGrade() << std::endl;
	bob.signForm(shurb2);
	bob.executeForm(shurb2);
	std::cout << std::endl;

	ShrubberyCreationForm park("third");
	Bureaucrat charlie("Charlie", 150);
	std::cout << "Charlie grade: " << charlie.getGrade() << std::endl;
	charlie.signForm(park);
	charlie.executeForm(park);
	std::cout << std::endl;

	ShrubberyCreationForm park2("fourth");
	Bureaucrat sara("Sara", 1);
	std::cout << "Sara grade: " << sara.getGrade() << std::endl;
	sara.signForm(park2);
	sara.executeForm(park2);

	std::cout << std::endl;
	std::cout << "-------------------------------------------------------------------" << std::endl;
	std::cout << "    RobotomyRequestForm (Required grades: sign 72, exec 45)" << std::endl;
	std::cout << "-------------------------------------------------------------------" << std::endl;
	std::cout << "*Makes some drilling noises, then informs that <target> \nhas been robotomized successfully 50% of the time. Otherwise, it informs that the robotomy failed.\n" << std::endl;

	RobotomyRequestForm robot1("Alice");
	Bureaucrat eve("Bob", 45);
	std::cout << "Bob grade: " << eve.getGrade() << std::endl;
	eve.signForm(robot1);
	eve.executeForm(robot1);
	std::cout << std::endl;

	RobotomyRequestForm robot2("Charlie");
	Bureaucrat frank("Sara", 72);
	std::cout << "Sara grade: " << frank.getGrade() << std::endl;
	frank.signForm(robot2);
	frank.executeForm(robot2);
	std::cout << std::endl;

	RobotomyRequestForm robot3("RandomTarget");
	Bureaucrat randomBureaucrat("RandomBureaucrat", 1);
	std::cout << "RandomBureaucrat grade: " << randomBureaucrat.getGrade() << std::endl;
	randomBureaucrat.signForm(robot3);
	randomBureaucrat.executeForm(robot3);
	std::cout << std::endl;

	std::cout << "-------------------------------------------------------------------" << std::endl;
	std::cout << "    PresidentialPardonForm (Required grades: sign 25, exec 5)" << std::endl;
	std::cout << "-------------------------------------------------------------------" << std::endl;
	std::cout << "*Informs that <target> has been pardoned by Zaphod Beeblebrox.\n" << std::endl;

	PresidentialPardonForm pardon("Alice");
	Bureaucrat stieve("Stieve", 5);
	std::cout << "Stieve grade: " << stieve.getGrade() << std::endl;
	stieve.signForm(pardon);
	stieve.executeForm(pardon);
	std::cout << std::endl;

	PresidentialPardonForm pardon2("Charlie");
	Bureaucrat alex("Alex", 150);
	std::cout << "Alex grade: " << alex.getGrade() << std::endl;
	alex.signForm(pardon2);
	alex.executeForm(pardon2);
	std::cout << std::endl;

	PresidentialPardonForm pardon3("Sara");
	Bureaucrat paul("Paul", 1);
	std::cout << "Paul grade: " << paul.getGrade() << std::endl;
	paul.signForm(pardon3);
	paul.executeForm(pardon3);
	std::cout << std::endl;

	return 0;
}

