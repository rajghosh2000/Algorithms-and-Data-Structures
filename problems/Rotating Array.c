#include <stdio.h>
void RotateArray();
int main(int argc, char const *argv[])
{
	int test_cases;
	printf("Enter the number of test cases : \t");
	scanf("%d", &test_cases);
for (int i = 0; i < test_cases; ++i)
	{
	RotateArray();
	}
	return 0;
}
void RotateArray()
{
	int 	no_of_elements, rotate_by,j=0;
	printf("Total Number of elements in the Array: \t");
	scanf("%d", &no_of_elements);
	printf("No of elements to rotate by: \t");
	scanf("%d", &rotate_by);
	int a[no_of_elements], b[rotate_by];
		for (int i = 0; i < no_of_elements; ++i)
		{
			printf("Element %d: \t", i+1);
			scanf("%d", &a[i]);
		}
		for (int i = 0; i < rotate_by; ++i)
		{
			b[i] = a[i];
			printf("b[%d]: %d\n",i, b[i]);
		}
		printf("\nRotating......... \n");
		for (int i = 0; i < no_of_elements; ++i)
		{
			a[i] = a[i+rotate_by];
			printf("a[%d] is now: %d\n",i, a[i] );
			if (a[i+rotate_by]== a[no_of_elements-1])
			{
				break;
			}
		}
		for (int i = no_of_elements-rotate_by; i < no_of_elements; ++i)
		{
			a[i] = b[j];
			printf("a[%d] is now: %d\n",i,a[i] );
			j = j+1;
		}
		printf("Printing.......\n");
		for (int i = 0; i < no_of_elements; ++i)
		{
			printf("%d\n", a[i]);
		}
}