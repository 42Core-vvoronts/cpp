#include "PmergeMe.hpp"

// Orthodox Canonical Form
PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe &src) { (void)src; }
PmergeMe &PmergeMe::operator=(const PmergeMe &src) { (void)src; return *this; }
PmergeMe::~PmergeMe() {}

/**
 * @brief Jacobsthal Sequence Generator
 * @param n The number of Jacobsthal numbers to generate.
 * @return A vector containing the Jacobsthal numbers.
 */
std::vector<size_t> PmergeMe::generateJacobsthal(size_t n) {
    std::vector<size_t> jacob;
    jacob.push_back(1); // J(1)
    jacob.push_back(3); // J(3) because J(2)=1 is covered by range logic
    
    // J(n) = J(n-1) + 2*J(n-2)
    // Sequence: 0, 1, 1, 3, 5, 11, 21, 43...
    // We want indices: 1, 3, 5, 11...
    size_t last = 3;
    size_t prev = 1;
    
    while (last < n) {
        size_t next = last + 2 * prev;
        jacob.push_back(next);
        prev = last;
        last = next;
    }
    return jacob;
}

/**
 * @brief Runs the Ford-Johnson sorting algorithm on input from command-line arguments.
 * @param argc Argument count.
 * @param argv Argument vector containing the sequence to sort.
 * 
 * std::vector: Contiguous memory. 
 * Faster cache access, but inserting in the middle requires shifting 
 * all subsequent elements (expensive copy).
 * 
 * std::deque: Segmented array. 
 * Slower access than vector, 
 * but inserting in the middle is generally cheaper than vector for large types 
 * (though for integers, vector usually wins due to CPU caching).
 */
void PmergeMe::run(int argc, char **argv) {
    std::vector<int> vec;
    std::deque<int> deq;

    // Parsing
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        // Empty check
        if (arg.empty()) continue;
        // Digit check
        size_t start = 0;
        if (arg[0] == '+') start = 1;
        for (size_t j = start; j < arg.size(); ++j) {
            if (!std::isdigit(arg[j]))
                throw "Error: Invalid character in input.";
        }
        // Convert
        long val = std::atol(arg.c_str());
        if (val < 0) throw "Error: Negative number.";
        if (val > INT_MAX) throw "Error: Number too large.";

        // Duplicate Check (Using vector for check is sufficient)
        if (std::find(vec.begin(), vec.end(), static_cast<int>(val)) != vec.end())
            throw "Error: Duplicate number.";

        vec.push_back(static_cast<int>(val));
        deq.push_back(static_cast<int>(val));
    }

    // Output Before
    std::cout << "Before: ";
    printContainer(vec);

    // Sort & Time Vector and Deque
    double timeVec = sortAndMeasure(vec);
    double timeDeq = sortAndMeasure(deq);

    // Output After
    std::cout << "After:  ";
    printContainer(vec);
    // Times
    std::cout << "Time to process a range of " << vec.size() 
              << " elements with std::vector : " << timeVec << " us" << std::endl;
    std::cout << "Time to process a range of " << deq.size() 
              << " elements with std::deque  : " << timeDeq << " us" << std::endl;
}