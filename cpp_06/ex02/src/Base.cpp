/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 19:50:00 by vvoronts          #+#    #+#             */
/*   Updated: 2026/01/18 19:55:03 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>

Base::~Base() {}

/**
* @brief Generates and returns a pointer to a random instance of A, B, or C.
* @return Base* Pointer to the generated instance.
*
*/
Base *generate(void) {
    switch (std::rand() % 3) {
    case 0:
        std::cout << "Generated instance of A*\n";
        return (new A());
    case 1:
        std::cout << "Generated instance of B*\n";
        return (new B());
    case 2:
        std::cout << "Generated instance of C*\n";
        return (new C());
    default:
        return (NULL);
    }
}

/**
* @brief Identifies the derived type of the object pointed to by Base pointer p.
* @param p Pointer to the Base class object.

*/
void identify(Base *p) {
    std::string type = "";
    if (dynamic_cast<A *>(p))
        type = "A";
    else if (dynamic_cast<B *>(p))
        type = "B";
    else if (dynamic_cast<C *>(p))
        type = "C";
    else {
        std::cout << "Unknown type" << std::endl;
        return;
    }
    std::cout << "Identified " << type << " type" << std::endl;
}

/**
 * @brief Identifies the derived type of the object referenced by Base reference p.
 * @param p Reference to the Base class object.
 */
void identify(Base &p) {
    try {
        (void)dynamic_cast<A &>(p);
        std::cout << "Identified A type" << std::endl;
        return;
    } catch (...) {
     }
    try {
        (void)dynamic_cast<B &>(p);
        std::cout << "Identified B type" << std::endl;
        return;
    } catch (...) {
     }
    try {
        (void)dynamic_cast<C &>(p);
        std::cout << "Identified C type" << std::endl;
        return;
    } catch (...) {
    }
     std::cout << "Unknown type" << std::endl;
}
