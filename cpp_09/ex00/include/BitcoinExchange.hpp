/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 19:07:11 by vvoronts          #+#    #+#             */
/*   Updated: 2026/01/19 19:08:32 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

/**
 * @class BitcoinExchange
 * @brief A class to handle Bitcoin exchange rate calculations based on input
 * files.
 * @details This class provides functionality to read a database of Bitcoin
 * exchange rates and process input files to calculate the value of Bitcoin on
 * given dates.
 */
class BitcoinExchange {
    public:
        static std::map<std::string, std::string> database;
        static void calculate(const std::string& filepath);

    private:
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        BitcoinExchange();
        ~BitcoinExchange();
};

#endif
