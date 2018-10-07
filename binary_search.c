#include<stdio.h>
#define count 10

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
int result = binary_search(arr , 0, 9, key);
printf("\nThe answer is found at index no: %d\n", result);
}
