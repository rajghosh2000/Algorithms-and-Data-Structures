#include<stdio.h>
#include<math.h>
#include "./user_libraries/calculating_factorial.h"
double taylor_series(int, int);
double e(int, int);
int main(int argc, char *argv[])
{
    double taylor_value = taylor_series(1, 10);
    printf("%lf\n", taylor_value);
    double static_taylor_value = e(1, 10);
    printf("%lf\n", static_taylor_value); 
    return 0;
}
double taylor_series(int x, int n)
{
    if(n == 0)
        return 1;
   return  pow(x, n)/factorial(n) + taylor_series(x, n - 1);
}

double e(int x, int n)
{
    static double p = 1, f = 1;
    double r;
	if(n == 0) return 0;
    r = e(x, n - 1);
	p = p * x;
	f = f * n;
	return r + p/f ;
}

