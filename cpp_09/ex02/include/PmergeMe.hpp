#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <string>
#include <algorithm>
#include <ctime>
#include <climits>
#include <cstdlib>

/**
 * @class PmergeMe Class
 * @brief Implements the Ford-Johnson (Merge-Insertion) sorting algorithm
 * 
 * This class provides static methods to run the sorting algorithm on
 * sequences of positive integers provided via command-line arguments.
 * It includes input validation, duplicate checking, and performance measurement.
 * 
 * Containers used: std::vector and std::deque.
 * 
 */
class PmergeMe {
    public:
        static void run(int argc, char **argv);

    private:
        PmergeMe();
        PmergeMe(const PmergeMe &src);
        PmergeMe &operator=(const PmergeMe &src);
        ~PmergeMe();

        static std::vector<size_t> generateJacobsthal(size_t n);

        // Display helper
        template <typename Container>
        static void printContainer(const Container& c);
        // Binary Search Insertion
        template <typename Container>
        static void binarySearchInsert(Container& sorted, int val, size_t range);
        // Main Ford-Johnson Algorithm
        template <typename Container>
        static void mergeInsertionSort(Container& container);
        // Sort and Measure Time
        template <typename Container>
        static double sortAndMeasure(Container& container);
};

#include "PmergeMe.tpp"

#endif