#include <stdio.h>
int natural_sum(int);
int recursion_sum(int);
int main(int argc, char *argv[])
{
    int number = 40;
    int xxvalue = recursion_sum(number);
    printf("%d\n", xxvalue);
    printf("%d\n", natural_sum(number));
    return 0;
}
int natural_sum(int n)
{
    return (n * (n+1))/2;
}
int recursion_sum(int n){
    if(n > 0)
    {
        return n + recursion_sum(n - 1);
    }
    return 0;
}
