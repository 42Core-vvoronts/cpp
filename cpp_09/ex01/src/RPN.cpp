#include "RPN.hpp"
#include <iostream>
#include <sstream>
#include <stack>

RPN::RPN() {}
RPN::RPN(const RPN &src) { (void)src; }
RPN &RPN::operator=(const RPN &src) {
    (void)src;
    return *this;
}
RPN::~RPN() {}

/**
 * @brief Perform computation based on the operator and stack values.
 * @param stack The stack containing operands.
 * @param opr The operator to apply.
 * This function pops the top two values from the stack, applies the operator,
 * and pushes the result back onto the stack. It throws errors for invalid
 * sequences and division by zero.
 */
static void compute(std::stack<int> &stack, const char opr) {
    if (stack.size() < 2) 
        throw "Error: not valid sequence";
    int first = stack.top();
    stack.pop();
    int second = stack.top();
    stack.pop();
    switch (opr) {
    case '+':
        stack.push(first + second);
        break;
    case '-':
        stack.push(second - first);
        break;
    case '*':
        stack.push(first * second);
        break;
    case '/':
        if (first == 0) 
            throw "Error: division by zero";
        stack.push(second / first);
        break;
    }
}

static bool isValidDigit(const char digit) { 
    return (std::isdigit(digit));
}

static bool isValidOperator(const char opr) {
    static const std::string operators = "+-/*";
    if (operators.find(opr) == std::string::npos)
        throw "Error: not valid operator";
    return true;
}


/**
 * @brief Calculate the result of a Reverse Polish Notation expression.
 * @param expr The RPN expression as a string.
 * This function evaluates the RPN expression provided in the string `expr`
 * and prints the result to the standard output. It uses a stack to perform the
 * calculations and handles errors for invalid sequences and division by zero.
 */
void RPN::calculate(const std::string &expr) {
    std::stack<int> stack;
    std::stringstream stream(expr);
    char item = '\0';

    try {
        while (stream >> item) {
            if (isValidDigit(item)) {
                stack.push(item - '0');
            } else if (isValidOperator(item)) {
                compute(stack, item);
            }
        }
        if (stack.size() != 1) throw "Error: not valid sequence";
        std::cout << stack.top() << std::endl;
    } catch (const char *str) {
        std::cerr << str << std::endl;
    }
}
