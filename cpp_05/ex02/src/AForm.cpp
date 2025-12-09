/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:42:51 by vvoronts          #+#    #+#             */
/*   Updated: 2025/12/09 18:16:40 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

static const std::string	defaultFormName = "default";
static const bool			defaultIsSigned = false;
static const int			defaultGradeToSign = 150;
static const int			defaultGradeToExecute = 150;
static const int			highestGrade = 1;
static const int			lowestGrade = 150;
static const char*			formGradeTooHighMsg = "AForm grade is too high";
static const char*			formGradeTooLowMsg = "AForm grade is too low";

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute)
	: _name(name), _isSigned(defaultIsSigned), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	verifyGrade(gradeToSign);
	verifyGrade(gradeToExecute);
}

AForm::AForm(const AForm &src)
	: _name(src._name), _isSigned(src._isSigned), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute) {
}

AForm::~AForm() {
}

AForm &AForm::operator=(const AForm &src) {
	if (this != &src) {
		this->_isSigned = src._isSigned;
	}
	return *this;
}

std::string AForm::getName() const {
	return this->_name;
}

bool AForm::getIsSigned() const {
	return this->_isSigned;
}

int AForm::getGradeToSign() const {
	return this->_gradeToSign;
}

int AForm::getGradeToExecute() const {
	return this->_gradeToExecute;
}

void AForm::verifyGrade(int grade) {
	if (grade < highestGrade)
		throw AForm::GradeTooHighException();
	if (grade > lowestGrade)
		throw AForm::GradeTooLowException();
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw AForm::GradeTooLowException();
	this->_isSigned = true;
}

const char* AForm::GradeTooHighException::what() const throw() {
	return formGradeTooHighMsg;
}

const char* AForm::GradeTooLowException::what() const throw() {
	return formGradeTooLowMsg;
}

std::ostream& operator<<(std::ostream& out, const AForm& f) {
	out << "AForm " << f.getName() << ", signed: ";
	if (f.getIsSigned())
		out << "yes";
	else
		out << "no";
	out << ", grade to sign: " << f.getGradeToSign()
		<< ", grade to execute: " << f.getGradeToExecute();
	return out;
}
