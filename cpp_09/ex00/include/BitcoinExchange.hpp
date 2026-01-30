#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include "Database.hpp"
#include <string>

/**
 * @class BitcoinExchange
 * @brief Represents a Bitcoin exchange application that processes input files
 * to calculate Bitcoin exchange values based on a database of historical rates. 
 */
class BitcoinExchange {
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange();

        void        loadDatabase(const std::string& dbPath);
        void        run(const std::string& inputPath);

    private:
        Database    _db;
};

#endif