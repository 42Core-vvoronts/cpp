#include "Database.hpp"
#include "DataHandler.hpp"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <stdexcept>

Database::Database() {}
Database::~Database() {}
Database::Database(const Database& other) { *this = other; }

Database& Database::operator=(const Database& other) {
    if (this != &other) {
        this->_data = other._data;
    }
    return *this;
}

/**
 * @brief Load the database from a CSV file.
 * @param filepath Path to the database CSV file.
 * @details This function reads the CSV file line by line, splits each line
 * into date and exchange rate, and stores them in the internal map.
 */
void Database::load(const std::string& filepath) {
    std::ifstream infile(filepath.c_str());
    if (infile.fail()) {
        std::cerr << "Error: could not open database file." << std::endl;
        std::exit(EXIT_FAILURE);
    }

    std::string line, key, value;
    std::getline(infile, line); // Skip header

    while (std::getline(infile, line)) {
        DataHandler::split(line, ',', key, value);
        DataHandler::trim(key);
        DataHandler::trim(value);
        if (!key.empty())
            _data[key] = value;
    }
    infile.close();
}

/**
 * @brief Find the closest date in the database that is less than or equal to
 * the given date.
 * @param date The date to compare.
 * @return The closest date as a string. If no such date exists, returns an
 * empty string.
 */
std::string Database::findClosestDate(const std::string& date) {
    if (_data.empty()) return "";

    std::map<std::string, std::string>::iterator it = _data.upper_bound(date);
    
    // If iterator is at begin, it means all dates in DB are > input date.
    // No lower date exists.
    if (it == _data.begin()) return ""; 
    
    it--; 
    return it->first;
}

/**
 * @brief Retrieve the exchange rate for a given date.
 * @param date The date for which to retrieve the exchange rate.
 * @return The exchange rate as a float. If the exact date is not found,
 * the closest earlier date's rate is returned.
 */
float Database::getExchangeRate(const std::string& date) {
    if (_data.count(date)) {
        return DataHandler::stringToFloat(_data[date]);
    }
    std::string closest = findClosestDate(date);
    if (closest.empty()) {
        throw std::string("date too old, no data available => " + date);
    }
    return DataHandler::stringToFloat(_data[closest]);
}