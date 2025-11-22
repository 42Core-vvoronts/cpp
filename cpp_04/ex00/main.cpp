/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 12:41:52 by vvoronts          #+#    #+#             */
/*   Updated: 2025/11/22 12:53:40 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>

int main() {
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();  // will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete j;
	delete i;

	std::cout << std::endl;

	const WrongAnimal* wMeta = new WrongAnimal();
	const WrongAnimal* wI = new WrongCat();
	wMeta->makeSound();
	wI->makeSound();
	delete wMeta;
	delete wI;

	return 0;
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


// // --- COLORS FOR PRETTY PRINTING ---
// #define RST  "\033[0m"
// #define RED  "\033[31m"   
// #define GRN  "\033[32m"   
// #define CYN  "\033[36m"   
// #define YEL  "\033[33m"   

// static void sep(std::string title)
// {
// 	std::cout << "\n" << CYN;
// 	std::cout << " " << std::endl;
// 	std::cout << "----- " << title << "-----" << std::endl;
// 	std::cout << " " << RST << std::endl;
// }

// int main()
// {
// 	// ----------------------------------------------------------------------
// 	sep("1. HEAP POLYMORPHISM (Virtual Keywords)");
// 	// ----------------------------------------------------------------------
// 	std::cout << "Allocating generic Animal, Dog, and Cat..." << std::endl;
	
// 	const Animal* meta = new Animal();
// 	const Animal* j = new Dog();
// 	const Animal* i = new Cat();

// 	std::cout << "\n" << std::left << std::setw(20) << "POINTER" 
// 			<< std::setw(20) << "TYPE (getType)" 
// 			<< "SOUND (makeSound)" << std::endl;
// 	std::cout << "------------------------------------------------------------" << std::endl;

// 	std::cout << std::left << std::setw(20) << "Animal* j" 
// 			<< std::setw(20) << j->getType();
// 	std::cout << GRN; j->makeSound(); std::cout << RST << std::endl; 

// 	std::cout << std::left << std::setw(20) << "Animal* i" 
// 			<< std::setw(20) << i->getType();
// 	std::cout << GRN; i->makeSound(); std::cout << RST << std::endl; 
	
// 	std::cout << std::left << std::setw(20) << "Animal* meta" 
// 			<< std::setw(20) << meta->getType();
// 	std::cout << GRN; meta->makeSound(); std::cout << RST << std::endl;

// 	// ----------------------------------------------------------------------
// 	sep("2. WRONG ANIMAL (Missing Virtual)");
// 	// ----------------------------------------------------------------------
// 	std::cout << "Allocating WrongAnimal and WrongCat..." << std::endl;

// 	const WrongAnimal* wrongMeta = new WrongAnimal();
// 	const WrongAnimal* wrongCat = new WrongCat();

// 	std::cout << "\n" << std::left << std::setw(20) << "POINTER" 
// 			<< std::setw(20) << "ACTUAL TYPE" 
// 			<< "OUTPUT" << std::endl;
// 	std::cout << "--------------------------------------------------------------------------------" << std::endl;

// 	// --- TEST 1: WrongCat (Demonstration) ---
// 	std::cout << std::left << std::setw(20) << "WrongAnimal*" 
// 			<< std::setw(20) << wrongCat->getType();
	
// 	std::cout << YEL; 
// 	wrongCat->makeSound(); 
// 	std::cout << RST;

// 	std::cout << std::setw(40) << std::endl;
	
// 	// Clarify that this is EXPECTED behavior for this specific class
// 	// std::cout << std::setw(40) << " " << "^^^ (Base sound called: Static Binding)" << std::endl;


// 	// --- TEST 2: WrongAnimal (Standard) ---
// 	std::cout << std::left << std::setw(20) << "WrongAnimal*" 
// 			<< std::setw(20) << wrongMeta->getType();
	
// 	std::cout << YEL;
// 	wrongMeta->makeSound(); 
// 	std::cout << RST;
	

// 	// ----------------------------------------------------------------------
// 	sep("3. CLEANUP (Checking Destructors)");
// 	// ----------------------------------------------------------------------
// 	std::cout << YEL;
// 	delete meta;
// 	delete j;
// 	delete i;
// 	delete wrongMeta;
// 	delete wrongCat;
// 	std::cout << RST;

// 	// ----------------------------------------------------------------------
// 	sep("4. STACK ALLOCATION (Scope Check)");
// 	// ----------------------------------------------------------------------
// 	{
// 		std::cout << "Entering scope..." << std::endl;
// 		Dog d;
// 		Cat c;
		
// 		std::cout << "Inside scope: " << std::endl;
// 		std::cout << "  d is a " << GRN << d.getType() << RST << ": "; d.makeSound(); std::cout << std::endl;
// 		std::cout << "  c is a " << GRN << c.getType() << RST << ": "; c.makeSound(); std::cout << std::endl;

// 		std::cout << "Exiting scope (Destructors should print below)..." << std::endl;
// 		std::cout << YEL;
// 	} 
// 	std::cout << RST << "Scope exited." << std::endl;

// 	// ----------------------------------------------------------------------
// 	sep("5. COPY CONSTRUCTOR & ASSIGNMENT");
// 	// ----------------------------------------------------------------------
// 	{
// 		std::cout << "Creating 'original' Dog..." << std::endl;
// 		Dog original;
		
// 		std::cout << "Copy constructing 'copy' from 'original'..." << std::endl;
// 		Dog copy_constructed(original);
		
// 		std::cout << "Creating 'assigned' and assigning from 'original'..." << std::endl;
// 		Dog assigned;
// 		assigned = original;

// 		std::cout << "\nTesting Clones:" << std::endl;
// 		std::cout << "Original: " << GRN << original.getType() << RST << std::endl;
// 		std::cout << "Copy Ctor: "; copy_constructed.makeSound(); std::cout << std::endl;
// 		std::cout << "Assigned:  "; assigned.makeSound(); std::cout << std::endl;
		
// 		std::cout << YEL; 
// 	}
// 	std::cout << RST;

// 	// ----------------------------------------------------------------------
// 	sep("6. POLYMORPHIC ARRAY LOOPS");
// 	// ----------------------------------------------------------------------
// 	const int N = 4;
// 	Animal* arr[N];
	
// 	std::cout << "Filling array with 50% Dogs, 50% Cats..." << std::endl;
// 	for (int k = 0; k < N; ++k) {
// 		if (k % 2 == 0) arr[k] = new Dog();
// 		else arr[k] = new Cat();
// 	}

// 	std::cout << "\nIterating Array:" << std::endl;
// 	for (int k = 0; k < N; ++k) {
// 		std::cout << "Index " << k << ": " << std::setw(10) << arr[k]->getType() << " says ";
// 		std::cout << GRN; arr[k]->makeSound(); std::cout << RST << std::endl;
// 	}

// 	std::cout << "\nDeleting Array:" << YEL << std::endl;
// 	for (int k = 0; k < N; ++k) {
// 		delete arr[k];
// 	}
// 	std::cout << RST;

// 	sep("END OF TESTS");
// 	return 0;
// }






// static void sep(const char *title)
// {
// 	std::cout << "\n---- " << title << " ----\n";
// }

// int main()
// {
	
// 	// Demonstrates runtime polymorphism using virtual functions (getType, makeSound) 
// 	// with base class pointers (Animal*) pointing to derived class objects (Dog, Cat) 
// 	// allocated on the heap (new).
// 	sep("Basic polymorphism (heap)");
// 	const Animal* meta = new Animal();
// 	const Animal* j = new Dog();
// 	const Animal* i = new Cat();

// 	std::cout << "j type: " << j->getType() << std::endl;
// 	std::cout << "i type: " << i->getType() << std::endl;
// 	i->makeSound(); // cat sound
// 	j->makeSound(); // dog sound
// 	meta->makeSound();

// 	// Shows what happens when the base class method (makeSound) 
// 	// is NOT declared as virtual. 
// 	// It illustrates that the non-polymorphic base class version is called, 
// 	// even when accessed via a base class pointer (WrongAnimal*) 
// 	// pointing to a derived object (WrongCat).
// 	sep("WrongAnimal polymorphism (heap)");
// 	const WrongAnimal* wrongMeta = new WrongAnimal();
// 	const WrongAnimal* wrongCat = new WrongCat();
// 	std::cout << "wrongCat type: " << wrongCat->getType() << std::endl;
// 	wrongCat->makeSound(); // will call WrongAnimal::makeSound (non-virtual)
// 	wrongMeta->makeSound();

// 	//Explicitly calls delete on the dynamically allocated objects (new ...) 
// 	//from the previous two sections to prevent memory leaks and trigger their destructors.
// 	sep("Cleanup heap objects");
// 	delete meta;
// 	delete j;
// 	delete i;
// 	delete wrongMeta;
// 	delete wrongCat;

// 	// Tests automatic memory management by allocating objects (Dog d, Cat c) on the stack. 
// 	// The objects' destructors are automatically called when they go out of scope (}).
// 	sep("Stack allocation and scope (destructors)");
// 	{
// 		Dog d;
// 		Cat c;
// 		std::cout << "Inside scope: d type=" << d.getType() << ", c type=" << c.getType() << std::endl;
// 		d.makeSound();
// 		c.makeSound();
// 	}
// 	std::cout << "Exited scope — stack destructors should have been called" << std::endl;

// 	// Demonstrates the use of the copy constructor (Dog copy_constructed(original)) 
// 	// and the copy assignment operator (assigned = original) to create copies of objects.
// 	sep("Copy constructor and assignment");
// 	{
// 		Dog original;
// 		Dog copy_constructed(original);
// 		Dog assigned;
// 		assigned = original;
// 		std::cout << "original type: " << original.getType() << std::endl;
// 		copy_constructed.makeSound();
// 		assigned.makeSound();
// 	}

// 	//Shows how to create an array of base class pointers (Animal* arr[N]) 
// 	// that hold mixed derived class objects (Dog, Cat), 
// 	// confirming that polymorphism works in this context, 
// 	// and then correctly deletes them in a loop.
// 	sep("Polymorphic array and bulk deletion");
// 	{
// 		const int N = 4;
// 		Animal* arr[N];
// 		for (int k = 0; k < N; ++k) {
// 			if (k % 2 == 0) arr[k] = new Dog();
// 			else arr[k] = new Cat();
// 		}
// 		for (int k = 0; k < N; ++k) {
// 			std::cout << "arr[" << k << "] type: " << arr[k]->getType() << std::endl;
// 			arr[k]->makeSound();
// 		}
// 		for (int k = 0; k < N; ++k) delete arr[k];
// 	}

// 	sep("End of tests — all destructors should have run by now");

// 	return 0;
// }

/*To ensure you understood how it works, implement a WrongCat class that inherits
from a WrongAnimal class. If you replace the Animal and the Cat by the wrong ones
in the code above, the WrongCat should output the WrongAnimal sound.*/

