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
 * @tparam T The type of elements stored in the stack.
 * @tparam C The underlying container type (default is std::deque<T>).
 * @details Inherits from std::stack and provides iterator access to the
 * underlying container.
 */
template <typename T, typename C = std::deque<T> >
class MutantStack : public std::stack<T, C> 
{
    public:
        // type definition for simpler access to iterator types
        typedef typename std::stack<T, C>::container_type::iterator iterator;
        typedef typename std::stack<T, C>::container_type::const_iterator const_iterator;
        typedef typename std::stack<T, C>::container_type::reverse_iterator reverse_iterator;
        typedef typename std::stack<T, C>::container_type::const_reverse_iterator const_reverse_iterator;

        MutantStack<T, C>(void) : std::stack<T, C>(){};
        MutantStack<T, C>(MutantStack<T, C> const& src) : std::stack<T, C>(src){};
        ~MutantStack<T, C>(void){};

        MutantStack<T, C>& operator=(MutantStack<T, C> const& src) {
            if (this != &src) this->c = src.c;
            return (*this);
        }

        // iterator functions
        MutantStack<T, C>::iterator begin(void) { return (this->c.begin()); }

        MutantStack<T, C>::iterator end(void) { return (this->c.end()); }

        // const iterator functions
        MutantStack<T, C>::const_iterator begin(void) const {
            return (this->c.begin());
        }

        MutantStack<T, C>::const_iterator end(void) const { return (this->c.end()); }

        // reverse iterator functions
        MutantStack<T, C>::reverse_iterator rbegin(void) {
            return (this->c.rbegin());
        }

        MutantStack<T, C>::reverse_iterator rend(void) { return (this->c.rend()); }

        // const reverse iterator functions
        MutantStack<T, C>::const_reverse_iterator rbegin(void) const {
            return (this->c.rbegin());
        }

        MutantStack<T, C>::const_reverse_iterator rend(void) const {
            return (this->c.rend());
        }
};
#endif
