/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 12:45:50 by vvoronts          #+#    #+#             */
/*   Updated: 2025/11/22 16:51:39 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <string>

/*
 * @class Animal
 * @brief Base class representing a generic animal.
 *
 * For polymorphic deletion (deleting a derived object through a base pointer), 
 * the base class must have a virtual destructor for the derived destructor to be invoked
*/
class Animal {
	public:
		Animal();
		Animal(const Animal& other);
		Animal& operator=(const Animal& other);
		virtual ~Animal();

		std::string		getType() const;
		virtual void	makeSound() const;

	protected:
		void			setType(const std::string& type);
		std::string		type;
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