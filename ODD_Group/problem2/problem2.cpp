#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

#define ca0 42
#define cb0 28
#define cc0 4
#define k 0.016

double lo,hi,accuracy;
FILE *fp1,*fp2;

double func(double x)
{
    double up = (cc0+x);
    double down = (ca0-2.0*x)*(ca0-2.0*x)*(cb0-x);
    return (up/down)-k;
}



double falseposition_method(double lo,double hi)
{


    double prev,present,f,relative_approx_error;
    int cnt = 1;

    prev=(hi*func(lo) - lo*func(lo))/(func(lo)-func(hi)) + lo;
    f = func(prev);

    fprintf(fp2,"Iteration\tXl\tXu\tf(Xl)\tf(Xu)\tXr\tRelative Apporximate Error\n");
    fprintf(fp2,"%d\t%0.6lf\t%0.6lf\t%0.6lf\t%0.6lf\t%0.6lf\t%0.6lf\n",cnt,lo,hi,func(lo),func(hi),prev,func(prev));

    printf("Iteration\tXl\tXu\tf(Xl)\tf(Xu)\tXr\tRelative Apporximate Error\n");
    printf("%d\t%0.6lf\t%0.6lf\t%0.6lf\t%0.6lf\t%0.6lf\t%0.6lf\n",cnt,lo,hi,func(lo),func(hi),prev,func(prev));
    cnt++;

    if(!f)  return prev;
    else if(f * func(hi) > 0)            hi = prev;
    else if(f * func(lo) > 0)            lo = prev;

    while(1)
    {
        present =(hi*func(lo) - lo*func(lo))/(func(lo)-func(hi)) + lo;
        f = func(present);

        relative_approx_error = fabs((present-prev)*100.00/present);

        fprintf(fp2,"%d %0.6lf %0.6lf %0.6lf %0.6lf %0.6lf %0.6lf %0.6lf\n",cnt,lo,hi,func(lo),func(hi),present,func(present),relative_approx_error);
        printf("%d %0.6lf %0.6lf %0.6lf %0.6lf %0.6lf %0.6lf %0.6lf\n",cnt,lo,hi,func(lo),func(hi),present,func(present),relative_approx_error);

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
    fp1 = fopen("problem2_1.csv","w");
    fp2 = fopen("problem2_2.csv","w");

    printf("x\tF(x)\n");
    fprintf(fp1,"x\tF(x)\n");
    for(double i=0;i<=20.0;i+=1.0)
    {

        printf("%0.2lf\t%0.6lf\n",i,func(i));
        fprintf(fp1,"%0.2lf\t%0.6lf\n",i,func(i));

    }
    scanf("%lf %lf %lf",&lo,&hi,&accuracy);
    double root = falseposition_method(lo,hi);
    printf("Root of the equation: %0.6lf\n",root);
    fclose(fp1);
    fclose(fp2);
}

