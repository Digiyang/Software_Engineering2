/*
 * Simo Samardzic
 * Moez Rjiba
 * Links: https://en.cppreference.com/w/cpp/language/override
 *
 */

#include "calculation.h"
#include <iostream>
#include <cmath>

// Calculation's constructor
calculation::calculation() : accumulator_(0.0), pendingOperator_(NONE), memory_(0.0){}

// Clears the engine state, but not the memory value
void calculation::clear()
{
    accumulator_ = 0.0;
    pendingOperator_ = NONE;
}

// Store a binary operator for usage in next evaluation
void calculation::pending(Operator _operator)
{
  pendingOperator_ = _operator;
}

// Calculates result for binary operators
double calculation::evaluateBinary(double operand) {
    switch (pendingOperator_) {
    case NONE:
        accumulator_ = operand;
        break;
    case ADD:
        accumulator_ += operand;
        break;
    case SUB:
        accumulator_ -= operand;
        break;
    case MUL:
        accumulator_ *= operand;
        break;
    case DIV:
        try
        {
            if(operand == 0.0)
                throw ParameterError("division by 0 not allowed!");
            accumulator_ /= operand;
        } catch (ParameterError & e)
        {
            std::cout << e.what() << endl;
            return 0.0;
        }
        break;
    default:
        return 0;
    }
    return accumulator_;
}

// Calculates unary operations and returns the result
double calculation::evaluateUnary(Operator _operator, double operand)
{
    double result = 0.0;

    switch(_operator) {
    case SQRT:
        try {
            if (operand < 0.0)
                throw ParameterError("sqrt of negative number");
            result = sqrt(operand);
        }  catch (ParameterError & e) {
            std::cout << e.what() << endl;
            return 0.0;
        }
        break;
    case SQUARE:
        result = pow(operand, 2.0);
        break;
    case RPROC:
        try {
            if (operand == 0.0)
                throw ParameterError("division by 0 is not allowed!");
            result = 1.0 / operand;
        }  catch (ParameterError & e) {
            std::cout << e.what() << endl;
            return 0.0;
        }
        break;
    case SIGN:
        result = -1.0 * operand;
        break;
    default:
        ;
    }
    return result;
}

// Clears the memory
void calculation::clearMemory()
{
    memory_ = 0.0;
}

// Reads and returns the memory
double calculation::memory() const
{
    return memory_;
}

// Commits input to memory
void calculation::memory(double memory)
{
    memory_ = memory;
}
