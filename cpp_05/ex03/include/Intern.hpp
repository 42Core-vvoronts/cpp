/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 19:40:00 by vvoronts          #+#    #+#             */
/*   Updated: 2025/12/10 19:33:51 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include "AForm.hpp"

/*
The
intern has no name, no grade, and no unique characteristics. The only thing bureaucrats
care about is that they do their job.
*/
class Intern {
	public:
		Intern();
		Intern(const Intern &src);
		~Intern();

		Intern &operator=(const Intern &src);

		AForm *makeForm(const std::string &formName, const std::string &target) const;
};

#endif
