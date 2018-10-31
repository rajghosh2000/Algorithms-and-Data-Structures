#include<stdio.h>
#include<stdlib.h>
//Created a linked list of n nodes
//implemented stacks using linked list-the pop() function,push() function
//implemented queues using linked list - the enqueue() function , dequeue() function,
//implemented deleting of node at a particular position
//implemented adding of node at a particular position
/*

								KNOWN BUGS: 
			THE FIRST ELEMENT CANNOT BE DELETED FROM THE LIST;



*/
typedef struct node {
	int data;
	struct node * next;
} node;

node * createLinkedlist(int n);
void displayList(node * head);//prints out the list of nodes
node * enqueue(node* head);//adds an element to the beginning
node * push(node * head);//adds and element to the end of the linked list
node * dequeue(node * head);//remove the topmost element of the linked list
node * del(node * head);//delete an element from a given postition
node * adp(node * head); // add and element to a given position of the linked list

int main(int argc, char const *argv[])
{
	int n;
	node * HEAD = NULL;
	printf("Enter the number of nodes to be created : ");
	scanf("%d", &n);
	HEAD = createLinkedlist(n);
	displayList(HEAD);
	HEAD = enqueue(HEAD);
	printf("After adding the node in the front\n");
	displayList(HEAD);
	HEAD = push(HEAD);
	printf("After addingthe node in the back \n");
	displayList(HEAD);
	HEAD = dequeue(HEAD);
	printf("\nAfter deleting a node: \n");
	displayList(HEAD);
	HEAD = del(HEAD);
	printf("After deleting at the desired position\n");
	displayList(HEAD);
	printf("\n Adding a node at the given position\n");
	HEAD = adp(HEAD);
	displayList(HEAD);
	return 0;
}


node * createLinkedlist(int n)
{
	node * head = NULL;
	node * temp = NULL;
	node * p = NULL;

	for (int i = 0; i < n; i++)
	{
		//creating an individual node 
		temp = (node*)malloc(sizeof(node));
		printf("Enter the data for node number %d: ", (i+1));
		scanf("%d", &(temp->data));
		temp->next = NULL;
		if(head == NULL)
			head = temp;//temp is assigned as first node if temp is the first node
		else
		{
			p = head;
			while(p->next != NULL)
				p = p->next;
			p->next = temp;
		}
	}
return head;
}

void displayList(node * head){
	node * p = head;
	while(p != NULL)
	{
		printf("%d\t",p->data );
		p = p->next; 
	}
}
node* enqueue(node * head){
	node* temp;
	temp = (node *)malloc(sizeof(node));
	printf("\nEnter data for the new node: \t");
	scanf("%d", &(temp->data));
	if(head==NULL){
		temp = head;
	}
	else{
		temp->next = head;
	}
	return temp;
}
node * push(node * head){
	int i = 0;
	node* temp;
	node* p;
	temp = (node *)malloc(sizeof(node));
	printf("\nEnter data for the new node: \t");
	scanf("%d", &(temp->data));
	temp->next = NULL;
	p = head;
	while(p->next != NULL){
		p = p->next;
		
	}
	p->next = temp;		
return head;
}
node * dequeue(node * head)
{
	node * p;
	p = head->next;
	head = p;
	return head; 
}
node * del(node * head){
	int a;
	node * p;
	node * q;
	printf("\nEnter the NODE position to Delete\n");
	scanf("%d", &a);
	if(a==1)
		{
			head = dequeue(head);
			return head;
		}
	p = head;
	for (int i = 1; i < a-1; ++i)
	{
		p = p->next;
	}
	q = p->next;
	p->next = q->next;
	return head;
}
node * adp(node * head){
	int a;
	node * q;
	node * p;
	q = (node * )malloc(sizeof(node));
	p = head;
	node * temp;
	temp = (node *)malloc(sizeof(node));
	printf("Enter Data for the Node: \n");
	scanf("%d", &(temp->data));
	printf("Enter the postition to add node: \t");
	scanf("%d", &a);
	for (int i = 1; i < a; ++i)
	{
		p = p->next;
	}
	q->next = p->next;
	p->next = temp;
	temp->next = q-next; 
	return head;
}