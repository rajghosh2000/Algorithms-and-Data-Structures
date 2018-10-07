//We start by counting form the thumb of the left hand as 1 and start moving right till the smallest finger and then 
//we count the ring finger as six and then move further to the left and so we do this everytime as we go on counting till 10;
#include<stdio.h>
int main(int argc, char const *argv[])
{
	int x = 1;
	for (int i = 1; i < 1001; ++i)
	{
		printf("%d \t", i);
		if(i == 5*x)
			{
				printf("\n");
				x++;
			}
	}
printf("%d\n", x);
	return 0;
}
