#include <bits/stdc++.h>
using namespace std;
#define nl endl
#define sadik() ios::sync_with_stdio(false); cin.tie(0);
const double tolerance = 1e-3; // Defined as 0.001

class SecantMethod {
private:
    double a, b, c;

    double func(double x) {
        return x * x * x - x * x + 2; // Example function: f(x) = x³ - x² + 2
    }

    void randomValueGenerator() {
        srand(time(0)); // Seed the random generator
        do {
            a = ((rand() % 200) - 100) / 10.0;
            b = a + 0.5; // Ensure b is different from a
        } while (fabs(func(a) - func(b)) < 1e-9); // Avoid division by zero
    }

public:
    SecantMethod(double tol) {
        randomValueGenerator();
    }

    double secantSolve() {
        int i = 1;
        while (true) {
            if (fabs(func(b) - func(a)) < 1e-9) { // Prevent division by zero
                cout << "Division by zero detected. Stopping computation." << nl;
                return NAN; // Indicate failure
            }

            c = b - func(b) * (b - a) / (func(b) - func(a)); // Secant method formula

            cout << "Iteration: " << i << "  c: " << c << "  f(c): " << func(c) << nl;

            if (fabs(func(c)) < tolerance || fabs(c - b) < tolerance) { // Convergence check
                break;
            }

            a = b;
            b = c;
            i++;
        }

        cout << "The Root Is: " << c << nl;
        return c;
    }
};

int main() {
    sadik();
    SecantMethod secant(tolerance);
    double root = secant.secantSolve();

    if (!isnan(root)) {
        cout << "Approximate root found: " << root << nl;
    } else {
        cout << "Failed to find root due to numerical issues." << nl;
    }

    return 0;
}
