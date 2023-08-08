#include <cmath>
// #include "cpgplot.h"
#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;

double rabbitODE(double x, double y)
{
    double a = 0.4, b = 0.1;
    return x * (a - (b * y));
}

double foxODE(double x, double y)
{
    double c = 0.4, d = 0.1;
    return y * ((d * x) - c);
}

int main()
{
    double y = 7.0, x = 7.0;
    double tStart = 0, tEnd = 100, t = tStart;
    int i = 0, n = 1000;
    double deltaT = (tEnd - tStart) / n;
    float tp[n];
    float yp[n];
    float xp[n];
    double kx1, kx2, kx3, kx4;
    double ky1, ky2, ky3, ky4;
    for (int i = 0; i < n; i++)
    {
        kx1 = deltaT * (rabbitODE(x, y));
        ky1 = deltaT * (foxODE(x, y));

        kx2 = deltaT * (rabbitODE(x + 0.5 * kx1, y + 0.5 * ky1));
        ky2 = deltaT * (foxODE(x + 0.5 * kx1, y + 0.5 * ky1));
        kx3 = deltaT * (rabbitODE(x + 0.5 * kx2, y + 0.5 * ky2));
        ky3 = deltaT * (foxODE(x + 0.5 * kx2, y + 0.5 * ky2));
        kx4 = deltaT * (rabbitODE(x + kx3, y + ky3));
        ky4 = deltaT * (foxODE(x + kx3, y + ky3));
        x = x + (kx1 + (2 * kx2) + (2 * kx3) + kx4) / 6;
        y = y + (ky1 + (2 * ky2) + (2 * ky3) + ky4) / 6;
        xp[i] = x;
        yp[i] = y;
        t = t + deltaT;
        tp[i] = t;
    }

    // if (!cpgopen("/XWINDOW"))
    //     return 1;

    // cpgenv(0, 100, 0, 10.0, 0, 1);
    // cpglab("T", "Animal Populations", "Foxes vs. Rabbits");
    // cpgsci(5);
    // cpgline(n, tp, yp); // Plotting the fox population
    // cpgsci(1);
    // cpgline(n, tp, xp); // Plotting the rabbit population
    // cpgclos();
}
