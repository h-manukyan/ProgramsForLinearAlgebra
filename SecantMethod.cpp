#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Polynomial evaluator (up to 4th degree)
float poly(float a=0, float b=0, float c=0, float d=0, float e=0, float x=0) {
    return a*pow(x,4) + b*pow(x,3) + c*pow(x,2) + d*x + e;
}

// Secant method function
void secant(float x0, float x1, int maxIter, float tol, float a=0, float b=0, float c=0, float d=0, float e=0) {
    float x2, f0, f1;

    cout << fixed << setprecision(6);
    cout << "\nIter |    x0     |    x1     |    x2     |   f(x2)" << endl;
    cout << "-----------------------------------------------" << endl;

    for (int i = 0; i < maxIter; i++) {
        f0 = poly(a,b,c,d,e,x0);
        f1 = poly(a,b,c,d,e,x1);

        if (fabs(f1 - f0) < 1e-9) {
            cout << "Division by zero or near-zero difference detected. Stopping.\n";
            return;
        }

        x2 = x1 - f1 * (x1 - x0) / (f1 - f0);

        cout << setw(4) << i+1 << " | " 
             << setw(8) << x0 << " | " 
             << setw(8) << x1 << " | " 
             << setw(8) << x2 << " | "
             << setw(8) << poly(a,b,c,d,e,x2) << endl;

        if (fabs(x2 - x1) < tol) {
            cout << "\nRoot found: x ≈ " << x2 << " after " << i+1 << " iterations.\n";
            return;
        }

        x0 = x1;
        x1 = x2;
    }

    cout << "\nApproximation after " << maxIter << " iterations: x ≈ " << x1 << endl;
}

int main() {
    float a=0,b=0,c=0,d=0,e=0;
    float x0, x1, tol;
    int maxIter;

    cout << "Enter coefficients for function (max degree 4): ";
    cin >> a >> b >> c >> d >> e;

    cout << "Enter two initial guesses (x0 and x1): ";
    cin >> x0 >> x1;

    cout << "Enter tolerance (e.g. 0.0001): ";
    cin >> tol;

    cout << "Enter number of iterations: ";
    cin >> maxIter;

    secant(x0, x1, maxIter, tol, a, b, c, d, e);
    return 0;
}
