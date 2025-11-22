/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 12:49:12 by vvoronts          #+#    #+#             */
/*   Updated: 2025/11/22 13:43:20 by vvoronts         ###   ########.fr       */
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

/*
[ HEAP MEMORY ]                 [ .RODATA SECTION ]                 [ .TEXT SECTION ]
   (The Object)                    (The Vtable)                    (The Instructions)

+------------------+             +---------------------+         +---------------------+
| Cat Instance     |             | Vtable for Cat      |         | ~Cat destructor     |
|                  |             |                     |         |                     |
| [vptr]  -------------------->  | Index 0: ~Cat   ----------->  | [Binary Code...]    |
| string type      |             | Index 1: makeSound -------+   |                     |
+------------------+             +---------------------+     |   +---------------------+
                                                             |
                                                             |   +---------------------+
                                                             +-> | Cat::makeSound()    |
                                                                 |                     |
                                                                 | [Binary Code...]    |
                                                                 +---------------------+


Offset     Size       Content (Member)                  Access Context
+----------+----------+---------------------------------+-----------------------------+
| 0 bytes  | 8 bytes  | _vptr (Virtual Pointer)         | Hidden (System)             |
|          |          | [Points to Cat's vtable]        | Needed for virtual functions|
+----------+----------+---------------------------------+-----------------------------+
| 8 bytes  | ~32 bytes| std::string type                | Protected                   |
|          |          | [Pointer, Size, Capacity]       | Accessible by Animal & Cat  |
+----------+----------+---------------------------------+-----------------------------+
| 40 bytes | 0 bytes  | Cat's Members                   | Private/Public              |
|          |          |                                 |                             |
+----------+----------+---------------------------------+-----------------------------+
Total Size: ~40 bytes

-------------------------------------------------------
*/