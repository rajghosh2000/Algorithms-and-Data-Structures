#include<stdio.h>
#define max 20
void sum();
int n, num1[max],num2[max], temp, result[max+1], carry = 0;
int main(){
//........................................Taking the numbers of aray as input;
	printf("Enter No of Digits to Add\n");
	scanf("%d", &n);
	printf("Enter the first Number:\n");
	for (int i = max-1; i >= max - n; --i)
	{
		scanf("%d", &num1[i]);
	}
	printf("Enter the second number: \n");
	for (int i = max-1; i >= max-n; --i)
	{
		scanf("%d", &num2[i]);
	}
	sum();
}
//............................Implementing Sum Now
void sum(){
	int result[max+1];
	for(int i = max-1; i >=0; --i)
	{
		if(carry==1)
			result[i+1] = (num1[i] + num2[i] +1)%10;
		else{
			result[i+1] = (num1[i] + num2[i])%10;
		}
		carry = (num1[i] + num2[i])/10;

	}
	if(carry==1)
		result[0]==1;
	for (int i = n; i >=0; --i)
	{
		printf("%d  ", result[i]);
	}

}