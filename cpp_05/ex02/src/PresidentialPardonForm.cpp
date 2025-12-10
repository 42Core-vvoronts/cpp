/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 18:15:00 by vvoronts          #+#    #+#             */
/*   Updated: 2025/12/10 17:17:31 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

static const unsigned int presidentialGradeToSign = 25;
static const unsigned int presidentialGradeToExecute = 5;

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	: AForm("PresidentialPardonForm", presidentialGradeToSign, presidentialGradeToExecute), _target(target) {
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src)
	: AForm(src), _target(src._target) {
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src) {
	AForm::operator=(src);
	return *this;
}

std::string PresidentialPardonForm::getTarget() const {
	return this->_target;
}

void PresidentialPardonForm::beExecuted() const {
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
