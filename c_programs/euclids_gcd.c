#include<stdio.h>
int euclid_gcd(int , int);
int euclid_gcd_2(int, int);
int main(int argc, char *argv[])
{
    int a,b;
    printf("Enter the Number: \t");
    scanf("%d %d", &a, &b);
    printf("\nGCD of %d and %d is: %d\n", a, b, euclid_gcd(a, b));
    printf("\nMethod 2, GCD of %d and %d is: %d\n", a, b, euclid_gcd_2(a, b));

    return 0;
}
// version 1, the naive method
int euclid_gcd(int a, int b)
{
    while(a != b && a > 0 && b > 0)
    {
        if(a > b)
            a = a - b;
        else
            b = b - a;
        printf("%d, %d\n", a, b);
    }
    return a;
}
// version 2, replacing subtraction with remainder
int euclid_gcd_2(int a, int b)
{
    while(a != b && a > 0 && b > 0)
    {
        if(a > b)
            a = a % b;
        else
            b = b % a;
        printf("%d, %d\n", a, b);
        if(a % b == 0) return a;
	else if(b % a == 0) return b;
    }
}
