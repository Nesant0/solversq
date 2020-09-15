#include <stdio.h>
#include <math.h>
#include <assert.h>

int solversq(double a, double b, double c, double* x1, double* x2)
    {
    assert (isfinite (a));
    assert (isfinite (b));
    assert (isfinite (c));

    double discriminant = b*b - 4*a*c;
    if (a != 0)
        {
        if (discriminant >= 0)
            {
            *x1 = (-b + sqrt(discriminant))/(2*a);
            *x2 = (-b - sqrt(discriminant))/(2*a);
            return 2;
            }
        else
            {
            return 0;
            }
        }
    else
        {
            if (b != 0)
                {
                *x1 = -c/b;
                *x2 = -c/b;
                return 1;
                }
            else
                {
                return 0;
                }
        }
    }

int main()
    {
    void test_solversq();

    printf ("enter a,b,c for (ax^2+bx+c)\n");

    double a = 0;
    double b = 0;
    double c = 0;
    double x1 = 0;
    double x2 = 0;

    scanf ("%lf", &a);
    scanf ("%lf", &b);
    scanf ("%lf", &c);

    test_solversq();

    int solvenum = solversq(a, b, c, &x1, &x2);

    solversq(a, b, c, &x1, &x2);

    if (solvenum == 1)
        {
        printf("only solution: x = %lg", x1);
        }
    if (solvenum == 2)
        {
        printf("first soultion: x1 = %lg\nsecond solution: x2 = %lg\n", x1, x2);
        }
    if (solvenum == 0)
        {
        printf("no solution");
        }
    }

void test_solversq()
{

#define test if (res == exp) printf("Test on %d completed\n",__LINE__);\
else printf("Test on %d failed: res - %d, expected - %d\n",__LINE__ , res, exp)

double a = 0;
double b = 0;
double c = 0;

double x1 = 0;
double x2 = 0;

int res = solversq (a, b, c, &x1, &x2);
int exp= 0;

test;

a = 1;
b = 0;
c = -4;

x1 = 0;
x2 = 0;

res = solversq (a, b, c, &x1, &x2);
exp= 2;

test;

a = 1;
b = 1;
c = 100;

x1 = 0;
x2 = 0;

res = solversq (a, b, c, &x1, &x2);
exp= 0;

test;

a = 0;
b = 0;
c = 1;

x1 = 0;
x2 = 0;

res = solversq (a, b, c, &x1, &x2);
exp= 0;



#undef test
}







