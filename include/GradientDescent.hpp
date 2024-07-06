#ifndef GRADIENTDESCENT_HPP
#define GRADIENTDESCENT_HPP

#include "RootFinder.hpp"

class GradientDescent : public RootFinder {
public:
    GradientDescent(std::function<double(double)> func, std::function<double(double)> derivativeFunc);

    double findMinimum(double initialX, double learningRate, double tolerance, int maxIterations);

    double findRoot(double initialGuess, double tolerance) override {
        throw std::runtime_error("Use findMinimum with GradientDescent");
    }

private:
    std::function<double(double)> derivative;
};

#endif
