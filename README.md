# Root Finding and Optimization Methods

This project implements various root finding and optimization methods in C++. The available methods are:
- Secant Method
- Bisection Method
- Newton-Raphson Method
- Gradient Descent

## Methods

### 1. Secant Method
The Secant Method is an iterative numerical method for finding the root of a function. It uses two initial approximations and iteratively refines them using the formula:

$$x_{n+1} = x_n - f(x_n) \frac{x_n - x_{n-1}}{f(x_n) - f(x_{n-1})}$$

### 2. Bisection Method
The Bisection Method is a simple and robust method for finding roots. It works by repeatedly dividing an interval in half and selecting the subinterval in which the function changes sign. The formula used is:

$$c = \frac{a + b}{2}$$

The algorithm terminates when either of the following conditions is met:

$$\text{If } f(c) = 0 \text{ or } \frac{b - a}{2} < \text{tolerance, then } c \text{ is the root.}$$

Otherwise, the interval \([a, c]\) or \([c, b]\) is selected based on the sign of \(f(c)\).

### 3. Newton-Raphson Method
The Newton-Raphson Method is a fast and efficient root-finding algorithm that uses the derivative of the function. Starting from an initial guess $x_0$, the formula used is:

$$x_{n+1} = x_n - \frac{f(x_n)}{f'(x_n)}$$

### 4. Gradient Descent
Gradient Descent is an optimization algorithm used to find the minimum of a function. Starting from an initial point $x_0$, it iteratively updates the point in the direction opposite to the gradient. The formula used is:

$$x_{n+1} = x_n - \alpha \nabla f(x_n)$$

where $\alpha$ is the learning rate.

## Usage

### Setting Up the Project

1. Clone the repository and navigate to the project directory.
2. Change the main.cpp file to use the desired method.
3. Build the project using the provided Makefile:
```bash
make
```
4. Run the executable:
```bash
./main
```
5. To clean the project, run:
```bash
make clean
```
