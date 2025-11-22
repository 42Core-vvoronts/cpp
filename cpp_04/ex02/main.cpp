/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 12:41:52 by vvoronts          #+#    #+#             */
/*   Updated: 2025/11/22 19:09:42 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

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
int main() {
	std::cout << std::endl << "--- Tests ---" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;
	delete i;

	// It is not possible
	// Animal();
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
