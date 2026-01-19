/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 14:14:20 by vvoronts          #+#    #+#             */
/*   Updated: 2026/01/19 14:15:44 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>

template <typename T>
class Array {
    public:
        Array();
        Array(const Array<T> &other);
        Array(const unsigned int &n);
        ~Array();

        Array<T> &operator=(const Array<T> &other);
        T &operator[](const unsigned int &index);

        unsigned int size() const;

    private:
        T *_items;
        unsigned int _n;

    class IndexOutOfBoundException : public std::exception {
        public:
            virtual const char *what() const throw();
    };
};

#include "Array.tpp"
#endif
