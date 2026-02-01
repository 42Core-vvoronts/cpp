#include "PmergeMe.hpp"
#include <iostream>
#include <cstdlib>

/**
 * @brief The main entry point of the program.
 * @param argc Argumant count.
 * @param argv Argument vector containing the sequence to sort eg "./PmergeMe 3 5 9 1 4".
 * @return Exit status.
 */
int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Error: Usage: ./PmergeMe <positive integer sequence>" << std::endl;
        return EXIT_FAILURE;
    }

    try {
        PmergeMe::run(argc, argv);
    } catch (const char* e) {
        std::cerr << e << std::endl;
        return EXIT_FAILURE;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}