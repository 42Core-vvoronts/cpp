/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:58:52 by vvoronts          #+#    #+#             */
/*   Updated: 2025/12/10 17:30:19 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <string>
#include <iostream>

static const std::string		defaultName = "Noname";
static const unsigned int		defaultGrade = Bureaucrat::lowestGrade;
static const std::string		incrementMsg = " grade incremented";
static const std::string		decrementMsg = " grade decremented";
static const std::string		outGradeMsg = ", bureaucrat grade ";
static const char*				gradeTooHighMsg = "Grade is too high";
static const char*				gradeTooLowMsg = "Grade is too low";

void	Bureaucrat::verifyGrade(unsigned int grade) {
	if (grade < Bureaucrat::highestGrade)
		throw GradeTooHighException();
	if (grade > Bureaucrat::lowestGrade)
		throw GradeTooLowException();
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return (gradeTooHighMsg);
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return (gradeTooLowMsg);
}

// Canonical Form
Bureaucrat::Bureaucrat() : _name(defaultName), _grade(defaultGrade) {}
Bureaucrat::~Bureaucrat() {}
Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src._name), _grade(src._grade) {}
Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : _name(name), _grade(grade) {
	verifyGrade(_grade);
}
// Assignment Operator
Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &src) {
	if (this != &src) {
		this->_grade = src._grade;
		//  _name is const and cannot be assigned
	}
	return (*this);
}

// Getters, Setters
std::string	Bureaucrat::getName() const { return (this->_name); }
unsigned int	Bureaucrat::getGrade() const { return (this->_grade); }

/*
Remember, since grade 1 is the highest and 150 the lowest,
incrementing a grade 3 should result in a grade 2 for the bureaucrat
*/
void	Bureaucrat::incrementGrade() {
	this->_grade--;
	verifyGrade(this->_grade);
	std::cout << this->_name << incrementMsg << std::endl;
}

void	Bureaucrat::decrementGrade() {
	this->_grade++;
	verifyGrade(this->_grade);
	std::cout << this->_name << decrementMsg << std::endl;
}

void	Bureaucrat::signForm(AForm &form) {
	try {
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	} catch (std::exception &e) {
		std::cout << this->_name << " couldn't sign " << form.getName()
				  << " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(const AForm &form) const {
	try {
		form.execute(*this);
		std::cout << this->_name << " executed " << form.getName() << std::endl;
	} catch (std::exception &e) {
		std::cout << this->_name << " couldn't execute " << form.getName()
				  << " because " << e.what() << std::endl;
	}
}

// <name>, bureaucrat grade <grade>.
std::ostream& operator<<(std::ostream& out, const Bureaucrat& b){
	return out << b.getName() << outGradeMsg << b.getGrade() << ".";
}