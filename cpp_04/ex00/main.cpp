/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 12:41:52 by vvoronts          #+#    #+#             */
/*   Updated: 2025/11/20 19:31:35 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

static void sep(const char *title)
{
	std::cout << "\n---- " << title << " ----\n";
}

int main()
{
	// Demonstrates runtime polymorphism using virtual functions (getType, makeSound) 
	// with base class pointers (Animal*) pointing to derived class objects (Dog, Cat) 
	// allocated on the heap (new).
	sep("Basic polymorphism (heap)");
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << "j type: " << j->getType() << std::endl;
	std::cout << "i type: " << i->getType() << std::endl;
	i->makeSound(); // cat sound
	j->makeSound(); // dog sound
	meta->makeSound();

	// Shows what happens when the base class method (makeSound) 
	// is NOT declared as virtual. 
	// It illustrates that the non-polymorphic base class version is called, 
	// even when accessed via a base class pointer (WrongAnimal*) 
	// pointing to a derived object (WrongCat).
	sep("WrongAnimal polymorphism (heap)");
	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();
	std::cout << "wrongCat type: " << wrongCat->getType() << std::endl;
	wrongCat->makeSound(); // will call WrongAnimal::makeSound (non-virtual)
	wrongMeta->makeSound();

	//Explicitly calls delete on the dynamically allocated objects (new ...) 
	//from the previous two sections to prevent memory leaks and trigger their destructors.
	sep("Cleanup heap objects");
	delete meta;
	delete j;
	delete i;
	delete wrongMeta;
	delete wrongCat;

	// Tests automatic memory management by allocating objects (Dog d, Cat c) on the stack. 
	// The objects' destructors are automatically called when they go out of scope (}).
	sep("Stack allocation and scope (destructors)");
	{
		Dog d;
		Cat c;
		std::cout << "Inside scope: d type=" << d.getType() << ", c type=" << c.getType() << std::endl;
		d.makeSound();
		c.makeSound();
	}
	std::cout << "Exited scope — stack destructors should have been called" << std::endl;

	// Demonstrates the use of the copy constructor (Dog copy_constructed(original)) 
	// and the copy assignment operator (assigned = original) to create copies of objects.
	sep("Copy constructor and assignment");
	{
		Dog original;
		Dog copy_constructed(original);
		Dog assigned;
		assigned = original;
		std::cout << "original type: " << original.getType() << std::endl;
		copy_constructed.makeSound();
		assigned.makeSound();
	}

	//Shows how to create an array of base class pointers (Animal* arr[N]) 
	// that hold mixed derived class objects (Dog, Cat), 
	// confirming that polymorphism works in this context, 
	// and then correctly deletes them in a loop.
	sep("Polymorphic array and bulk deletion");
	{
		const int N = 4;
		Animal* arr[N];
		for (int k = 0; k < N; ++k) {
			if (k % 2 == 0) arr[k] = new Dog();
			else arr[k] = new Cat();
		}
		for (int k = 0; k < N; ++k) {
			std::cout << "arr[" << k << "] type: " << arr[k]->getType() << std::endl;
			arr[k]->makeSound();
		}
		for (int k = 0; k < N; ++k) delete arr[k];
	}

	sep("End of tests — all destructors should have run by now");

	return 0;
}

/*To ensure you understood how it works, implement a WrongCat class that inherits
from a WrongAnimal class. If you replace the Animal and the Cat by the wrong ones
in the code above, the WrongCat should output the WrongAnimal sound.*/