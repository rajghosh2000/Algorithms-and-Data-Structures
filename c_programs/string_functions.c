#include <stdio.h>



void my_copy();
int my_strlen();
void my_strcat();
char* my_strchr();
int main(void)
{
	typedef unsigned int Array[10];
	Array myarray;
	printf("%d\n", sizeof(myarray));

}


void my_copy(const char* src, char * dest)
{
	while(*src != '\0')
		*dest++ = *src++;
}
int my_strlen(const char * src)
{
	int i = 0;
	while(*src)
	{
		*src++;
		i++;
	}
	return i;
}
void my_strcat(const char * src,char * dest)
{
	while(*dest)
	{
		// for traversing the destination string till we find a \0 symbol
		*dest++;
	}
	while(*src){
		// copying the source string to the destination after the \0 char of the string.
		*dest++ = *src++;
	}
	*dest = '\0';
}

char * my_strchr(char * str, int c)  // it should be const 'char * str' instead of 'char * str'
{
	while(*str != c){
		// traversing the array 
		*str++;
	}
	printf("%p\n", str);
	return str;
}
