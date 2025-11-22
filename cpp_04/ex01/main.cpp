/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 12:41:52 by vvoronts          #+#    #+#             */
/*   Updated: 2025/11/22 18:57:53 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

static void sep(const char *title)
{
	std::cout << "\n---- " << title << " ----\n";
}

// Stack Memory (The Array)          Heap Memory (The Actual Objects)
// +------------------+             +-----------------------------+
// | arr[0] (Pointer) |------------>| [ Dog Object ]              |
// +------------------+             | - vptr (points to Dog func) |
// | arr[1] (Pointer) |--------+    | - type: "Dog"               |
// +------------------+        |    +-----------------------------+
//                             |
//                             |    +-----------------------------+
//                             +--->| [ Cat Object ]              |
//                                  | - vptr (points to Cat func) |
//                                  | - type: "Cat"               |
//                                  +-----------------------------+
/*To ensure you understood how it works, implement a WrongCat class that inherits
from a WrongAnimal class. If you replace the Animal and the Cat by the wrong ones
in the code above, the WrongCat should output the WrongAnimal sound.*/
#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void sep(std::string title) {

	std::cout << "------------------------------------------------\n";
	std::cout << " " << title << "\n";
	std::cout << "------------------------------------------------" << std::endl;
}


int main()
{
	// ========================================================
	// TEST 1: Subject Requirement (Polymorphic Array)
	// ========================================================
	sep("Subject Requirement: Array of Animals");
	const int N = 4;
	Animal* animals[N];

	std::cout << "[Creating Animals...]" << std::endl;
	for (int i = 0; i < N; i++) {
		if (i < N / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	std::cout << "\n[Testing Sounds...]" << std::endl;
	for (int i = 0; i < N; i++) {
		animals[i]->makeSound();
	}

	std::cout << "\n[Deleting Array...]" << std::endl;
	// This checks if destructors are called in correct order
	// Expect: ~Dog/~Cat -> ~Brain -> ~Animal
	for (int i = 0; i < N; i++) {
		delete animals[i];
	}

	// ========================================================
	// TEST 2: Deep Copy Proof (Copy Constructor)
	// ========================================================
	sep("Deep Copy Proof (Copy Constructor)");
	
	std::cout << "Creating catOriginal..." << std::endl;
	Cat* catOriginal = new Cat();

	std::cout << "Creating catCopy (from catOriginal)..." << std::endl;
	Cat* catCopy = new Cat(*catOriginal);

	std::cout << "\n--- CHECKING MEMORY ADDRESSES ---" << std::endl;
	// We assume you have getBrain() based on your previous messages.
	// If you don't, you can trust the Valgrind check at the end.
	std::cout << "Original Brain Address: " << catOriginal->getBrain() << std::endl;
	std::cout << "Copy     Brain Address: " << catCopy->getBrain() << std::endl;

	if (catOriginal->getBrain() != catCopy->getBrain())
		std::cout << ">> SUCCESS: Brain pointers are DIFFERENT. (Deep Copy)" << std::endl;
	else
		std::cout << ">> FAILED: Brain pointers are THE SAME. (Shallow Copy)" << std::endl;

	delete catOriginal;
	delete catCopy;

	// ========================================================
	// TEST 3: Deep Copy Proof (Assignment Operator)
	// ========================================================
	sep("Deep Copy Proof (Assignment Operator)");

	{
		std::cout << "Creating dogA..." << std::endl;
		Dog dogA;
		std::cout << "Creating dogB..." << std::endl;
		Dog dogB;

		std::cout << "\n--- BEFORE ASSIGNMENT ---" << std::endl;
		std::cout << "Dog A Brain Address: " << dogA.getBrain() << std::endl;
		std::cout << "Dog B Brain Address: " << dogB.getBrain() << std::endl;

		std::cout << "\n>> Executing: dogB = dogA;" << std::endl;
		dogB = dogA; 

		std::cout << "\n--- AFTER ASSIGNMENT ---" << std::endl;
		std::cout << "Dog A Brain Address: " << dogA.getBrain() << std::endl;
		std::cout << "Dog B Brain Address: " << dogB.getBrain() << std::endl;

		// Proof of Deep Copy:
		// Even if dogB reused its memory, it MUST NOT point to dogA's brain.
		if (dogA.getBrain() != dogB.getBrain())
			std::cout << ">> SUCCESS: Pointers are unique." << std::endl;
		else
			std::cout << ">> FAILED: Pointers are shared (Shallow Copy)." << std::endl;
	}
	std::cout << "\n[Scope exited] Destructors called." << std::endl;

	return 0;
}

// int main() {
// 	sep("--- Subject Example ---");
// 	const Animal* j = new Dog();
// 	const Animal* i = new Cat();
// 	delete j;  // should not create a leak
// 	delete i;

// 	std::cout << std::endl
// 			<< "--- Call Destructors via Animal in an Array --" << std::endl;
// 	Animal* animals[4] = {new Dog(), new Dog(), new Cat(), new Cat()};
// 	for (int i = 0; i < 4; i++) delete animals[i];

// 	std::cout << std::endl
// 			<< "--- Check if Copy Constructor makes Deep Copy --" << std::endl;
// 	Cat* cat0 = new Cat();
// 	Cat* cat1 = new Cat(*cat0);
// 	std::cout << cat0->getBrain() << " - memory adress of the cat0 brain"
// 			<< std::endl;
// 	std::cout << cat1->getBrain() << " - memory adress of the cat1 brain"
// 			<< std::endl;
// 	std::cout << cat0->getBrain()->getIdea(0) << " - a first idea in cat0 brain"
// 			<< std::endl;
// 	std::cout << cat1->getBrain()->getIdea(0) << " - a first idea in cat1 brain"
// 			<< std::endl;
// 	std::cout << &(cat0->getBrain()->getIdea(0))
// 			<< " - an address of a first idea in cat0 brain" << std::endl;
// 	std::cout << &(cat1->getBrain()->getIdea(0))
// 			<< " - an address of a first idea in cat1 brain" << std::endl;
// 	delete cat0;
// 	delete cat1;

// 	std::cout << "--- Testing Assignment Operator (The Leak Check) ---" << std::endl;
// 	Cat existing_cat;
// 	Cat second_cat;
	
// 	second_cat = existing_cat;
// 	return 0;
// }
