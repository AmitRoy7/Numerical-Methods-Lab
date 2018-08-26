#include<bits/stdc++.h>
using namespace std;


double lo,hi,accuracy;
FILE *fp1_n0,*fp1_n1,*fp1_n2,*fp1_2;

double fact (double n)
{
    double ret = 1.0;
    for(double i=2;i<=n;i+=1.0)
    {
        ret = ret * i;
    }
    return ret;
}

double func(double x,double n)
{
    double ret = pow((x/2),n),up,down,sum = 0;
    for(double k=0;k<=100;k+=1.0)
    {
        up = pow(-1.0,k)* pow(((x*x)/4.0),k);
        down = fact(k) * fact(n+k);

        sum = sum+(up/down);
    }
    return ret*sum;
}



double bisection_method(double lo,double hi,double n)
{


    double prev,present,f,relative_approx_error;
    int cnt = 1;
    prev = (hi+lo)/2.0;
    f = func(prev,n);

    printf("Iteration\tXl\tXu\tXr\tF(Xr)\tRelative Apporximate Error\n");
    printf("%d\t%0.6lf\t%0.6lf\t%0.6lf\t%0.6lf\n",cnt,lo,hi,prev,func(prev,n));

    fprintf(fp1_2,"Iteration\tXl\tXu\tXr\tF(Xr)\tRelative Apporximate Error\n");
    fprintf(fp1_2,"%d\t%0.6lf\t%0.6lf\t%0.6lf\t%0.6lf\n",cnt,lo,hi,prev,func(prev,n));

    cnt++;

    if(!f)  return prev;
    else if(f * func(hi,n) > 0)            hi = prev;
    else if(f * func(lo,n) > 0)           lo = prev;

    while(1)
    {
        present = (hi+lo)/2.0;
        f = func(present,n);

        relative_approx_error = fabs((present-prev)*100.00/present);

        printf("%d\t%0.6lf\t%0.6lf\t%0.6lf\t%0.9lf\t%0.7lf\n",cnt,lo,hi,present,func(present,n),relative_approx_error);
        fprintf(fp1_2,"%d\t%0.6lf\t%0.6lf\t%0.6lf\t%0.9lf\t%0.7lf\n",cnt,lo,hi,present,func(present,n),relative_approx_error);

        cnt++;

        if(!f)  return present;
        else if(f * func(hi,n) > 0)            hi = present;
        else if(f * func(lo,n) > 0)           lo = present;

        if(relative_approx_error<accuracy)  break;
        prev = present;
    }
    return present;

}
int main()
{
    fp1_n0 = fopen("problem1_n0.csv","w");
    fp1_n1 = fopen("problem1_n1.csv","w");
    fp1_n2 = fopen("problem1_n2.csv","w");

    fp1_2 = fopen("problem1_2.csv","w");

    //n = 0
    printf("x\tF(x)\n");
    fprintf(fp1_n0,"x\tJ(x)\n");
    for(double i=0;i<=10.0;i+=0.1)
    {

        printf("%0.2lf\t%0.6lf\n",i,func(i,0));
        fprintf(fp1_n0,"%0.2lf\t%0.6lf\n",i,func(i,0));

    }
    printf("\n\n");


    //n=1
    printf("x\tF(x)\n");
    fprintf(fp1_n1,"x\tJ(x)\n");
    for(double i=0;i<=10.0;i+=0.1)
    {

        printf("%0.2lf\t%0.6lf\n",i,func(i,1));
        fprintf(fp1_n1,"%0.2lf\t%0.6lf\n",i,func(i,1));

    }
    printf("\n\n");

    //n = 2
    printf("x\tF(x)\n");
    fprintf(fp1_n2,"x\tJ(x)\n");
    for(double i=0;i<=10.0;i+=0.1)
    {

        printf("%0.2lf\t%0.6lf\n",i,func(i,2));
        fprintf(fp1_n2,"%0.2lf\t%0.6lf\n",i,func(i,2));

    }
    printf("\n\n");

    scanf("%lf %lf %lf",&lo,&hi,&accuracy);
    double root = bisection_method(lo,hi,0);
    printf("Root of the equation: %0.6lf\n",root);
    fclose(fp1_n0);
    fclose(fp1_n1);
    fclose(fp1_n2);
    fclose(fp1_2);
}
