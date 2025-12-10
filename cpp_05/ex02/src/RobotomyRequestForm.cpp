/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 18:15:00 by vvoronts          #+#    #+#             */
/*   Updated: 2025/12/10 17:57:40 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

static const unsigned int robotomyGradeToSign = 72;
static const unsigned int robotomyGradeToExecute = 45;
static const std::string drillingNoise = "[o_o]...bzzzbzzzbzzzz";
static const std::string formName = "RobotomyRequestForm";
static const std::string successMessage = " has been robotomized successfully";
static const std::string failureMessage = " failed to be robotomized";

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm(formName, robotomyGradeToSign, robotomyGradeToExecute), _target(target) {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
	: AForm(src), _target(src._target) {
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src) {
	AForm::operator=(src);
	return *this;
}

std::string RobotomyRequestForm::getTarget() const {
	return this->_target;
}

void RobotomyRequestForm::beExecuted() const {
	std::cout << drillingNoise << std::endl;
	
	if (std::rand() % 2 == 0)
		std::cout << this->_target << successMessage << std::endl;
	else
		std::cout << this->_target << failureMessage << std::endl;
}
