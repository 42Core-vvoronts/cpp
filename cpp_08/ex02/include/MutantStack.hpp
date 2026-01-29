/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 14:36:17 by vvoronts          #+#    #+#             */
/*   Updated: 2026/01/19 19:06:44 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

/**
 * @brief A stack that supports iteration.
 * Subject:
 * "MutantStack class. It will be implemented in terms of a std::stack.
 * It will offer all its member functions, plus an additional feature: iterator"
 * 
 * std::stack: https://en.cppreference.com/w/cpp/container/stack.html
 * 
 * Deque is the default underlying container for std::stack.
 * c is the protected member of std::stack that holds the underlying container.
 * It works the same way as a stack, but also allows iteration through its elements.
 * 
 * List of std::stack member functions:
 * - top: access the top element
 * - empty: check if the stack is empty
 * - size: get the number of elements
 * - push: add an element to the top
 * - pop: remove the top element
 *  Added iterators and const versions:
 * - begin: returns pointer to the First element *it = First element
 * - end: returns pointer to After last element *it = undefined
 * - rbegin: returns pointer to the Last element *it = Last element 
 * - rend: returns pointer to the Before first element *it = undefined
 * 
 * @tparam T The type of elements stored in the stack.
 * @tparam C The underlying container type (default is std::deque<T>).
 */
template <typename T, typename C = std::deque<T> >
class MutantStack : public std::stack<T, C>
{
    public:
        // type definition for shorter access to iterator types
        typedef typename std::stack<T, C>::container_type::iterator               iterator;
        typedef typename std::stack<T, C>::container_type::const_iterator         const_iterator;
        typedef typename std::stack<T, C>::container_type::reverse_iterator       reverse_iterator;
        typedef typename std::stack<T, C>::container_type::const_reverse_iterator const_reverse_iterator;

        // OCF constructors and destructor, overloaded assignment operator
        MutantStack<T, C>(void) : std::stack<T, C>(){};
        MutantStack<T, C>(MutantStack<T, C> const& src) : std::stack<T, C>(src){};
        ~MutantStack<T, C>(void){};

        MutantStack<T, C>& operator=(MutantStack<T, C> const& src) {
            if (this != &src) this->c = src.c;
            return (*this);
        }

        // direct 
        iterator               begin(void) { return (this->c.begin()); }
        iterator               end(void) { return (this->c.end()); }
        const_iterator         begin(void) const { return (this->c.begin()); }
        const_iterator         end(void) const { return (this->c.end()); }
        // reverse
        reverse_iterator       rbegin(void) { return (this->c.rbegin()); }
        reverse_iterator       rend(void) { return (this->c.rend()); }
        const_reverse_iterator rbegin(void) const { return (this->c.rbegin());}
        const_reverse_iterator rend(void) const { return (this->c.rend()); }
};

#endif