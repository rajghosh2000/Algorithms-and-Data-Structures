#include<stdio.h>
#define count 10
/*

The current problems in the program is , 
	1.we have to give the array in the starting of the program.
	(Implement something to take the input of the array as the file)
	2. The array should be in sorted order.So,We have to implement a sorting function.

*/

//......................binary_search.............................//



int binary_search(int arr[], int low, int high, int key){
while(low <= high)
{
	int mid = (high + low)/2;
	if(arr[mid]<key)
		{
			low = mid + 1;
		}
	else if (arr[mid]>key)
	{
		high = mid-1;
	}
	else if(arr[mid]==key)
	{
        return mid;
	}

}
return -1;
}
//.......................MAIN FUNCTION.....................................//
int main()
{

int arr[count],key;
for (int i = 0; i < count; ++i)
{
	arr[i] = 3*i;
}
for (int i = 0; i < count; ++i)
{
	printf("%d ", arr[i] );
}
printf("\nEnter the value to search for: \t");
scanf("%d", &key);
int high = sizeof(arr)/sizeof(arr[1]);
int result = binary_search(arr , 0, high-1, key);
printf("\nThe answer is found at index no: %d\n", result);
}
