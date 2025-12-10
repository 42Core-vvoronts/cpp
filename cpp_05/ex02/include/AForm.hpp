/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:42:54 by vvoronts          #+#    #+#             */
/*   Updated: 2025/12/10 19:14:39 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP
# include <string>

class Bureaucrat;

class AForm {
	public:
		AForm();
		AForm(const AForm &src);
		AForm(const std::string &name, unsigned int gradeToSign, unsigned int gradeToExecute);
		virtual ~AForm();

		AForm &operator=(const AForm &src);

		std::string			getName() const;
		bool				isSigned() const;
		unsigned int		getGradeRequiredToSign() const;
		unsigned int		getGradeRequiredToExecute() const;

		void				beSigned(Bureaucrat &bureaucrat);
		void				execute(const Bureaucrat &executor) const;

		class GradeTooHighException : public std::exception {
			virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			virtual const char* what() const throw();
		};
		class AlreadySignedException : public std::exception {
			virtual const char* what() const throw();
		};
		class NotSignedException : public std::exception {
			virtual const char* what() const throw();
		};

	private:
		const std::string	_name;
		const unsigned int	_gradeRequiredToSign;
		const unsigned int	_gradeRequiredToExecute;
		bool				_isSigned;

		void				confirmValidGrade(unsigned int grade);
		virtual void		beExecuted() const = 0;
};

std::ostream& operator<<(std::ostream& out, const AForm& f);

#endif