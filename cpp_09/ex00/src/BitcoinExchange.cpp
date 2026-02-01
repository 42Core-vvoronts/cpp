#include "BitcoinExchange.hpp"
#include "DataHandler.hpp"
#include <fstream>
#include <iostream>
#include <algorithm> // for std::find_if
#include <cstdlib>   // for std::exit, std::atof, std::strtod
#include <ctime>     // for struct tm

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::~BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) { *this = other; }

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        this->_db = other._db;
    }
    return *this;
}

/**
 * @brief Load the Bitcoin exchange rate database from a CSV file.
 * @param dbPath Path to the database CSV file.
 */
void BitcoinExchange::loadDatabase(const std::string& dbPath) {
    _db.load(dbPath);
}

/**
 * @brief Process the input file and calculate Bitcoin exchange values.
 * @param inputPath Path to the input file containing dates and values.
 * @details This function reads the input file line by line, validates the
 * dates and values, retrieves the corresponding exchange rates from the
 * database, and prints the calculated results.
 */
void BitcoinExchange::run(const std::string& inputPath) {
    // 1. Open Input
    std::ifstream infile(inputPath.c_str());
    if (infile.fail()) {
        std::cout << "Error: could not open file." << std::endl;
        std::exit(EXIT_FAILURE);
    }

    // 2. Process Line by Line
    std::string line, key, value;
    std::getline(infile, line);

    while (std::getline(infile, line)) {
        DataHandler::split(line, '|', key, value);
        DataHandler::trim(key);
        DataHandler::trim(value);

        try {
            // This line prevents the error on empty lines
            if (key.empty() && value.empty()) continue; // Skip empty lines
            if (key.empty() || value.empty()) 
                throw std::string("bad input => " + line);

            DataHandler::validateDate(key);
            DataHandler::validateValue(value);

            float rate = _db.getExchangeRate(key);
            float amount = DataHandler::stringToFloat(value);
            
            std::cout << key << " => " << value << " = " << (amount * rate) << std::endl;

        } catch (const std::string& msg) {
            std::cout << "Error: " << msg << std::endl;
        }
    }
    infile.close();
}