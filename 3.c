#include <stdio.h>
#include <math.h>

int main(void)
{
    int i, n;
    double x[50], y[50];
    double sum_x = 0.0, sum_y = 0.0, sum_xy = 0.0, sum_x2 = 0.0, a, b;
    printf("\nFitting of y= ae^bx using the method of least squares\n");

    printf("Enter the no of data points: \t");
    scanf("%d", &n);

    printf("Enter the respective values of x and y: \n");
    for (i = 0; i < n; i++)
    {
        scanf("%lf%lf", &x[i], &y[i]);
    }
    printf("\nThe table of the values you entered is:\n");
    printf("\n__________________________________________\n");
    printf("\tx\t\ty\t\n");
    printf("____________________________________________\n");

    for (i = 0; i < n; i++)
    {
        printf("%.6f\t%.6f\t\n", x[i], y[i]);
         sum_x = sum_x + x[i];
         sum_x2  += x[i]*x[i];
         sum_y  += log(y[i]);
         sum_xy  += x[i]*log(y[i]);
    }
    printf("_________________________________________\n");

    b = (n * sum_xy - sum_x * sum_y) / (n * sum_x2 - sum_x * sum_x);
    a = (sum_y - b * sum_x) / n;

    printf("The required linear curve for fitting is y = %.9lf e ^ (%.9lf x)\n", a, b);
}