/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 19:58:55 by vvoronts          #+#    #+#             */
/*   Updated: 2026/01/18 19:59:29 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>
#include <iostream>

/**
 * @brief Applies a function to each element of an array.
 * @param array Pointer to the first element of the array.
 * @param len Number of elements in the array.
 * @param f Function pointer to the function to be applied to each element.
 * @tparam T Type of the elements in the array.
 * @tparam F Type of the function to be applied.
 * @return void
 */
template <typename T, typename F>
void iter(T *array, const size_t &len, F (*f)){
     if (array == NULL || f == NULL)
        return;
    for (size_t i = 0; i < len; i++) {
        f(array[i]);
     }
}

/**
 * @brief Prints an item to the standard output.
 * @param item The item to be printed.
 * @tparam T Type of the item.
 * @return void
 */
template <typename T>
void printItem(const T &item){
     std::cout << item << " ";
}

/**
 * @brief Increments an item by one.
 * @param item The item to be incremented.
 * @tparam T Type of the item.
 * @return void
 */
template <typename T>
void incByOne(T &item){
    item += 1;
}
#endif
