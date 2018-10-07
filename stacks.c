#include<stdio.h>
void pop(int a[], int *top);
void push(int value, int a[], int *top);
#define MAX 100


   int main(int argc, char const *argv[])
{
  
    int n,x,a[MAX],top,value;
    printf("Enter the number of elements to be Entered\t");
    scanf("%d",&n);
    for (int i = 0; i < n; ++i)
    {
      scanf("%d", &a[i]);
      top = i;
    }
    printf("Enter the value to push\n");
    scanf("%d",&value);
    push(value,a,&top);
    pop(a,&top);
}

  void push(int value, int a[], int *top){
    if((*top)==MAX-1)
      printf("The stack is Full.\n");
    else{
      (*top) +=1;
      a[(*top)] = value;
      printf("The value %d was pushed\n", value);
    }
  }
  
void pop(int a[], int *top){
  if(*(top)==-1)
    printf("The Stack is empty\n");
  else{
    (*top) -= 1; 
  }
}