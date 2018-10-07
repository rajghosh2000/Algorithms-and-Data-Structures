//linear search algorithim
#include<stdio.h>
int main(int argc, char const *argv[])
{
	int a,b;
	scanf("%d%d", &a, &b);
	int arr[a];
	int count = a-1;
	for (int i = 0; i < a; ++i)
	{
		scanf("%d", &arr[i]);
	}
	for (int i = a-1; i >= 0; --i)
	{
		if(arr[i]==b)
			{
				printf(" The index is: %d\n", count+1);
				break;
			}
			count--;

	}
	return 0;
}