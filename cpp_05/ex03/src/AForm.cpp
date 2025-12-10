/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:42:51 by vvoronts          #+#    #+#             */
/*   Updated: 2025/12/10 17:52:03 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

static const std::string	defaultFormName = "default";
static const bool			defaultIsSigned = false;
static const unsigned int	defaultGradeToSign = 150;
static const unsigned int	defaultGradeToExecute = 150;
static const unsigned int	highestGrade = 1;
static const unsigned int	lowestGrade = 150;
static const char*			formGradeTooHighMsg = "grade is too high";
static const char*			formGradeTooLowMsg = "grade is too low";
static const char*			formAlreadySignedMsg = "form is already signed";
static const char*			formNotSignedMsg = "form is not signed";

AForm::AForm()
	: _name(defaultFormName), _gradeRequiredToSign(defaultGradeToSign), 
	  _gradeRequiredToExecute(defaultGradeToExecute), _isSigned(defaultIsSigned) {
}

AForm::AForm(const std::string &name, unsigned int gradeToSign, unsigned int gradeToExecute)
	: _name(name), _gradeRequiredToSign(gradeToSign), 
	  _gradeRequiredToExecute(gradeToExecute), _isSigned(defaultIsSigned) {
	confirmValidGrade(gradeToSign);
	confirmValidGrade(gradeToExecute);
}

AForm::AForm(const AForm &src)
	: _name(src._name), _gradeRequiredToSign(src._gradeRequiredToSign), 
	  _gradeRequiredToExecute(src._gradeRequiredToExecute), _isSigned(src._isSigned) {
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

bool AForm::isSigned() const {
	return this->_isSigned;
}

unsigned int AForm::getGradeRequiredToSign() const {
	return this->_gradeRequiredToSign;
}

unsigned int AForm::getGradeRequiredToExecute() const {
	return this->_gradeRequiredToExecute;
}

void AForm::confirmValidGrade(unsigned int grade) {
	if (grade < highestGrade)
		throw AForm::GradeTooHighException();
	if (grade > lowestGrade)
		throw AForm::GradeTooLowException();
}

void AForm::beSigned(Bureaucrat &bureaucrat) {
	if (this->_isSigned)
		throw AForm::AlreadySignedException();
	if (bureaucrat.getGrade() > this->_gradeRequiredToSign)
		throw AForm::GradeTooLowException();
	this->_isSigned = true;
}

void AForm::execute(const Bureaucrat &executor) const {
	if (!this->_isSigned)
		throw AForm::NotSignedException();
	if (executor.getGrade() > this->_gradeRequiredToExecute)
		throw AForm::GradeTooLowException();
	this->beExecuted();
}

const char* AForm::GradeTooHighException::what() const throw() {
	return formGradeTooHighMsg;
}

const char* AForm::GradeTooLowException::what() const throw() {
	return formGradeTooLowMsg;
}

const char* AForm::AlreadySignedException::what() const throw() {
	return formAlreadySignedMsg;
}

const char* AForm::NotSignedException::what() const throw() {
	return formNotSignedMsg;
}

std::ostream& operator<<(std::ostream& out, const AForm& f) {
	out << "AForm " << f.getName() << ", signed: ";
	if (f.isSigned())
		out << "yes";
	else
		out << "no";
	out << ", grade to sign: " << f.getGradeRequiredToSign()
		<< ", grade to execute: " << f.getGradeRequiredToExecute();
	return out;
}

