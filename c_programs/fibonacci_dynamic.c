#include<stdio.h>
#include<stdlib.h>
#define MAX 50
int fibonacci(int);
int cache[5] = {-1, -1, -1, -1, -1};
int main(int argc, char *argv[])
{
    int x;
    x = fibonacci(10);
    printf("%d\n", x);
    return 0;
}

int fibonacci(int n)
{
    if(n <= 1){
        cache[n] = 1;
        return 1;
    }
    else
    {
	    if(cache[n-2] == -1) cache[n-2] = fibonacci(n - 2);
	    if(cache[n - 1] == -1 ) cache[n-1] = fibonacci(n-1);
	    return cache[n -1] + cache[n-2];
    }
}
