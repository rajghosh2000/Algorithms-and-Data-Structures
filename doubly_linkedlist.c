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
            head = temp;
        else{
            p = head;
            while(p->next != NULL)
            {
                p = p->next;
                p->previous = p;
            }
            p->next = temp;
            temp->previous = p;
        }

    }
    return head;
}