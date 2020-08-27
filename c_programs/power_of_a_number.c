#include<stdio.h>
int power(int, int);
int nested_power(int, int);
int iterative_power(int, int);
int main(int argc, char *argv[])
{
    int value;
    value = iterative_power(2, 2);
    printf("Value is %d\n", value);
    return 0;
}
int power(int m, int n){
    if(n == 0){
        return 1;
    }
    return m * power(m, n - 1);
}

int nested_power(int m, int n)
{
    if(n == 0)
    {
        // returns the base value i.e. 1
        return 1;
    }
    if(n % 2 == 0)
    {
        return nested_power(m * m, n / 2);
    }
    else{
        return m * nested_power( m * m, n/2 ); 
    }
}

int iterative_power(int m, int n)
{
    int mult_val;
    for (int i = 0; i < n; i++) {
       mult_val = m * m; 
    }
    return mult_val;
}
