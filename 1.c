#include <stdio.h>
#include <math.h>
#define f(x) cos(x)-3*x-1
#define g(x) (1+cos(x))/3

void main()
{
int N,i=1;
float x0,x1,e;
printf("Enter the initial guess(x0):\t");
scanf("%f",&x0);
printf("Enter the tolerable error(e):\t");
scanf("%f",&e);
printf("Enter the maximum iteration:\t");
scanf("%d",&N);
printf("\n________________________________________________________________________________\n");
printf("Iteration\tx0\t\tf(x0)\t\tx1\t\tf(x1)\n");
printf("\n________________________________________________________________________________\n");
do
{
x1=g(x0);
printf("%d\t\t%f\t%f\t%f\t%f\n",i,x0,f(x0),x1,f(x1));
i++;
if(i>N)
{


printf("\n________________________________________________________________________________\n");

printf("the root is %.8f",x1);
exit(0);
}
x0 =x1;
}while((fabs(f(x1))>e));

printf("\n________________________________________________________________________________\n");

printf("the root is %.8f",x1);
}