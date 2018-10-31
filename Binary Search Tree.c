#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    int data;
    struct node * left;
    struct node * right;
} node ;
node * createNode(int n);
int main(int argc, char const *argv[])
{
    int n;
    node * head;
    printf("Enter the no of node to be created: \n");
    scanf("%d", &n);
    head = createNode(int n);
    return 0;
}
node * createNode(int n){
    node * head = NULL;
    node * p = NULL;
    node * temp = NULL;
    //creating a new node 
    for(int i = 0;i<n;i++){
        temp = (node *)malloc(sizeof(node));
        printf("Enter data for the node %d", i+1);
        if(head == NULL)
            head = temp;
        else
        {
            p = head;
            if(temp->data > p->data){
                while(temp->data > p->data){
                    p = p->right;
                }
                while(temp->data < p->data){
                    p = p->left;
                }
                if(temp->data > p->data)
            }
            else if(temp->data < p->data){
                while(temp->data < p->data){
                    p = p->left;
                }
            }
        }
    }
}
