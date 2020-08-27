#include<stdio.h>
void hanoi(int, char, char, char); 
int main(int argc, char *argv[]) 
{ 
    hanoi(3, '1', '2', '3'); return 0; 
} 
void hanoi(int n, char a, char c, char b)
{
    if(n > 0)
    {
        hanoi(n-1, a, b, c);
        printf("Moving a block from %c to %c \n", a, c);
        hanoi(n-1, b, c, a);
    }
}
