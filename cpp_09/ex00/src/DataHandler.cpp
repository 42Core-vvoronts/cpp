#include "DataHandler.hpp"
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstdlib>

DataHandler::DataHandler() {}
DataHandler::~DataHandler() {}
DataHandler::DataHandler(const DataHandler& other) { (void)other; }
DataHandler& DataHandler::operator=(const DataHandler& other) { (void)other; return *this; }

/**
 * @brief Check if a character is not a whitespace.
 * @param ch The character to check.
 * @return True if the character is not a whitespace, false otherwise.
 */
static inline bool is_not_space(int ch) {
    return !std::isspace(static_cast<unsigned char>(ch));
}

/**
 * @brief Trim leading and trailing whitespace from a string.
 * @param s The string to trim.
 */
void DataHandler::trim(std::string& s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), is_not_space));
    s.erase(std::find_if(s.rbegin(), s.rend(), is_not_space).base(), s.end());
}

/**
 * @brief Split a line into key and value based on a delimiter.
 * @param line The input line to split.
 * @param delim The delimiter character.
 * @param key The extracted key from the line.
 * @param value The extracted value from the line.
 */
void DataHandler::split(const std::string& line, char delim, std::string& key, std::string& value) {
    size_t delimiter_pos = line.find(delim);
    if (delimiter_pos == std::string::npos) {
        key = line;
        value = "";
        return;
    }
    key = line.substr(0, delimiter_pos);
    value = line.substr(delimiter_pos + 1);
}

/**
 * @brief Validate the date format (YYYY-MM-DD) and check for valid calendar dates.
 * @param date The date string to validate.
 * @throws std::string if the date is invalid.
 */
void DataHandler::validateDate(const std::string& date) {
    char hifen;
    std::stringstream stream(date);
    struct tm old = {}, normalized = {};
    const std::string error = "bad input => " + date;

    if (date.size() != 10) throw error;
    if (!(stream >> old.tm_year >> hifen >> old.tm_mon >> hifen >> old.tm_mday))
        throw error;
    
    old.tm_mon -= 1;
    old.tm_year -= 1900;
    normalized = old;
    mktime(&normalized);
    
    if (normalized.tm_year != old.tm_year || normalized.tm_mon != old.tm_mon || normalized.tm_mday != old.tm_mday)
        throw error;
}

/**
 * @brief Validate the value string to ensure it's a valid positive number within range.
 * @param value The value string to validate.
 * @throws std::string if the value is invalid.
 */
void DataHandler::validateValue(const std::string& value) {
    char* endptr = NULL;
    std::string error;
    const double num = std::strtod(value.c_str(), &endptr);
    
    if (*endptr != '\0') throw(error = ("bad input => " + value));
    if (num < 0) throw error = "not a positive number.";
    if (num > 1000.0) throw error = "too large a number.";
}

float DataHandler::stringToFloat(const std::string& value) {
    return static_cast<float>(std::atof(value.c_str()));
}