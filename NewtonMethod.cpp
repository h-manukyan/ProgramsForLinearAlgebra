#include <iostream>
#include <cmath>
#include <string>
using namespace std;

float derivative(float a = 0, float b = 0, float c = 0, float d = 0, float e = 0, float initX = 0){
    float h = 1e-6;
    return ((a*pow((initX+h), 4)+b*pow((initX+h), 3)+c*pow(initX+h, 2)+d*(initX+h)+e)
          - (a*pow((initX-h), 4)+b*pow((initX-h), 3)+c*pow(initX-h, 2)+d*(initX-h)+e))
          / (2*h);
}

float f(float a = 0, float b = 0, float c = 0, float d = 0, float e = 0, float initX = 0){
    return a*pow(initX, 4)+b*pow(initX, 3)+c*pow(initX, 2)+d*initX+e;
}

void NewtonMethod(float a = 0, float b = 0, float c = 0, float d = 0, float e = 0, float initX = 0, int iterationCount = 0){
    float x;
    for (int i = 0; i < iterationCount; i++){
        cout << "x" << i << " = " << initX << endl;
        x = initX - (f(a, b, c, d, e, initX) / derivative(a, b, c, d, e, initX));
        initX = x;
    }
    cout << "Approximation after \e[1m" << iterationCount << "\e[0m iterations is \e[1m" << x << "\e[0m" << endl;
}

int main (){
    float guess, a, b, c, d, e;
    int it;
    
    cout << "Enter coefficients for function (max degree 4): ";
    cin >> a >> b >> c >> d >> e;
    cout << "\nEnter the initial guess: ";
    cin >> guess;
    cout << "\nEnter number of iterations: ";
    cin >> it;
    
    NewtonMethod(a, b, c, d, e, guess, it);
    return 0;
}
