/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 14:28:53 by vvoronts          #+#    #+#             */
/*   Updated: 2026/01/19 14:35:00 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#include <algorithm>
#include <ctime> // for std::rand
#include <iostream>
#include <limits> // for std::numeric_limits
#include <vector>

Span::Span() : N(0) {};
Span::~Span() {};
Span::Span(const Span& other) : N(other.N), _payload(other._payload) {}
Span::Span(unsigned int N) : N(N) {}

Span& Span::operator=(const Span& other) {
    if (this == &other) 
        return *this;
    this->N = other.N;
    this->_payload = other._payload;
    return *this;
}

/**
 * @brief Adds a number to the Span payload. Overloaded to add a single integer.
 * 
 * Subject: 
 * "Function to add a single number to the Span. It will be used in order to fill it. 
 * Any attempt to add a new element if there 
 * are already N elements stored should throw an exception.""
 * 
 * @param n The number to add.
 * @throws FullSpanException if the payload is already full.
 */
void Span::addNumber(const int n) {
    if (this->_payload.size() == this->N) 
        throw FullSpanException();
    this->_payload.push_back(n);
}

/**
 * @brief Computes the shortest span between any two numbers in the payload.
 * 
 * @return The shortest span.
 * @throws RangeTooSmallException if there are less than two numbers in the payload.
 */
int Span::shortestSpan() {
    if (this->_payload.size() < 2)
        throw RangeTooSmallException();

    int min = std::numeric_limits<int>::max();
    std::sort(this->_payload.begin(), this->_payload.end());
    std::vector<int>::const_iterator curr;
    for (curr = this->_payload.begin() + 1; curr != this->_payload.end(); curr++) {
        int diff = *curr - *(curr - 1);
        if (diff < min) min = diff;
    }
  return min;
}

/**
 * @brief Computes the longest span between any two numbers in the payload.
 * @return The longest span.
 * @throws RangeTooSmallException if there are less than two numbers in the payload.
 */
int Span::longestSpan() {
  if (this->_payload.size() < 2)
    throw RangeTooSmallException();
  return *std::max_element(this->_payload.begin(), this->_payload.end()) -
         *std::min_element(this->_payload.begin(), this->_payload.end());
}

const char* Span::FullSpanException::what() const throw() {
  return "Span is full";
}

const char* Span::RangeTooSmallException::what() const throw() {
  return "Span has less then 2 items";
}

unsigned int Span::size() const {
    return this->N;
}

const std::vector<int>& Span::getPayload() const {
    return this->_payload;
}

/**
 * @brief Overloads the output stream operator for Span.
 * @param out The output stream.
 * @param span The Span object to output.
 * @return The output stream.
 */
std::ostream& operator<<(std::ostream& out, const Span& span) {
    // Output each number in the Span payload
    for (unsigned int i = 0; i < span.getPayload().size(); i++) {
        out << span.getPayload()[i] << " ";
    }
    out << std::endl;
    return out;
}
