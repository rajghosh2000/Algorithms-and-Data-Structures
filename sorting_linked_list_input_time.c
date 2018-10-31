#include <stdio.h>
#include <stdlib.h>
//structure for node
typedef struct node
{
    int data;
    struct node * previous;
    struct node * next;
} node;
void displaylist(node * HEAD);
node * CreateNode(int n);
void displaylist(node * HEAD)
{
    node * p = HEAD;
    while(p != NULL)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
}
int main(){
    node * HEAD;
    int n;
    printf("Enter the no of nodes to be created: \t");
    scanf("%d", &n);
    HEAD = CreateNode(n);
    displaylist(HEAD);
}
node * CreateNode(int n){
    node * temp = NULL;
    node * head = NULL;
    node * p = NULL;
    //creating a temporary isolated node
    for (int i = 0; i < n; ++i) {
        temp = (node *)malloc(sizeof(node));
        printf("Enter the data to be entered in node %d :", i+1);
        scanf("%d", &(temp->data));
        if(head == NULL)
            {
                head = temp;
            }
        else{
            p = head;

            if( temp->data < p->data )
                {
                    p->previous = temp;
                    temp->next = p;
                    temp->previous = NULL;
                    head = temp;
                }
            while(temp->data > p->data && p->next != NULL)
            {
                printf("Traversing....\n");
                (p->next)->previous = p;
                p = p->next;
            }
            if(p->next == NULL && temp->data > p->data)
                    {
                        printf("Entered the p->next = NULL\n");
                        p->next = temp;
                        temp->previous = p;
                        temp->next = NULL;
                    }
            else if( temp->data < p->data)
            {
                (p->previous)->next = temp;
                temp->previous = p->previous;
                temp->next = p;
                p->previous = temp;
                printf("Value of p is: %d\n", p->data);
            }

            
        }

    }
    return head;
}