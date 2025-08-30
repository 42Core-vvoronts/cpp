#ifndef __SAMPLE_HPP__
# define __SAMPLE_HPP__

class Sample
{
    public:
        Sample(void);                     // Default Class Constructor
        Sample(Sample const &src);        // Copy Class Constructor
        ~Sample(void);                    // Class Deconstructor

        Sample    &operator=(Sample const &rhs);    // Assign operator overload

        virtual    ~Sample(void); // Class Deconstructor
    private:
};

#endif // **************************************************** __SAMPLE_HPP__ //

#include "Sample.hpp"

// Default Class Constructor
Sample::Sample(void)
{
    return ;
}

// Copy Class Constructor
Sample::Sample(Sample const &src)
{
    *this = src;
}

// Class Deconstructor
Sample::~Sample(void)
{
    return ;
}

// Assign Operator Overlaod
Sample    &Sample::operator=(Sample const &rhs)
{
    // Make your Assignment here
    return (*this);
}


#!/bin/bash
TEMPLATE_PATH=<Where you store Sample.cpp && Sample.hpp>

for CLASS in "$@"
do
    sed "s/Sample/${CLASS}/g" ${TEMPLATE_PATH}Sample.cpp > ${CLASS}.cpp
    sed "s/Sample/${CLASS}/g" ${TEMPLATE_PATH}Sample.hpp > ${CLASS}.hpp
    sed -i "s/SAMPLE/${CLASS^^}/g" ${CLASS}.hpp
done