#ifndef DATAHANDLER_HPP
#define DATAHANDLER_HPP

#include <string>

/**
 * @class DataHandler
 * @brief A utility class for handling data operations such as trimming,
 * splitting, and validating strings.
 */
class DataHandler {
    public:
        static void   validateDate(const std::string& date);
        static void   validateValue(const std::string& value);
        static void   trim(std::string& s);
        static void   split(const std::string& line, char delim, std::string& key, std::string& value);
        static float  stringToFloat(const std::string& value);

    private:
        DataHandler();
        DataHandler(const DataHandler& other);
        DataHandler& operator=(const DataHandler& other);
        ~DataHandler();
};

#endif