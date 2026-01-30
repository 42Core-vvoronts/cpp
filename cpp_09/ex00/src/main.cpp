#include "BitcoinExchange.hpp"
#include <iostream>
#include <cstdlib>

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Usage: ./btc <input_file_path>" << std::endl;
        return EXIT_FAILURE;
    }

    BitcoinExchange app;
    app.loadDatabase("data.csv");
    app.run(argv[1]);

    return EXIT_SUCCESS;
}