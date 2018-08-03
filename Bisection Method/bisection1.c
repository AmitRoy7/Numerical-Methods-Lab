#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>


double lo,hi,accuracy;
FILE *fp1,*fp2;

double func(double x)
{
    return (exp(x)-5.0*x*x);
}



double bisection_method(double lo,double hi)
{


    double prev,present,f,relative_approx_error;
    int cnt = 1;
    prev = (hi+lo)/2.0;
    f = func(prev);
    fprintf(fp2,"Iteration\tXl\tXu\tXr\tRelative Apporximate Error\n");
    fprintf(fp2,"%d\t%0.6lf\t%0.6lf\t%0.6lf\n",cnt,lo,hi,prev);
    cnt++;

    if(!f)  return prev;
    else if(f * func(hi) > 0)            hi = prev;
    else if(f * func(lo) > 0)           lo = prev;

    while(1)
    {
        present = (hi+lo)/2.0;
        f = func(present);

        relative_approx_error = fabs((present-prev)*100.00/present);

        fprintf(fp2,"%d\t%0.6lf\t%0.6lf\t%0.6lf\t%0.7lf\n",cnt,lo,hi,present,relative_approx_error);

        cnt++;

        if(!f)  return present;
        else if(f * func(hi) > 0)            hi = present;
        else if(f * func(lo) > 0)           lo = present;

        if(relative_approx_error<accuracy)  break;
        prev = present;
    }
    return present;

}
int main()
{
    fp1 = fopen("problem1_1.csv","w");
    fp2 = fopen("problem1_2.csv","w");

    printf("x\tF(x)\n");
    fprintf(fp1,"x\tF(x)\n");
    for(double i=-1.0;i<=1.0;i+=0.1)
    {

        printf("%0.2lf\t%0.6lf\n",i,func(i));
        fprintf(fp1,"%0.2lf\t%0.6lf\n",i,func(i));

    }
    scanf("%lf %lf %lf",&lo,&hi,&accuracy);
    double root = bisection_method(lo,hi);
    printf("Root of the equation: %0.6lf\n",root);
    fclose(fp1);
    fclose(fp2);
}
