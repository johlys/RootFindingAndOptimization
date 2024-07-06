#ifndef BISECTIONMETHOD_HPP
#define BISECTIONMETHOD_HPP

#include "RootFinder.hpp"

class BisectionMethod : public RootFinder {
public:
    // Constructor to accept the function
    BisectionMethod(std::function<double(double)> func);

    // Method to find the root with two initial guesses
    double findRoot(double initialGuess1, double initialGuess2, double tolerance) override;

    // Overridden method that throws an exception for single initial guess
    double findRoot(double initialGuess, double tolerance) override {
        throw std::runtime_error("Use findRoot with two initial guesses for the Bisection method");
    }
};

#endif
