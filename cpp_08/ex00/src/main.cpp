/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 14:24:37 by vvoronts          #+#    #+#             */
/*   Updated: 2026/01/19 14:25:15 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <deque> // for std::deque
#include <iostream> // for std::cout, std::endl
#include <list> // for std::list
#include <vector> // for std::vector

#include "easyfind.hpp"

template <typename T>
void test(const std::string &name, T &c, const int &i) {
    c.push_back(0);
    c.push_back(1);
    c.push_back(2);
    c.push_back(3);
    std::cout << "Test: search " << i << " in " << name << std::endl;
    try {
        typename T::const_iterator it = easyfind(c, i);
        (void)it;
        std::cout << i << " has been found" << std::endl;
    } catch (const std::exception &e) {
        std::cout << i << " not found" << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> vector;
    std::list<int> list;
    std::deque<int> deque;

    std::cout << "----- Positive tests -----" << std::endl << std::endl;

    test("vector", vector, 0);
    test("list", list, 1);
    test("deque", deque, 2);

    std::cout << "----- Negative tests -----" << std::endl << std::endl;

    test("deque", deque, -1);
    test("list", list, 42);
    test("vector", vector, 100);
}
