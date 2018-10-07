#include<stdio.h>
#include<stdlib.h>
//1.Made a linked list consisting of n nodes
//2.Added a new node in the front 
//3.Added a new node at the back
//4.fucntion to print the linked list
TODO:
1.Delete a node at a particular position
2.Add a node at a particular position
3.Implement Stacks using linked list basically implement the
	functions push() pop() and top()
4.Implement queues using linked list , implementing the enqueue and dequeue fucntion
// a structure to create a linked list 

typedef struct node {
	int data;
	struct node * next;
} node;

node * createLinkedlist(int n);
void displayList(node * head);
node * newnodefront(node* HEAD);
node * newnodeback(node * HEAD);

int main(int argc, char const *argv[])
{
	int n;
	node * HEAD = NULL;
	printf("Enter the number of nodes to be created : ");
	scanf("%d", &n);
	HEAD = createLinkedlist(n);
	displayList(HEAD);
	HEAD = newnodefront(HEAD);
	printf("After adding the node in the front\n");
	displayList(HEAD);
	HEAD = newnodeback(HEAD);
	printf("After addingthe node in the back \n");
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
node* newnodefront(node * head){
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
node * newnodeback(node * head){
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
		printf("this runs %d times", ++i);
		
	}
	p->next = temp;		
return head;
}