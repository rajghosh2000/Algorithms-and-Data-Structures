#include <stdio.h>
#include<stdlib.h>


struct Node
{
    int des; //destination
    int wei; 
    struct Node* next;
};

struct List //to form List type node in the graph 
{
    struct List *h; //head 
};

struct Gph
{    //graph
    int nov;//no. of vertcies
    struct List* l; //the array  containing the vertices
};

struct Node* listNode(int des,int weight)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->des = des;
    newNode->wei = weight;
    newNode->next=NULL;

    return newNode;
}

struct Gph* createGraph(int nov)
{
    struct Gph* g = (struct Gph*)malloc(sizeof(struct Gph));
    g->nov = nov; //the no of vertices to be hold in the graph

    g->l = (struct List*)malloc(nov * (sizeof(struct List))); // The list will contain no of vertices no.of node 
    
    //Need to initialize the node heads with null pointing now
    int i=0;
    while(i<nov)
    {
        g->l[i].h = NULL;
        i++;
    }

    return g;
}

void addNode(struct Gph* g, int s , int d,int weight )
{   //s--> src and d--> des
    struct Node* newNode = listNode(d,weight);
    newNode->next = g->l[s].h; // The address stored at head of the list is now also stored in the newNode next
    g->l[s].h = newNode; //newNode is now the nxt node of the list with that source

    //Same procedure with destinatio as the source now and source as the destination as it is a undirected graph
    newNode = listNode(s,weight);
    newNode->next = g->l[d].h;
    g->l[d].h = newNode;

}

void print(struct Gph* g)
{
    int i=0;
    
    while(i<g->nov)
    {
        struct Node* t = g->l[i].h;
        printf("\nThe Vertices Connected to vertex %d ",i);
        while(t!=NULL)
        {
            printf(" -> %d",t->des);
            t=t->next;
        }
         i++;
    }
   
}


int main()
{
    int v=4,i,j,r,weight;
    int cost[v][v];
    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
            cost[i][j]=0;
        }
    }
    struct Gph* gph = createGraph(v); 
    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
            if(i!=j)
            { 
                if(cost[i][j]==0)
                {
                    printf("\n Is %d and %d or %d and %d connected by an edge :",i,j,j,i);
                    scanf("%d",&r);

                    if(r==1)
                    {
                        printf("       Weight of the edge %d and %d or %d and %d ...Weight should not exceed 100: ",i,j,j,i);
                        scanf("%d",&cost[i][j]);
                        weight = cost[i][j];
                        addNode(gph,i,j,weight);
                        cost[j][i]=cost[i][j];
                    }
                    else
                    {
                        cost[i][j]=cost[j][i]=999;
                    } 
                    
                } 
                
            }
         }
       
    }
    print(gph);
    
}
