#ifndef ROOTFINDER_HPP
#define ROOTFINDER_HPP

#include <functional>

class RootFinder {
public:
    RootFinder(std::function<double(double)> func) : function(func) {}

    virtual double findRoot(double initialGuess, double tolerance) = 0;

    virtual double findRoot(double initialGuess1, double initialGuess2, double tolerance) {
        throw std::runtime_error("This method is not supported for this algorithm.");
    }

protected:
    std::function<double(double)> function;
};

#endif
