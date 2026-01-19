/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 14:16:41 by vvoronts          #+#    #+#             */
/*   Updated: 2026/01/19 14:20:59 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

/**
 * @brief Default constructor that initializes an empty array.
 * @tparam T Type of the elements in the array.
 * @return void
 */
template <typename T>
Array<T>::Array() : _n(0) {
    this->_items = new T[this->_n]();
}

/**
 * @brief Copy constructor that creates a new array as a copy of another.
 * @tparam T Type of the elements in the array.
 * @param other The array to copy from.
 * @return void
 */
template <typename T>
Array<T>::Array(const Array<T> &other) : _n(other._n) {
    this->_items = NULL;
    *this = other;
}

/**
 * @brief Constructor that initializes an array with a given size.
 * @tparam T Type of the elements in the array.
 * @param n The size of the array.
 * @return void
 */
template <typename T>
Array<T>::Array(const unsigned int &n) : _n(n) {
    this->_items = new T[this->_n]();
}

/**
 * @brief Destructor that cleans up the allocated memory.
 * @tparam T Type of the elements in the array.
 */
template <typename T>
Array<T>::~Array() {
    delete[] this->_items;
}

/**
 * @brief Assignment operator that assigns one array to another.
 * @tparam T Type of the elements in the array.
 * @param other The array to assign from.
 * @return Reference to the assigned array.
 */
template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &other) {
    if (this == &other) 
        return *this;
    delete[] this->_items;
    this->_n = other._n;
    this->_items = new T[this->_n]();
    for (unsigned int i = 0; i < this->_n; i++) {
        this->_items[i] = other._items[i];
    }
    return *this;
}

/**
 * @brief Subscript operator that provides access to array elements.
 * @tparam T Type of the elements in the array.
 * @param index The index of the element to access.
 * @return Reference to the accessed element.
 * @throws IndexOutOfBoundException if the index is out of bounds.
 */
template <typename T>
T& Array<T>::operator[](const unsigned int &index) {
    if (index >= this->_n)
        throw Array<T>::IndexOutOfBoundException();
    return this->_items[index];
}

/**
 * @brief Returns the size of the array.
 * @tparam T Type of the elements in the array.
 * @return Size of the array.
 */
template <typename T>
unsigned int Array<T>::size() const {
    return this->_n;
}

/**
 * @brief Returns an error message for out-of-bounds access.
 * @tparam T Type of the elements in the array.
 * @return Error message string.
 */
template <typename T>
const char *Array<T>::IndexOutOfBoundException::what() const throw() {
    return "Index is out of bound";
}
