#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#define osf 8

double lo,hi,accuracy;
FILE *fp1,*fp2;

double func(double x)
{

    return(-log(osf) - 139.34411 + (1.575701e5/x) - (6.642308e7/(x*x)) + (1.2438e10/(x*x*x)) - ((8.621949e11)/(x*x*x*x)));
}



double bisection_method(double lo,double hi)
{


    double prev,present,f,relative_approx_error;
    int cnt = 1;
    prev = (hi+lo)/2.0;
    f = func(prev);
    fprintf(fp2,"Iteration\tXl\tXu\tXr\tRelative Apporximate Error\n");
    fprintf(fp2,"%d\t%0.6lf\t%0.6lf\t%0.6lf\n",cnt,lo-273.15,hi-273.15,prev-273.15);
    cnt++;

    if(!f)  return prev;
    else if(f * func(hi) > 0)            hi = prev;
    else if(f * func(lo) > 0)           lo = prev;

    while(1)
    {
        present = (hi+lo)/2.0;
        f = func(present);

        relative_approx_error = fabs((present-prev)*100.00/present);

        fprintf(fp2,"%d\t%0.6lf\t%0.6lf\t%0.6lf\t%0.7lf\n",cnt,lo-273.15,hi-273.15,present-273.15,relative_approx_error);
        cnt++;

        if(!f)  return present;
        else if(f * func(hi) > 0)            hi = present;
        else if(f * func(lo) > 0)           lo = present;

        if(relative_approx_error<accuracy)  break;
        prev = present;
    }
    return present-273.15;

}
int main()
{
    fp1 = fopen("osf8_1.csv","w");
    fp2 = fopen("osf8_2.csv","w");

    fprintf(fp1,"t\tTa\tF(Ta)\n");
    for(int i=0;i<=40;i++)
    {
        //fprintf(fp,"%0.2lf\n",i);
        //fprintf(fp,"%lf\n",func(i));
        double x = i+273.15;
        printf("%d\t%0.2lf\t%0.6lf\n",i,x,func(x));
        fprintf(fp1,"%d\t%0.2lf\t%0.6lf\n",i,x,func(x));
    }
    scanf("%lf %lf %lf",&lo,&hi,&accuracy);
    lo = lo + 273.15;
    hi = hi + +273.15;
    double root = bisection_method(lo,hi);
    printf("Root of the equation: %0.6lf\n",root);
    fclose(fp1);
    fclose(fp2);
}
