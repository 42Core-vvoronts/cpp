/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 12:41:52 by vvoronts          #+#    #+#             */
/*   Updated: 2025/11/16 14:38:08 by vvoronts         ###   ########.fr       */
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
	std::cout << "\n=== " << title << " ===\n";
}

int main()
{
	sep("Basic polymorphism (heap)");
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << "j type: " << j->getType() << std::endl;
	std::cout << "i type: " << i->getType() << std::endl;
	i->makeSound(); // cat sound
	j->makeSound(); // dog sound
	meta->makeSound();

	sep("WrongAnimal polymorphism (heap)");
	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();
	std::cout << "wrongCat type: " << wrongCat->getType() << std::endl;
	wrongCat->makeSound(); // will call WrongAnimal::makeSound (non-virtual)
	wrongMeta->makeSound();

	sep("Cleanup heap objects");
	delete meta;
	delete j;
	delete i;
	delete wrongMeta;
	delete wrongCat;

	sep("Stack allocation and scope (destructors)");
	{
		Dog d;
		Cat c;
		std::cout << "Inside scope: d type=" << d.getType() << ", c type=" << c.getType() << std::endl;
		d.makeSound();
		c.makeSound();
	}
	std::cout << "Exited scope — stack destructors should have been called" << std::endl;

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