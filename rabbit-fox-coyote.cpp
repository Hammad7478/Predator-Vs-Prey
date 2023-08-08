#include <cmath>
// #include "cpgplot.h"
#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;

double rabbitODE(double r, double f, double c)
{
    double a = 0.4, b = 0.1, d = 0.1;
    return (r * (a - (b * f) - (d * c)));
}

double foxODE(double r, double f, double c)
{
    double a = 0.4, b = 0.1, d = 0.1;
    return f * ((b * r) - a - (d * c));
}

double coyoteODE(double r, double f, double c)
{
    double a = 0.4, b = 0.1, d = 0.1;
    return c * ((d * f) + (b * r) - a);
}

int main()
{
    double f = 7.0, r = 7.0, c = 7.0;
    double tStart = 0, tEnd = 100, t = tStart;
    int i = 0, n = 1000;
    double deltaT = (tEnd - tStart) / n;
    float tp[n];
    float fp[n];
    float rp[n];
    float cp[n];
    double kr1, kr2, kr3, kr4;
    double kf1, kf2, kf3, kf4;
    double kc1, kc2, kc3, kc4;
    for (int i = 0; i < n; i++)
    {
        kr1 = deltaT * (rabbitODE(r, f, c));
        kf1 = deltaT * (foxODE(r, f, c));
        kc1 = deltaT * (coyoteODE(r, f, c));

        kr2 = deltaT * (rabbitODE(r + 0.5 * kr1, f + 0.5 * kf1, c + 0.5 * kc1));
        kf2 = deltaT * (foxODE(r + 0.5 * kr1, f + 0.5 * kf1, c + 0.5 * kc1));
        kc2 = deltaT * (coyoteODE(r + 0.5 * kr1, f + 0.5 * kf1, c + 0.5 * kc1));
        kr3 = deltaT * (rabbitODE(r + 0.5 * kr2, f + 0.5 * kf2, c + 0.5 * kc2));
        kf3 = deltaT * (foxODE(r + 0.5 * kr2, f + 0.5 * kf2, c + 0.5 * kc2));
        kc3 = deltaT * (coyoteODE(r + 0.5 * kr2, f + 0.5 * kf2, c + 0.5 * kc2));
        kr4 = deltaT * (rabbitODE(r + kr3, f + kf3, c + kc3));
        kf4 = deltaT * (foxODE(r + kr3, f + kf3, c + kc3));
        kc4 = deltaT * (coyoteODE(r + kr3, f + kf3, c + kc3));
        r = r + (kr1 + (2 * kr2) + (2 * kr3) + kr4) / 6;
        f = f + (kf1 + (2 * kf2) + (2 * kf3) + kf4) / 6;
        c = c + (kc1 + (2 * kc2) + (2 * kc3) + kc4) / 6;
        rp[i] = r;
        fp[i] = f;
        cp[i] = c;
        t = t + deltaT;
        tp[i] = t;
    }

    // if (!cpgopen("/XWINDOW")) return 1;

    // cpgenv(0,100,0,20.0,0,1);
    // cpglab("T", "Animal Populations", "Coyotes vs. Foxes vs. Rabbits");
    // cpgsci(5);
    // cpgline(n,tp,fp); //Plotting the estimate
    // cpgsci(1);
    // cpgline(n,tp,rp); //Plotting the estimate
    // cpgsci(3);
    // cpgline(n,tp,cp); //Plotting the estimate
    // cpgclos();
}