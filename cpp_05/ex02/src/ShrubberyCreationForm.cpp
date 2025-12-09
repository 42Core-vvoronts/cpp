/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 18:15:00 by vvoronts          #+#    #+#             */
/*   Updated: 2025/12/09 18:16:40 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

static const int shrubberyGradeToSign = 145;
static const int shrubberyGradeToExecute = 137;
static const char* tree = "    *\n   ***\n  *****\n *******\n*********\n   ***\n   ***\n";

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("ShrubberyCreationForm", shrubberyGradeToSign, shrubberyGradeToExecute), _target(target) {
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
	: AForm(src), _target(src._target) {
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src) {
	AForm::operator=(src);
	return *this;
}

std::string ShrubberyCreationForm::getTarget() const {
	return this->_target;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
	if (!this->getIsSigned())
		throw AForm::GradeTooLowException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	
	std::string filename = this->_target + "_shrubbery";
	std::ofstream file(filename.c_str());
	if (!file.is_open())
		return;
	
	file << tree << tree << tree;
	file.close();
}
