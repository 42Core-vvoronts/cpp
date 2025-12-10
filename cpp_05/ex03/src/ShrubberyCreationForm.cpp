/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 18:15:00 by vvoronts          #+#    #+#             */
/*   Updated: 2025/12/10 19:18:26 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

static const int shrubberyGradeToSign = 145;
static const int shrubberyGradeToExecute = 137;
static const std::string formName = "ShrubberyCreationForm";
static const std::string filePostfix = "_shrubbery";
static const char* tree = "               ,@@@@@@@,\n"
"       ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
"    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
"   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n"
"   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n"
"   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n"
"   `&%\\ ` /%&'    |.|        \\ '|8'\n"
"       |o|        | |         | |\n"
"       |.|        | |         | |\n"
"jgs \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_\n";

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm(formName, shrubberyGradeToSign, shrubberyGradeToExecute), _target(target) {
}

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm(formName, shrubberyGradeToSign, shrubberyGradeToExecute), _target("default") {
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
	: AForm(src), _target(src._target) {
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src) {
	if (this != &src) {	
		AForm::operator=(src);
		this->_target = src._target;
	}
	return *this;
}

std::string ShrubberyCreationForm::getTarget() const {
	return this->_target;
}

void ShrubberyCreationForm::beExecuted() const {
	std::string filename = this->_target + filePostfix;
	std::ofstream file(filename.c_str());
	if (!file.is_open())
		return;
	
	file << tree << tree << tree;
	file.close();
}
