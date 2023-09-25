#include <iostream>
#include <cmath>
using namespace std;
// Abstract Product for the calculator
class Calculator {
public:
    virtual double add(double a, double b) = 0;
    virtual double subtract(double a, double b) = 0;
    virtual double multiply(double a, double b) = 0;
    virtual double divide(double a, double b) = 0;
    virtual double squareRoot(double a) = 0;
};

// Concrete Products for the simple calculator
class SimpleCalculator : public Calculator {
public:
    double add(double a, double b) override {
        return a + b;
    }

    double subtract(double a, double b) override {
        return a - b;
    }

    double multiply(double a, double b) override {
        return a * b;
    }

    double divide(double a, double b) override {
        if (b != 0) {
            return a / b;
        } else {
            cerr << "Error: Division by zero." << endl;
            return 0;
        }
    }

    double squareRoot(double a) override {
        if (a >= 0) {
            return std::sqrt(a);
        } else {
            cerr << "Error: Cannot calculate square root of a negative number." << endl;
            return 0;
        }
    }
};

// Concrete Products for the scientific calculator
class ScientificCalculator : public Calculator {
public:
    double add(double a, double b) override {
        return a + b;
    }

    double subtract(double a, double b) override {
        return a - b;
    }

    double multiply(double a, double b) override {
        return a * b;
    }

    double divide(double a, double b) override {
        if (b != 0) {
            return a / b;
        } else {
            cerr << "Error: Division by zero." << endl;
            return 0;
        }
    }

    double squareRoot(double a) override {
        if (a >= 0) {
            return std::sqrt(a);
        } else {
            cerr << "Error: Cannot calculate square root of a negative number." << endl;
            return 0;
        }
    }
};

// Abstract Factory for the calculator
class CalculatorFactory {
public:
    virtual Calculator* createCalculator() = 0;
};

// Concrete Factory for the simple calculator
class SimpleCalculatorFactory : public CalculatorFactory {
public:
    Calculator* createCalculator() override {
        return new SimpleCalculator();
    }
};

// Concrete Factory for the scientific calculator
class ScientificCalculatorFactory : public CalculatorFactory {
public:
    Calculator* createCalculator() override {
        return new ScientificCalculator();
    }
};

int main() {
    // Create a simple calculator
    CalculatorFactory* simpleFactory = new SimpleCalculatorFactory();
    Calculator* simpleCalculator = simpleFactory->createCalculator();

    cout << "Simple Calculator: " << endl;
    cout<< "Addition: " << simpleCalculator->add(5, 3) << endl;
    cout << "Subtraction: " << simpleCalculator->subtract(5, 3) << endl;
    cout << "Multiplication: " << simpleCalculator->multiply(5, 3) << endl;
    cout << "Division: " << simpleCalculator->divide(5, 3) << endl;
    cout << "Square Root: " << simpleCalculator->squareRoot(9) << endl;

    // Create a scientific calculator
    CalculatorFactory* scientificFactory = new ScientificCalculatorFactory();
    Calculator* scientificCalculator = scientificFactory->createCalculator();

    cout << "Scientific Calculator: " << endl;
    cout << "Addition: " << scientificCalculator->add(5, 3) << endl;
    cout << "Subtraction: " << scientificCalculator->subtract(5, 3) << endl;
    cout << "Multiplication: " << scientificCalculator->multiply(5, 3) << endl;
    cout << "Division: " << scientificCalculator->divide(5, 3) << endl;
    cout << "Square Root: " << scientificCalculator->squareRoot(9) << endl;

    // Cleanup
    delete simpleFactory;
    delete simpleCalculator;
    delete scientificFactory;
    delete scientificCalculator;

    return 0;
}
