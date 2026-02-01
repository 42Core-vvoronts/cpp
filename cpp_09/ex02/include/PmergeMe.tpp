#ifndef PMERGEME_TPP
#define PMERGEME_TPP

#include "PmergeMe.hpp"

/**
 * @brief Prints the contents of a container to standard output.
 * Limits output to first 20 elements for large containers.
 * @param c The container to print.
 */
template <typename Container>
void PmergeMe::printContainer(const Container& c) {
    typename Container::const_iterator it;
    int limit = 0;
    for (it = c.begin(); it != c.end(); ++it) {
        std::cout << *it << " ";
        if (++limit > 20) { // Limit output for large lists
            std::cout << "[...]";
            break;
        }
    }
    std::cout << std::endl;
}

/**
 * @brief Inserts a value into a sorted container using binary search to find the correct position.
 * @param sorted The sorted container where the value will be inserted.
 * @param val The value to insert.
 * @param range The range within the container to consider for insertion.
 */
template <typename Container>
void PmergeMe::binarySearchInsert(Container& sorted, int val, size_t range) {
    size_t left = 0;
    size_t right = range; 
    
    // Binary Search
    while (left < right) {
        size_t mid = left + (right - left) / 2;
        if (sorted[mid] < val)
            left = mid + 1;
        else
            right = mid;
    }
    // Insert at the found position
    sorted.insert(sorted.begin() + left, val);
}

 /**
 * @brief Performs the Ford-Johnson (Merge-Insertion) sorting algorithm on the container.
 * @param container The container to sort.
 * 
 * It operates by pairing elements, 
 * recursively sorting the "winners" (main chain), and inserting "losers" (pend chain) 
 * using binary insertion guided by Jacobsthal numbers to minimize comparisons.
 * 
 * The Ford-Johnson Algorithm:
 * Step 1: Pairing & Comparison
 *  - Create pairs (winner, loser) a > b, 
 *  - a is winner, b is loser
 *  - If odd, set aside the last element (straggler)
 * Step 2: Recursive Sorting (Main Chain)
 *  - Take all winners and recursively sort them using the same algorithm
 *  - Once recursion unwinds, we have a sorted main chain of winners
 *  - The Losers are still paired with their specific Winners logically
 * Step 3: Insertion (Pend Chain)
 *  - Insert the Losers back into the Main Chain using Binary Search
 *  - Search for index of its Winner in sorted main chain
 *  - Jacobsthal-Guided Insertion to optimize
 */
template <typename Container>
void PmergeMe::mergeInsertionSort(Container& container) {
    typedef typename Container::value_type T;
    size_t n = container.size();
    
    // Recursion Base Case when all sorted
    if (n <= 1) return;

    // ------------------------------------------------
    // 1. PAIRING
    // ------------------------------------------------
    Container winners;
    Container losers;
    T straggler = 0;

    // Handle Straggler if odd
    if (n % 2 != 0) {
        straggler = container.back();
        container.pop_back();
    }
    // Pair up and find winners
    typename Container::iterator it = container.begin();
    while (it != container.end()) {
        T a = *it++;
        T b = *it++;
        if (a > b) {
            winners.push_back(a);
            losers.push_back(b);
        } else {
            winners.push_back(b);
            losers.push_back(a);
        }
    }
    // Store pairs locally to restore association after recursion
    std::vector<std::pair<T, T> > localPairs;
    for (size_t i = 0; i < winners.size(); ++i) {
        localPairs.push_back(std::make_pair(winners[i], losers[i]));
    }

    // ------------------------------------------------
    // 2. MAIN CHAIN
    // ------------------------------------------------
    mergeInsertionSort(winners);

    // ------------------------------------------------
    // 3. PEND CHAIN
    // ------------------------------------------------
    Container reorderedLosers;
    reorderedLosers.resize(winners.size());
    std::vector<bool> pairUsed(localPairs.size(), false);
    
    // Re-map losers to the new sorted order of winners
    for (size_t i = 0; i < winners.size(); ++i) {
        for (size_t j = 0; j < localPairs.size(); ++j) {
            if (!pairUsed[j] && localPairs[j].first == winners[i]) {
                reorderedLosers[i] = localPairs[j].second;
                pairUsed[j] = true;
                break;
            }
        }
    }

    // Now insert losers into winners
    // 1. Insert the first loser (it belongs to the smallest winner)
    container = winners; // Main chain
    container.insert(container.begin(), reorderedLosers[0]);

    // 2. Insert rest using Jacobsthal
    std::vector<size_t> jacob = generateJacobsthal(reorderedLosers.size());
    
    // Iterate Jacobsthal groups
    for (size_t k = 1; k < jacob.size(); ++k) {
        size_t rightBound = jacob[k];
        size_t leftBound = jacob[k-1];

        if (rightBound > reorderedLosers.size()) 
            rightBound = reorderedLosers.size();

        // Iterate from rightBound down to leftBound + 1
        for (size_t i = rightBound; i > leftBound; --i) {
            size_t idx = i - 1;
            T valToInsert = reorderedLosers[idx];
            typename Container::iterator limitIt = std::lower_bound(container.begin(), container.end(), winners[idx]);
            size_t limitIndex = std::distance(container.begin(), limitIt);
            // Insert using binary search within the limit
            binarySearchInsert(container, valToInsert, limitIndex);
        }
    }
    // Insert Straggler if it exists
    if (straggler != 0) {
        binarySearchInsert(container, straggler, container.size());
    }
}

/**
 * @brief Sorts the container using merge-insertion sort and measures the time taken.
 * @param container The container to sort.
 * @return The time taken in microseconds.
 */
template <typename Container>
double PmergeMe::sortAndMeasure(Container& container) {
    // Start time measurement
    std::clock_t start = std::clock();
    // Perform sorting
    mergeInsertionSort(container);
    // End time measurement
    std::clock_t end = std::clock();
    // Return microseconds
    return static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000.0;
}

#endif