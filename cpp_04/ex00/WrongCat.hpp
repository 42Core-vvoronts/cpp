/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 12:53:30 by vvoronts          #+#    #+#             */
/*   Updated: 2025/11/16 12:54:38 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP
# include "WrongAnimal.hpp"
# include <string>
# include <iostream>

class WrongCat : public WrongAnimal {
	public:
		WrongCat();
		WrongCat(WrongCat const &src);
		WrongCat& operator=(WrongCat const &src);
		virtual ~WrongCat();

		void	makeSound(void) const;

};

#endif