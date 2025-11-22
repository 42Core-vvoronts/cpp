/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 12:45:50 by vvoronts          #+#    #+#             */
/*   Updated: 2025/11/22 13:33:15 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <string>
# include <iostream>

/*
 * @class Animal
 * @brief Base class representing a generic animal.
 *
 * For polymorphic deletion (deleting a derived object through a base pointer), 
 * the base class must have a virtual destructor for the derived destructor to be invoked
 *
 * Protected: Members are accessible within the class itself and by derived classes, but not by external code
*/
class Animal {
	public:
		Animal();
		Animal(Animal const &src);
		Animal& operator=(Animal const &src);
		virtual ~Animal();

		virtual void	makeSound(void) const;
		std::string		getType(void) const;

	protected:
		void			setType(const std::string& type);
		std::string		type;
};

#endif

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