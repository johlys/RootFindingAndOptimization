#include "SecantMethod.hpp"
#include <cmath>
#include <stdexcept>

SecantMethod::SecantMethod(std::function<double(double)> func) : RootFinder(func) {}

double SecantMethod::findRoot(double initialGuess1, double initialGuess2, double tolerance) {
    double x0 = initialGuess1;
    double x1 = initialGuess2;
    double xn;

    while (true) {
        double f_x0 = function(x0);
        double f_x1 = function(x1);
        if (std::abs(f_x1 - f_x0) < tolerance) {
            throw std::runtime_error("Division by zero in Secant method");
        }

        xn = x1 - f_x1 * (x1 - x0) / (f_x1 - f_x0);

        if (std::abs(xn - x1) < tolerance || std::abs(function(xn)) < tolerance) {
            break;
        }

        x0 = x1;
        x1 = xn;
    }
    return xn;
}
