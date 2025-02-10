// ********************************************************************************************************************************************
//*****           Write down a C++ program which calculates the integral of 𝒇(𝒙) = 𝒙𝟑 + 𝟒𝒙 using the “Riemann Sums” formula *****                                                                                                 
//*********************************************************************************************************************************************

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {

    float a, b, n;
    float sumOfMf, sumOfLhf, sumOfRhf = 0;


    cout << "a  : ";
    cin >> a;

    cout << "b  : ";
    cin >> b;

    cout << "n  : ";
    cin >> n;
    // Declaring arrays of MF LHF and RHF
    float arrayOfMf[int(n)], arrayOfLhf[int(n)], arrayOfRhf[int(n)];


    cout << "------------------------------------------------------------------" << endl;
    cout << setw(4) << "i" << setw(10) << "x[i]" << setw(17) << "epsilon[i]" << setw(10) << "LHF" << setw(10) << "RHF" << setw(10) << "MF" << endl;
    cout << "------------------------------------------------------------------" << endl;

    for (int i = 1; i <= n; i++) {

        float dx = (b - a) / n;
        float xi = a + (i - 1) * dx;
        float ei = xi + (dx / 2);

        float xii = a + i * dx;

        float fxi = pow(xi, 3) + 4 * xi;
        float lhf = dx * fxi;

        float fxii = pow(xii, 3) + 4 * xii;
        float rhf = dx * fxii;

        float fei = pow(ei, 3) + 4 * ei;
        float mf = dx * fei;

        arrayOfMf[i - 1] = mf;
        arrayOfLhf[i - 1] = lhf;
        arrayOfRhf[i - 1] = rhf;

        cout << setw(4) << i << setw(10) << xi << setw(17) << ei << setw(10) << lhf << setw(10) << rhf << setw(10) << mf << endl;

    };
    // Calculating the sum of mf , lhf and rhf;
    for (int j = 0; j < n; j++) {
        sumOfMf += arrayOfMf[j];
        sumOfLhf += arrayOfLhf[j];
        sumOfRhf += arrayOfRhf[j];
    };

    cout << "--------------------------------------" << endl;
    cout << "----------INTEGRAL   RESULTS----------" << endl;
    cout << "f(x) = x^3 + 4x from [" << a << "," << b << "] with " << n << " intervals" << endl;
    cout << "--------------------------------------" << endl;
    cout << "MIDPOINT RULE             : " << setprecision(6) << sumOfMf << endl;
    cout << "LEFT HAND RULE            : " << setprecision(6) << sumOfLhf << endl;
    cout << "RIGHT HAND RULE           : " << setprecision(6) << sumOfRhf << endl;
    cout << "--------------------------------------" << endl;

    return 0;
}
