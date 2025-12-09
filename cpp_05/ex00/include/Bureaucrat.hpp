/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:58:46 by vvoronts          #+#    #+#             */
/*   Updated: 2025/12/09 17:39:19 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <string>

class Bureaucrat {
	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat &src);
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();

		Bureaucrat &operator=(const Bureaucrat &src);

		static int const	highestGrade = 1;
		static int const	lowestGrade = 150;

		void				incrementGrade();
		void				decrementGrade();
		int					getGrade() const;
		std::string			getName() const;

	private:
		const std::string 	_name;
		int					_grade;

		void				verifyGrade(int grade);

		class GradeTooHighException : public std::exception {
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);

#endif