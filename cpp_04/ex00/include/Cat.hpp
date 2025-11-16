/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 12:49:12 by vvoronts          #+#    #+#             */
/*   Updated: 2025/11/16 12:49:39 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"
# include <string>
# include <iostream>

class Cat : public Animal {
	public:
		Cat();
		Cat(Cat const &src);
		Cat& operator=(Cat const &src);
		virtual ~Cat();

		virtual void	makeSound(void) const;

};

#endif