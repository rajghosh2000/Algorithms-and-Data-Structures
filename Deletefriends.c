#include<stdio.h>
#include<stdlib.h>
/*

														NOT RESOLVED:
														Algorithm Delete(Friend):
													    DeleteFriend=false
													    for i = 1 to Friend.length-1
													         if (Friend[i].popularity < Friend[i+1].popularity)
													            delete i th friend
													            DeleteFriend=true
													            break
													    if(DeleteFriend == false)
													        delete the last friend


*/
typedef struct friend
{
	int popularity;
	struct friend * next_friend;
} friend;
void disp(friend * list);
friend * createFriend();
friend * filterlist(friend * list);
int main()
{
	friend * list;
	list = createFriend();
	disp(list);
	list  = filterlist(list);
	disp(list);
}
friend * createFriend()
{
	int n;
	friend * temp = NULL;
	friend * p = NULL;
	friend * list = NULL;
	scanf("%d",&n);//no of test cases
	for (int i = 0; i < n; i++)
	{
		temp = (friend *)malloc(sizeof(friend));//isolated friend created
		printf("Enter data for friend no: %d\n", i+1);
		scanf("%d",&(temp->popularity));//data input
		temp->next_friend = NULL;
		if(list == NULL)
			list = temp;
		else{
			p = list;
			while(p->next_friend != NULL)
			{
				p = p->next_friend;
			}
			p->next_friend = temp;
		}
	}return list;
}
void disp(friend * list)
{
	while(list != NULL){
		printf("%d\t", list->popularity);
		list = list->next_friend;
	}
}
friend * filterlist(friend * list){
	friend * p = list;
	friend * previous;
	friend * next;
	while(p->next_friend != NULL)
	{
		previous = p;
		p = p->next_friend;
		next = p->next_friend;
		if((previous->popularity)>p->popularity)
			{
				previous->next_friend = next->next_friend;
			}
	}
	return list;

}