/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 19:56:52 by vvoronts          #+#    #+#             */
/*   Updated: 2026/01/18 19:57:20 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

/**
 * @brief Swaps the values of two variables.
 *
 * @tparam T The type of the variables to be swapped.
 * @param a Reference to the first variable.
 * @param b Reference to the second variable.
 */
template <typename T>
void swap(T &a, T &b){
    T tmp = a;
    a = b;
    b = tmp;
}

/**
 * @brief Returns the minimum of two values.
 *
 * @tparam T The type of the variables to be compared.
 * @param a Reference to the first variable.
 * @param b Reference to the second variable.
 * @return T The minimum value.
 */
template <typename T>
T min(const T &a, const T &b){
    return a < b ? a : b; 
}

/**
 * @brief Returns the maximum of two values.
 *
 * @tparam T The type of the variables to be compared.
 * @param a Reference to the first variable.
 * @param b Reference to the second variable.
 * @return T The maximum value.
 */
template <typename T>
T max(const T &a, const T &b){
    return a > b ? a : b;
}
#endif
