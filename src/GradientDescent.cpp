#include "GradientDescent.hpp"
#include <cmath>
#include <stdexcept>

GradientDescent::GradientDescent(std::function<double(double)> func, std::function<double(double)> derivativeFunc)
    : RootFinder(func), derivative(derivativeFunc) {}

double GradientDescent::findMinimum(double initialX, double learningRate, double tolerance, int maxIterations) {
    double x = initialX;
    int iterations = 0;

    while (iterations < maxIterations) {
        double grad = derivative(x);
        if (std::abs(grad) < tolerance) {
            break;
        }
        x = x - learningRate * grad;
        iterations++;
    }

    return x;
}
