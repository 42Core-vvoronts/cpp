/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 18:34:05 by vvoronts          #+#    #+#             */
/*   Updated: 2026/01/19 18:34:06 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "MutantStack.hpp"
#include <list>

int main() {
  // SUBJECT  TEST
    std::cout << "--- Test from subject ---" << std::endl;
    {
      MutantStack<int> mstack;
      mstack.push(5);
      mstack.push(17);
      std::cout << mstack.top() << std::endl;
      mstack.pop();
      std::cout << mstack.size() << std::endl;
      mstack.push(3);
      mstack.push(5);
      mstack.push(737);
      //[...]
      mstack.push(0);
      MutantStack<int>::iterator it = mstack.begin();
      MutantStack<int>::iterator ite = mstack.end();
      ++it;
      --it;
      while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
      }
      std::stack<int> s(mstack);
    }
    std::cout << std::endl;

  // std::list Comparison (Mandatory check)
  /* If you run it a first time with your MutantStack, and a second time replacing the
  MutantStack with, for example, a std::list, the two outputs should be the same. Of
  course, when testing another container, update the code below with the corresponding
  member functions (push() can become push_back()).*/
  std::cout << "\n--- std::list Test (Should match above) ---" << std::endl;
  {
    std::list<int> lstack;
    lstack.push_back(5);
    lstack.push_back(17);
    std::cout << lstack.back() << std::endl;
    lstack.pop_back();
    std::cout << lstack.size() << std::endl;
    lstack.push_back(3);
    lstack.push_back(5);
    lstack.push_back(737);
    lstack.push_back(0);
    std::list<int>::iterator lit = lstack.begin();
    std::list<int>::iterator lite = lstack.end();
    ++lit;
    --lit;
    while (lit != lite) {
        std::cout << *lit << std::endl;
        ++lit;
    }

  }
  std::cout << std::endl;

  // ADDITIONAL TESTS
  std::cout << "\n--- Additional Tests ---" << std::endl;
    {
      MutantStack<int> mstack;
      mstack.push(1);
      mstack.push(2);
      mstack.push(3);

      MutantStack<int>::reverse_iterator rit = mstack.rbegin();
      MutantStack<int>::reverse_iterator rite = mstack.rend();
      while (rit != rite) {
          std::cout << *rit << " "; // Should print: 3 2 1
          ++rit;
      }
      std::cout << std::endl;
  }

  std::cout << "\n--- String Stack Test ---" << std::endl;
  {
    MutantStack<std::string> sstack;
    sstack.push("Hello");
    sstack.push("World");
    sstack.push("!");

    MutantStack<std::string>::iterator it = sstack.begin();
    while (it != sstack.end()) {
        std::cout << *it << " "; // Output: Hello World ! 
        it++;
    }
    std::cout << std::endl;
  }

  return 0;
}
