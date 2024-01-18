#include <stdio.h>
#include <conio.h>
#include <math.h>
#define f(x) exp(cos(x)) - sin(x)

int main()
{

    float x0, x1, x2, f0, f1, f2, e;
    int n, i = 1;

INPUT:
    printf("\nEnter two initial guesses:\n");
    scanf("%f%f", &x0, &x1);
    f0 = f(x0);
    f1 = f(x1);

    if (f0 * f1 > 0.0)
    {
        printf("Incorrect Initial Guesses.\n");
        goto INPUT;
    }
    printf("Enter tolerable error:\n");
    scanf("%f", &e);

    printf("\n________________________________________________\n");
    printf("Step\t\tx0\t\tx1\t\tx2\t\tf(x2)\n");
    printf("________________________________________________\n");
    do
    {
        x2 = x0 - (x0 - x1) * f0 / (f0 - f1);
        f2 = f(x2);
        printf("%d\t\t%f\t%f\t%f\t%f\n", i, x0, x1, x2, f2);

        if (f0 * f2 < 0)
        {
            x1 = x2;
            f1 = f2;
        }
        else
        {
            x0 = x2;
            f0 = f2;
        }
        i++;

    } while (fabs(f2) > e);
    printf("________________________________________________\n");

    printf("\nRoot is: %f", x2);
    return 0;
}