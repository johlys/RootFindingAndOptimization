#include "BisectionMethod.hpp"
#include <cmath>
#include <stdexcept>

BisectionMethod::BisectionMethod(std::function<double(double)> func) : RootFinder(func) {}

double BisectionMethod::findRoot(double initialGuess1, double initialGuess2, double tolerance) {
    double a = initialGuess1;
    double b = initialGuess2;
    double c;

    if (function(a) * function(b) >= 0) {
        throw std::runtime_error("The function must have different signs at the endpoints of the interval");
    }

    while ((b - a) >= tolerance) {
        c = (a + b) / 2;

        if (function(c) == 0.0 || (b - a) / 2 < tolerance) {
            return c;
        }

        if (function(c) * function(a) < 0) {
            b = c;
        } else {
            a = c;
        }
    }
    return c;
}