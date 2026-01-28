#include <iostream>

#include "Span.hpp"

int main() {
  // SUBJECT TEST
  /* Should output:
    $> ./ex01
    2
    14
    $>*/
  std::cout << "--- Test from subject (expected 2 and 14) ---" << std::endl;
  {
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    std::cout << std::endl;
  }

  // ADDITIONAL TESTS
  {
    std::cout << "--- Test 10,000 numbers (Iterator Add) ---" << std::endl;
    try {
        // Create a large vector of numbers
        std::vector<int> bigVector;
        for (int i = 0; i < 10000; ++i) {
            bigVector.push_back(i * 3); // Spans will be 3 and 29997
        }
        // Create a Span
        Span sp = Span(10000);
        sp.addNumber(bigVector.begin(), bigVector.end());

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    } catch (const std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;
  }

  {
    std::cout << "--- Test Small Range (Manual add) ---" << std::endl;
    Span sp = Span(5);
    sp.addNumber(0);
    sp.addNumber(3);
    sp.addNumber(42);
    
    std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest: " << sp.longestSpan() << std::endl;
    std::cout << std::endl;
  }

  {
    std::cout << "--- Test Exception: Not enough elements ---" << std::endl;
    Span sp = Span(5);
    sp.addNumber(42);
    try {
      std::cout << sp.shortestSpan() << std::endl;
    } catch (const std::exception &e) {
      std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;
  }

  {
    std::cout << "--- Test Exception: Span Full ---" << std::endl;
    Span sp = Span(2);
    try {
      sp.addNumber(1);
      sp.addNumber(2);
      sp.addNumber(3); // This should throw
    } catch (const std::exception &e) {
      std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;
  }
  return 0;
}
