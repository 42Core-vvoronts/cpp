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
 */
class Span {
    private:
        unsigned int N;
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
        void            addNumber(const int n);
        int             shortestSpan();
        int             longestSpan();
        void            addMultipleNumbers();

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
#endif  // SPAN_HPP
