#include<stdio.h>
int fibonacci(int);
int main(int argc, char *argv[])
{
    int x;
    x = fibonacci(-10);
    printf("%d\n", x);
    return 0;
}

int fibonacci(int n)
{
    if(n <= 1)
        return n;
    else if(n == 1)
        return 1;
    else
        return fibonacci(n-2) + fibonacci(n-1);
}
