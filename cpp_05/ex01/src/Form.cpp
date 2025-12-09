/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:42:51 by vvoronts          #+#    #+#             */
/*   Updated: 2025/12/09 18:03:17 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

static const std::string	defaultFormName = "default";
static const bool			defaultIsSigned = false;
static const int			defaultGradeToSign = 150;
static const int			defaultGradeToExecute = 150;
static const int			highestGrade = 1;
static const int			lowestGrade = 150;
static const char*			formGradeTooHighMsg = "Form grade is too high";
static const char*			formGradeTooLowMsg = "Form grade is too low";

Form::Form() : _name(defaultFormName), _isSigned(defaultIsSigned), _gradeToSign(defaultGradeToSign), _gradeToExecute(defaultGradeToExecute) {
}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
	: _name(name), _isSigned(defaultIsSigned), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	verifyGrade(gradeToSign);
	verifyGrade(gradeToExecute);
}

Form::Form(const Form &src)
	: _name(src._name), _isSigned(src._isSigned), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute) {
}

Form::~Form() {
}

Form &Form::operator=(const Form &src) {
	if (this != &src) {
		this->_isSigned = src._isSigned;
	}
	return *this;
}

std::string Form::getName() const {
	return this->_name;
}

bool Form::getIsSigned() const {
	return this->_isSigned;
}

int Form::getGradeToSign() const {
	return this->_gradeToSign;
}

int Form::getGradeToExecute() const {
	return this->_gradeToExecute;
}

void Form::verifyGrade(int grade) {
	if (grade < highestGrade)
		throw Form::GradeTooHighException();
	if (grade > lowestGrade)
		throw Form::GradeTooLowException();
}

void Form::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw Form::GradeTooLowException();
	this->_isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw() {
	return formGradeTooHighMsg;
}

const char* Form::GradeTooLowException::what() const throw() {
	return formGradeTooLowMsg;
}

std::ostream& operator<<(std::ostream& out, const Form& f) {
	out << "Form " << f.getName() << ", signed: ";
	if (f.getIsSigned())
		out << "yes";
	else
		out << "no";
	out << ", grade to sign: " << f.getGradeToSign()
		<< ", grade to execute: " << f.getGradeToExecute();
	return out;
}
