#include<stdio.h>
#include<stdlib.h>
#define count 10
int main(int argc, char *argv[])
   {
   	//practising dynamic memory allocation
   	double* p;
   	p = calloc(10, sizeof(double));
   	for (int i = 0; i < count; ++i)
   	{
   		scanf("%lf", (p + i));
   	}
   	for (int i = 0; i < count; ++i)
   	{
   		printf("*(p + %d) = %lf\n", i, *(p+i) );
   	}

   
	return 0;
}
