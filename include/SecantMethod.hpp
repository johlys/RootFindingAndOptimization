#ifndef SECANTMETHOD_HPP
#define SECANTMETHOD_HPP

#include "RootFinder.hpp"

class SecantMethod : public RootFinder {
public:
    SecantMethod(std::function<double(double)> func);

    double findRoot(double initialGuess1, double initialGuess2, double tolerance) override;

    double findRoot(double initialGuess, double tolerance) override {
        throw std::runtime_error("Use findRoot with two initial guesses for the Secant method");
    }
};

#endif
