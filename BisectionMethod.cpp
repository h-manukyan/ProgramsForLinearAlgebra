#include <iostream>
#include <cmath>
#include <string>

using namespace std;

float resultAtBordersQuad(float a = 0, float b = 0, float c = 0, float d = 0, float e = 0, float Bound = 0){
    return a*pow(Bound, 4) + b*pow(Bound, 3) + c*pow(Bound, 2) + d*Bound + e;
}

void f(float lb, float bb, int iterat, float a = 0, float b = 0, float c = 0, float d = 0, float e = 0){
    float x;

    if (resultAtBordersQuad(a, b, c, d, e, lb) * resultAtBordersQuad(a, b, c, d, e, bb) > 0){
        cout << "There is no root in this range as \e[1mf(" << lb << ") * f(" << bb << ") >= 0\e[0m\n";
        return;
    }

    for(int i = 0; i < iterat; i++){
        x = (lb+bb)/2;

        cout << 'x' << i << " = " << x << endl; 

        // check if we hit the root exactly
        if (fabs(resultAtBordersQuad(a, b, c, d, e, x)) < 1e-7) {
            cout << x << " is the root of the function!\n";
            return;
        }

        if (resultAtBordersQuad(a, b, c, d, e, lb) * resultAtBordersQuad(a, b, c, d, e, x) <= 0){
            cout << "\e[1mf(" << lb << ") * f(" << x << ") <= 0\e[0m";
            bb = x;
            cout << "New range \e[1m[" << lb << " ; " << x << endl;
        }else {
            lb = x;
            cout << "\e[1mf(" << x << ") * f(" << bb << ") <= 0\e[0m";
            cout << "New range \e[1m[" << x << " ; " << bb << endl;
        }
    }

    cout << "Final \e[1mx" << iterat << " = " << x <<"\e[1m\n";
}

int main (){
    float lBound, uBound;
    int order, Resolution;
    float a = 0, b = 0, c = 0, d = 0, e = 0;
_ORDER:
    
    cout << "Enter coefficients for function (max degree 4): ";
    cin >> a >> b >> c >> d >> e;
        cout << "Give the range where you want to find the root\nFor example: for \e[1m[1;24]\e[0m range write \e[1m1 24\e[0m\n";
        cin >> lBound >> uBound;
        
        if (resultAtBordersQuad(a, b, c, d, e, lBound) * resultAtBordersQuad(a, b, c, d, e, uBound) > 0){
            cout << "There is no root in this range as \e[1mf(" << lBound << ") * f(" << uBound << ") >= 0\e[0m\n";
            return 0;
        }

        cout << "How many iterations you need?\n";
        cin >> Resolution;

        f(lBound, uBound, Resolution, a, b, c, d, e);

    return 0;
}
