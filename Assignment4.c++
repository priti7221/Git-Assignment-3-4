#include <iostream>

class computation {
private:
    // No private members needed for this implementation

public:
    int compute(int a, int b) {
        return a + b;
    }

    float compute(int a, float b) {
        return a + b;
    }

    double compute(int a, double b) {
        return a + b;
    }

    int compute(char a, char b) {
        return int(a) + int(b);
    }

    int compute(char a, int b) {
        return int(a) + b;
    }

    int compute() {
        return 0; // Default behavior if no values provided
    }
};

int main() {
    computation calc;

    std::cout << "1 + 2 = " << calc.compute(1, 2) << std::endl;
    std::cout << "1 + 2.5 = " << calc.compute(1, 2.5f) << std::endl;
    std::cout << "1 + 2.5 = " << calc.compute(1, 2.5) << std::endl;
    std::cout << "Ascii value of 'a' + Ascii value of 'b' = " << calc.compute('a', 'b') << std::endl;
    std::cout << "Ascii value of 'a' + 3 = " << calc.compute('a', 3) << std::endl;
    std::cout << "Default result = " << calc.compute() << std::endl;

    return 0;
}