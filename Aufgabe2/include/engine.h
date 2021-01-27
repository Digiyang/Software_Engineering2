#pragma once

#include <string>
#include <exception>
#include "operators.h"
using namespace std;

class ParameterError : public exception
{
    string reason_;
public:
    ParameterError(string reason) : reason_(reason) {};
    virtual const char * what() const throw() {
        string msg("Aborting operation due to ");
        return msg.append(reason_).c_str();
    }
};

// Interface for your engine implementation
class Engine
{
public:

    virtual void clear() = 0;

    virtual void pending(Operator _operator) = 0;

    virtual double evaluateBinary(double operand) = 0;

    virtual double evaluateUnary(Operator _operator, double operand) = 0;

    virtual void clearMemory() = 0;

    virtual double memory() const = 0;

    virtual void memory(double) = 0;
};

