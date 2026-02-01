#ifndef RPN_HPP
#define RPN_HPP
#include <string>

/**
 * @class RPN
 * @brief A class to perform Reverse Polish Notation calculations.
 * This class provides a static method to evaluate RPN expressions.
 */
class RPN {
    public:
        static void calculate(const std::string &expr);

    private:
        RPN();
        RPN(const RPN &src);
        RPN &operator=(const RPN &src);
        ~RPN();
};

#endif
