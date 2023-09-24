#include <iostream>
using namespace std;

class Calculator {
public:
    virtual double calculate(double a, double b) = 0;
};

class Addition : public Calculator {
public:
    double calculate(double a, double b) override {
        return a + b;
    }
};

class Subtraction : public Calculator {
public:
    double calculate(double a, double b) override {
        return a - b;
    }
};

class Multiplication : public Calculator {
public:
    double calculate(double a, double b) override {
        return a * b;
    }
};

class Division : public Calculator {
public:
    double calculate(double a, double b) override {
        if (b != 0) {
            return a / b;
        } else {
            cerr << "Error: Division by zero." << std::endl;
            return 0;
        }
    }
};

// Simple Factory
class CalculatorFactory {
public:
    static Calculator* createCalculator(char operation) {
        switch (operation) {
            case '+':
                return new Addition();
            case '-':
                return new Subtraction();
            case '*':
                return new Multiplication();
            case '/':
                return new Division();
            default:
                cerr << "Error: Invalid operation." << std::endl;
                return nullptr;
        }
    }
};

int main() {
    double a, b;
    char operation;

    cout << "Enter two numbers: ";
    cin >> a >> b;
    cout << "Enter operation (+, -, *, /): ";
    cin >> operation;

    Calculator* calculator = CalculatorFactory::createCalculator(operation);

    if (calculator) {
        double result = calculator->calculate(a, b);
        cout << "Result: " << a << " " << operation << " " << b << " = " << result << std::endl;
        delete calculator;
    }

    return 0;
}
