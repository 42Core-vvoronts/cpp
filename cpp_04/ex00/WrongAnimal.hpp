/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 12:52:49 by vvoronts          #+#    #+#             */
/*   Updated: 2025/11/16 12:53:12 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include <string>
# include <iostream>

class WrongAnimal {
	public:
		WrongAnimal();
		WrongAnimal(WrongAnimal const &src);
		WrongAnimal& operator=(WrongAnimal const &src);
		virtual ~WrongAnimal();

		void			makeSound(void) const;
		std::string		getType(void) const;

	protected:
		std::string		type;
};

#endif