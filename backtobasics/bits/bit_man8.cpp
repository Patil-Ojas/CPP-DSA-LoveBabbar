#include <iostream>
#include <climits>
using namespace std;

int divide(int dividend, int divisor) {
    // Handle division by zero
    if (divisor == 0) {
        throw invalid_argument("Divisor cannot be zero");
    }

    // Handle overflow cases (e.g., INT_MIN / -1)
    if (dividend == INT_MIN && divisor == -1) {
        return INT_MAX; // To prevent overflow
    }

    // Determine the sign of the result
    int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;

    // Convert both dividend and divisor to positive numbers
    long long absDividend = abs(dividend);
    long long absDivisor = abs(divisor);

    // Initialize the quotient
    int quotient = 0;

    // Subtract the divisor from the dividend until the dividend is less than the divisor
    while (absDividend >= absDivisor) {
        long long temp = absDivisor, multiple = 1;
        while (absDividend >= (temp << 1)) {
            temp <<= 1;
            multiple <<= 1;
        }
        absDividend -= temp;
        quotient += multiple;
    }

    // Apply the sign to the quotient
    return sign * quotient;
}

int main() {
    int dividend = 10;
    int divisor = 3;

    try {
        int result = divide(dividend, divisor);
        cout << "Result of division: " << result << endl;
    } catch (const invalid_argument& e) {
        cout << e.what() << endl;
    }

    return 0;
}
