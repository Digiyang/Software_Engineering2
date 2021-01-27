/*
 * Simo Samardzic
 * Moez Rjiba
 * Links: https://en.cppreference.com/w/cpp/language/override
 *
 */


#pragma once
#include "engine.h"

class calculation: public Engine
{
private:
    // Intern encapsulation
    double accumulator_;
    Operator pendingOperator_;
    double memory_;
public:
    calculation();
    ~calculation(){}

    // Clears the engine state, but not the memory value
    virtual void clear() override;

    // Store a binary operator for usage in next evaluation
    virtual void pending(Operator _operator) override;

    // Evaluate pending binary operator with given operand
    // May throw a ParameterError exceptio
    virtual double evaluateBinary(double operand) override;

    // Evaluate given unary operator and operand
    // May throw a ParameterError exception
    virtual double evaluateUnary(Operator _operator, double operand) override;

    // Clear the memory value
    virtual void clearMemory() override;

    // Retrieve the memory value
    virtual double memory() const override;

    // Store given value in memory
    virtual void memory(double) override;
};
