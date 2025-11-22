/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 12:45:50 by vvoronts          #+#    #+#             */
/*   Updated: 2025/11/22 19:06:47 by vvoronts         ###   ########.fr       */
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
		virtual void	makeSound() const = 0; // Pure virtual function

	protected:
		void			setType(const std::string& type);
		std::string		type;
};

/*
-------------------------------------------------------------------------------------------------------
| Method                            | Virtual |           Scope             |        Binding          |
|-----------------------------------|---------|-----------------------------|-------------------------|
| Animal()                          |   NO    | Code Segment (Static)       | Static / Compile        |
| Animal(Animal const &src)         |   NO    | Code Segment (Static)       | Static / Compile        |
| Animal& operator=(...)            |   NO    | Code Segment (Static)       | Static / Compile        |
| virtual ~Animal()                 |   YES   | **VTABLE**                  | Dynamic / Runtime vptr  |
| virtual void makeSound()          |   YES   | **VTABLE**                  | Dynamic / Runtime vptr  |
| std::string getType()             |   NO    | Code Segment (Static)       | Static / Compile        |
| void setType(...)                 |   NO    | Code Segment (Static)       | Static / Compile        |
-------------------------------------------------------------------------------------------------------

Static Binding (Compile-time): 
	The compiler writes the exact address of the function into the code. 
	It is fast, but it cannot change behavior based on the object type at runtime.
Dynamic Binding (Runtime): 
	The compiler writes instructions to "look at the vptr, find the table, 
	and pick the function at index X". This allows Cat to behave differently than Animal.
*/

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