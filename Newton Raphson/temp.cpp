#include<bits/stdc++.h>
using namespace std;

double f(double x)
{
    return (x*x)*exp(-x) - 0.5;
}

double fprime(double x)
{
    return 2*x*exp(-x) - (x*x)*(exp(-x));
}

int main ()
{
    double prev=0.2,present = 0.2;
    int cnt =0;
    while(++cnt<=6)
    {
        double fx = f(present);
        double fxx = fprime(present);
        double relative_approximate_error = fabs((present-prev)/present)*100.0;
        printf("%0.12lf %0.35lf %0.12lf %0.12lf\n",present,fx,fxx,relative_approximate_error);
        prev = present;
        present = present - (fx/fxx);
    }
}
