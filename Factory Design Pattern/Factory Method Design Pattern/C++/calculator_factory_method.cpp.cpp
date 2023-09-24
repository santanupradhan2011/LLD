#include <iostream>
using namespace std;
// Abstract Product
class Calculator {
public:
    virtual double calculate(double a, double b) = 0;
};

// Concrete Products
class AdditionCalculator : public Calculator {
public:
    double calculate(double a, double b) override {
        return a + b;
    }
};

class SubtractionCalculator : public Calculator {
public:
    double calculate(double a, double b) override {
        return a - b;
    }
};

class MultiplicationCalculator : public Calculator {
public:
    double calculate(double a, double b) override {
        return a * b;
    }
};

class DivisionCalculator : public Calculator {
public:
    double calculate(double a, double b) override {
        if (b != 0) {
            return a / b;
        } else {
            cerr << "Error: Division by zero." << endl;
            return 0;
        }
    }
};

// Abstract Factory
class CalculatorFactory {
public:
    virtual Calculator* createCalculator() = 0;
};

// Concrete Factories
class AdditionCalculatorFactory : public CalculatorFactory {
public:
    Calculator* createCalculator() override {
        return new AdditionCalculator();
    }
};

class SubtractionCalculatorFactory : public CalculatorFactory {
public:
    Calculator* createCalculator() override {
        return new SubtractionCalculator();
    }
};

class MultiplicationCalculatorFactory : public CalculatorFactory {
public:
    Calculator* createCalculator() override {
        return new MultiplicationCalculator();
    }
};

class DivisionCalculatorFactory : public CalculatorFactory {
public:
    Calculator* createCalculator() override {
        return new DivisionCalculator();
    }
};

int main() {
    double a, b;
    char operation;

    cout << "Enter two numbers: ";
    cin >> a >> b;
    cout << "Enter operation (+, -, *, /): ";
    cin >> operation;

    CalculatorFactory* factory = nullptr;

    switch (operation) {
        case '+':
            factory = new AdditionCalculatorFactory();
            break;
        case '-':
            factory = new SubtractionCalculatorFactory();
            break;
        case '*':
            factory = new MultiplicationCalculatorFactory();
            break;
        case '/':
            factory = new DivisionCalculatorFactory();
            break;
        default:
            cerr << "Error: Invalid operation." << endl;
            return 1;
    }

    if (factory) {
        Calculator* calculator = factory->createCalculator();
        double result = calculator->calculate(a, b);
        cout << "Result: " << a << " " << operation << " " << b << " = " << result << endl;
        delete calculator;
        delete factory;
    }

    return 0;
}
