#ifndef NEWTONRAPHSON_HPP
#define NEWTONRAPHSON_HPP

#include "RootFinder.hpp"

class NewtonRaphson : public RootFinder {
public:
    NewtonRaphson(std::function<double(double)> func, std::function<double(double)> derivativeFunc);

    double findRoot(double initialGuess, double tolerance) override;

private:
    std::function<double(double)> derivative;
};

#endif
