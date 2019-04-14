/*

We are adding the individual elements of the array one by one and then if there is a carry ,
we add it to the element in the previous block.
PROBLEMS:
    1. we are considering that the arrays are of same length.
    2. Not calculating the time complexity.
*/

#include <stdio.h>
int main(int argc, char const *argv[])
{
  //For obtaining the element in the arrays
  int N1,N2,sumd = 0,carry = 0;
  printf("Enter the number of elements in the first array: \t");
  scanf("%d",&N1);
  printf("Enter the number of elements in the Second array: \t");
  scanf("%d",&N2);
  int array1[N1],array2[N2],sum[N1];
  printf("Enter the values of the first array\n");
  for (int i = 0; i < N1; ++i)
  {
    scanf("%d",&array1[i]);
  }
  printf("Enter the values of the Second array\n");
  for (int i = 0; i < N2; ++i)
  {
    scanf("%d",&array2[i]);
  }
  //NOW, Adding the value of the arrays
  for (int i = N1-1; i >=0; --i)
  {
    sumd = array1[i]+array2[i]+carry;
    if(sumd>9){
      sumd = sumd%10;
      sum[i] = sumd;
      carry = 1;
    }
    else
    {
      sum[i] = sumd;
      carry = 0;
    }
  }
  //Now, we print the array
  printf("The summed array is :\t");
  for (int i = 0; i < N1; ++i)
  {
    printf("%d\t", sum[i]);
  }
  return 0;
}