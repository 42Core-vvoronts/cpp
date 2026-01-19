/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 14:24:34 by vvoronts          #+#    #+#             */
/*   Updated: 2026/01/19 14:24:35 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <algorithm> // for std::find
#include <stdexcept> // for std::out_of_range

/**
 * @brief Searches for an integer in a given container.
 * @param c The container to search in.
 * @param i The integer to search for.
 * @return An iterator to the found integer.
 * @throws std::out_of_range if the integer is not found in the container.
 */
template <typename T>
typename T::const_iterator easyfind(const T &c, const int i){
    typename T::const_iterator it;
    // Use std::find to search for the integer in the container
    it = std::find(c.begin(), c.end(), i);
    if (it == c.end())
        throw std::out_of_range("Item not found in container.");
    return it;
}
