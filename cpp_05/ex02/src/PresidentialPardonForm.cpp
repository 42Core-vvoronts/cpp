/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 18:15:00 by vvoronts          #+#    #+#             */
/*   Updated: 2025/12/10 19:19:00 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

static const int presidentialGradeToSign = 25;
static const int presidentialGradeToExecute = 5;
static const std::string formName = "PresidentialPardonForm";
static const std::string pardonMessage = " has been pardoned by Zaphod Beeblebrox";


PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	: AForm(formName, presidentialGradeToSign, presidentialGradeToExecute), _target(target) {
}

PresidentialPardonForm::PresidentialPardonForm()
	: AForm(formName, presidentialGradeToSign, presidentialGradeToExecute), _target("default") {
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src)
	: AForm(src), _target(src._target) {
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src) {
	if (this != &src) {	
		AForm::operator=(src);
		this->_target = src._target;
	}
	return *this;
}

std::string PresidentialPardonForm::getTarget() const {
	return this->_target;
}

void PresidentialPardonForm::beExecuted() const {
	std::cout << this->_target << pardonMessage << std::endl;
}
