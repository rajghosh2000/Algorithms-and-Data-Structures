#include<stdio.h>
int main(int argc, char const *argv[]) {
    int n1, n2,temp;
  printf("Enter the number of elements in the first array\n");
  scanf("%d", &n1);
  int a1[n1], sum[n1], carry = 0;
  int result[n1+1];
  printf("Enter the values of the first array\n");
  for (int i = 0; i < n1; i++) {
    scanf("%d", &a1[i]);
  }
  printf("Enter the number of elements in the second array\n");
  scanf("%d", &n2);
  int a2[n2];
  printf("Enter the values of the second array\n");
  for (int i = 0; i < n2; i++) {
    scanf("%d", &a2[i]);
  }
  for (int i = n1-1; i >= 0; i--) 
  {
  	if(carry==1)
  		result[i] = a1[i] + a2[i]+1;
    else
    result[i] = a1[i] + a2[i];
    temp = result[i]%10;
    if ((result[i]/10)==1)
    {
    	carry = 1;
    }
    result[i] = temp;

  }
  result[0]= 5;
  //for the carry in the most significant place
  if (carry==1)
  {
  	result[1]= (result[1]+1)%10;
  	if (result[1]/10==1)
  	{
  		result[0] = 1;
  	}
  }
  //for printing the array
  for (int i = 0; i < n1; i++) {
    printf("%d\t", result[i]);
  }
  
  return 0;
}