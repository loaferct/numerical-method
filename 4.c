
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define f(x) (exp(cos(x))-sin(x))
int main()
{
    float x0, x1, x2, f1, f2, f0, e;
    int iteration = 1, n;
    printf("Enter the value of initial guesses x0:\t");
    scanf("%f%f", &x0,&x1);
    printf("Enter the max no of tolernce error:\t");
    scanf("%f", &e);
    printf("Enter the maximum number of iteration:\t");
    scanf("%d", &n);
    printf("---------------------------------------------------------------------------------------------------\n");
    printf("Iterations\t\t x0\t\t x1\t\t x2\t\t f(x2)\n");
    printf("---------------------------------------------------------------------------------------------------\n");
    do
    {
        f0 = f(x0);
        f1 = f(x1);
        if (f0 == f1)
        {
            printf("Mathematical error\n");
            exit(0);
        }
        x2 = x1 - (x1 - x0) *f1 / (f1 - f0);
        f2 = f(x2);
        printf("\t%d\t\t%f\t%f\t%f\t%f\n", iteration, x0, x1, x2, f2);

        x0 = x1;
        f0 = f1;
        x1 = x2;
        f1 = f2;
        iteration++;
        if(iteration > n)
        {
            printf("The solution does not diverge\n");
            exit(0);
        }
    } while (fabs(f2) > e);
    printf("---------------------------------------------------------------------------------------------------\n");
    printf("The approximate root is %0.8f", x2);
    return 0;
}