#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <map>
#include <string>

/**
 * @class Database
 * @brief Represents a database of Bitcoin exchange rates.
 * @details This class provides functionality to load exchange rates from a CSV
 * file and retrieve exchange rates based on dates.
 * Map is used to store date-rate pairs for efficient lookup.
 */
class Database {
    public:
        Database();
        Database(const Database& other);
        Database& operator=(const Database& other);
        ~Database();

        void    load(const std::string& filepath);
        float   getExchangeRate(const std::string& date);

    private:
        std::map<std::string, std::string>  _data;
        std::string                         findClosestDate(const std::string& date);
};

#endif