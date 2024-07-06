#include <iostream>
#include <functional>
#include "SecantMethod.hpp"
#include "BisectionMethod.hpp"
#include "NewtonRaphson.hpp"
#include "GradientDescent.hpp"

enum Method {
    SECANT,
    BISECTION,
    NEWTON_RHAPSON,
    GRADIENT_DESCENT
};

int main() {
    // Define the function f(x) and its derivative f'(x)
    std::function<double(double)> function = [](double x) -> double {
        return 2 * x * x - 2 * x;
    };
    std::function<double(double)> derivative = [](double x) -> double {
        return 4 * x - 2;
    };

    // Set the method to use here
    Method method = GRADIENT_DESCENT;

    SecantMethod secantMethod(function);
    BisectionMethod bisectionMethod(function);
    NewtonRaphson newtonRaphson(function, derivative);
    GradientDescent gradientDescent(function, derivative);

    // Set initial guesses and tolerance
    double initialGuess1 = 0.0;
    double initialGuess2 = 2.0;
    double tolerance = 0.0001;

    double result;

    try {
        switch (method) {
            case SECANT: {
                result = secantMethod.findRoot(initialGuess1, initialGuess2, tolerance);
                std::cout << "Root found using Secant method: " << result << std::endl;
                break;
            }
            case BISECTION: {
                result = bisectionMethod.findRoot(initialGuess1, initialGuess2, tolerance);
                std::cout << "Root found using Bisection method: " << result << std::endl;
                break;
            }
            case NEWTON_RHAPSON: {
                result = newtonRaphson.findRoot(1.0, tolerance); // Using 1.0 as the initial guess
                std::cout << "Root found using Newton-Raphson method: " << result << std::endl;
                break;
            }
            case GRADIENT_DESCENT: {
                double initialX = 2.0;
                double learningRate = 0.1;
                int maxIterations = 1000;

                result = gradientDescent.findMinimum(initialX, learningRate, tolerance, maxIterations);
                std::cout << "Minimum found using Gradient Descent: " << result << std::endl;
                break;
            }
            default:
                std::cerr << "Invalid method selection." << std::endl;
                return 1;
        }
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}

