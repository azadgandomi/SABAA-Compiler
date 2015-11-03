#include<stdio.h>
#include<stdlib.h>


int main()

{
double x1;
double x2;
printf("%s", "Enter 2 numbers:\n");
printf("%s", "x1: ");
scanf("%lf", &x1);
printf("%s", "x2: ");
scanf("%lf", &x2);
printf("%s", "\n");
printf("%s", "x1 + x2 = ");
printf("%g", x1 + x2);
printf("%s", "\nx1 - x2 = ");
printf("%g", x1 - x2);
printf("%s", "\nx1 * x2 = ");
printf("%g", x1 * x2);
printf("%s", "\nx1 / x2 = ");
printf("%g", x1 / x2);
if(x1 > 0 && x2 > 0)
{
printf("%s", "\n\nBoth numbers are positive!\n\n");
}

else
{
if(x1 < 0 && x2 < 0)
{
printf("%s", "\n\nBoth numbers are negative!\n\n");
}

else
{
printf("%s", "\n\nOne of them is positive and the other is negative!\n\n");
}
}
return 0;
}