#include "NewtonRaphson.hpp"
#include <cmath>
#include <stdexcept>

NewtonRaphson::NewtonRaphson(std::function<double(double)> func, std::function<double(double)> derivativeFunc)
    : RootFinder(func), derivative(derivativeFunc) {}

double NewtonRaphson::findRoot(double initialGuess, double tolerance) {
    double x0 = initialGuess;
    double x1 = x0 - function(x0) / derivative(x0);

    while (std::fabs(x1 - x0) >= tolerance) {
        x0 = x1;
        x1 = x0 - function(x0) / derivative(x0);

        if (derivative(x0) == 0.0) {
            throw std::runtime_error("Derivative is zero, cannot continue Newton-Raphson method");
        }
    }
    return x1;
}
