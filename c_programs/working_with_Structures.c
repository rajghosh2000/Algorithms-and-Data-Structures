#include <stdio.h>
#include <string.h>

struct  tag 
{
	char fname[30];
	char lname[20];
	int age;
	float rate;
};
void showname(struct tag *p);
struct tag my_struct;
int main(int argc, char const *argv[])
{
	// struct tag *st_ptr;  // pointer to struct
	// st_ptr = &my_struct; //assigning address of mystruct to structure pointer.
	strcpy(my_struct.fname,"Rituparna");
	strcpy(my_struct.lname, "Das");
	showname(&my_struct);
	return 0;
}
void showname(struct tag *p)
{
	printf("%s\n", p->fname);
	printf("%s\n", p->lname);
}