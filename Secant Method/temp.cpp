#include<bits/stdc++.h>
#define eps 1e-4
using namespace std;

double f(double x)
{
    return (x-4.0)*(x-4.0)*(x+2.0);
}



int main ()
{
    freopen("out.txt","w",stdout);
    double prev,present1 = 2.5,present2=-1.0,present3,approx,relative_approximate_error=999999999;;
    ///taking -1.0 , -3.0 will provide root = 2
    int cnt =0;
    while(cnt++<=30 )
    {

        approx = (f(present2) - f(present1))/(present2-present1);
        present3 = present2 - (f(present2)/approx);

        printf("%0.8lf %0.8lf %0.8lf",present1,present2,present3);
        if(cnt!=1)
        {
            relative_approximate_error = fabs((present2-prev)/present2)*100.0;
            printf(" %0.8lf",relative_approximate_error);
        }
        printf(" %0.12lf",f(present3));
        puts("");
        prev = present2;

        present1 = present2;
        present2 = present3;

        if( relative_approximate_error<eps) break;
    }
    printf("Root: %0.8lf\nIterations Required: %d",present2,cnt);
}
