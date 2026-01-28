/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 14:28:49 by vvoronts          #+#    #+#             */
/*   Updated: 2026/01/19 14:28:50 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iostream>

/**
 * @class Span
 * @brief A class to manage a collection of integers and compute spans.
 * 
 * Bassically it is wrapping around a vector of integers, with addons:
 * - limit on how many integers can be stored
 * - ability to add numbers (both manually and using iterators)
 * - ability to compute shortest and longest span between numbers
 * - exception handling for edge cases
 */
class Span {
    private:
        unsigned int     N;
        std::vector<int> _payload;
    public:
        Span();
        ~Span();
        Span(const Span& other);
        Span(unsigned int N);

        Span& operator=(const Span& other);

        // Member functions
        unsigned int    size() const;
        const           std::vector<int>& getPayload() const;
        int             shortestSpan();
        int             longestSpan();

        /**
         * @brief Adds multiple numbers to the Span payload using iterators.
         * 
         * Subject: "it would be wonderful to fill your Span using a range of iterators.
         * Making thousands of calls to addNumber() is so annoying. Implement a member function
         * to add multiple numbers to your Span in a single call."
         * 
         * @param begin The beginning iterator of the range.
         * @param end The ending iterator of the range.
         * @throws FullSpanException if adding the range would exceed the capacity.
         */
        template <typename T>
        void addNumber(T begin, T end) {
            // Check if adding the range would exceed capacity
            if (_payload.size() + std::distance(begin, end) > N)
                throw FullSpanException();
            _payload.insert(_payload.end(), begin, end);
        }

        void            addNumber(const int n); // Single number add

        // Exception classes
        class FullSpanException : public std::exception {
        public:
            virtual const char* what() const throw();
        };

        class RangeTooSmallException : public std::exception {
        public:
            virtual const char* what(void) const throw();
        };
};

std::ostream& operator <<(std::ostream& out, const Span& span);
#endif
