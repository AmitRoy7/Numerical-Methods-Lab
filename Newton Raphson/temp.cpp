#include<bits/stdc++.h>
using namespace std;

double f(double x)
{
    return (x-4.0)*(x-4.0)*(x+2.0);
}

double fprime(double x)
{
    return (3.0*x*x - 12.0*x);
}

int main ()
{
    double prev=-2.3,present = -2.3;
    int cnt =0;
    while(++cnt<=5)
    {
        double fx = f(present);
        double fxx = fprime(present);
        double relative_approximate_error = fabs((present-prev)/present)*100.0;
        printf("%0.12lf %0.35lf %0.12lf %0.12lf\n",present,fx,fxx,relative_approximate_error);
        prev = present;
        present = present - (fx/fxx);
    }
}
