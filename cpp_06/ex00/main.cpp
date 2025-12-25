/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoronts <vvoronts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:52:38 by vvoronts          #+#    #+#             */
/*   Updated: 2025/12/25 09:52:25 by vvoronts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cstdlib>
#include <iostream>

struct TestCase {
	const char *description;
	const char *literal;
};

static const TestCase testCases[] = {
	{"    Printable Char", "*"},
	{"    Two Printable Chars", "**"},
	{"    Two Printable Chars", "-*"},
	{"    Positive int", "42"},
	{"    Negative int", "-42"},
	{"    Float notation", "42.0f"},
	{"    Float notation", "42.3f"},
	{"    Large Double", "100000000000000000000000000000000"},
	{"    Char Overflow", "256"},
	{"    Int Overflow", "2147483648"},
	{"    Float Overflow", "3400000000000000000000000000000000000000"},
	{"    -inff", "-inff"},
	{"    +inff", "+inff"},
	{"    nanf", "nanf"},
	{"    -inf", "-inf"},
	{"    +inf", "+inf"},
	{"    Typo in nanff", "nanff"}
};

static const int testCasesCount = sizeof(testCases) / sizeof(testCases[0]);

int main(int argc, char** argv) {
    if (argc == 2) {
        std::string literal = argv[1];
        ScalarConverter::convert(literal);
    } else {
        std::cout << "----------------------------" << std::endl;
        for (int i = 0; i < testCasesCount; ++i) {
            std::cout << testCases[i].description << ": " << testCases[i].literal << std::endl;
            std::cout << "----------------------------" << std::endl;
            ScalarConverter::convert(testCases[i].literal);
            std::cout << "\n----------------------------" << std::endl;
        }
        std::cout << "\033[34m:) You did not provide any input, \nsome test cases were run\033[0m" << std::endl;
        std::cout << "----------------------------" << std::endl;
    }
    return 0;
}

