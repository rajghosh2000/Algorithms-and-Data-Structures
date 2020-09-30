

#include<stdio.h>
#include<stdlib.h>
#define nonEdgeValue 100 // This value is for no edge in the graph




int parent_vertex_array[9];



int find(int v)
{
    while(parent_vertex_array[v]!=0)
    {
        v = parent_vertex_array[v];
    }
    return v;
}

int union_structure(int v1,int v2)
{
    if(v1!=v2)
    {
        parent_vertex_array[v2]=v1;
        return 1;
    }
    return 0;
}




int main()
{
    printf("This is Kruskals Algo for Undirected Graph\n");
    int i, j, v;
    printf("\nHow Many Vertices ... Should not exceed 8 ? : ");
    scanf("%d", &v);
    int cost_mat[v][v];
    int r;
    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
            cost_mat[i][j]=0;
        }
    }
    printf("Enter 1 if there exits an edge and then the weight or 0 for no edge");
    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
            if(i==j)
            {
                cost_mat[i][j]=0; //all diagnal elements of a undirected graph is 0
            }
            else
            { 
                if(cost_mat[i][j]==0)
                {
                    printf("\n Is %d and %d or %d and %d connected by an edge :",i,j,j,i);
                    scanf("%d",&r);

                    if(r==1)
                    {
                        printf("       Weight of the edge %d and %d or %d and %d ...Weight should not exceed 100: ",i,j,j,i);
                        scanf("%d",&cost_mat[i][j]);
                        cost_mat[j][i]=cost_mat[i][j];
                    }
                    else
                    {
                        cost_mat[i][j] = cost_mat[j][i] = nonEdgeValue;
                    }
                    
                } 
                
            }
         }
       
    }
    printf("\nThe cost matrix is : \n");
    printf("\n");
    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
            printf("%d\t",cost_mat[i][j]);
        }
        printf("\n");
    }
    printf("\t..........................................100 is given to those edge which doesnot exist\n");
    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
            if(cost_mat[i][j]==0)
            {
                cost_mat[i][j] = nonEdgeValue; 
            }
        }
    }
    int k=1; // This will count the edges that will be put in the MST
    int mincost=0;
    int v1,v2,x,y;


    printf("The edges that will be in the MST are:\n");
    while(k<v)
    {
        int init_min = nonEdgeValue;
        for(i=0;i<v;i++)
        {
           for(j=0;j<v;j++)
            {
                if(cost_mat[i][j]<init_min)
                {
                    init_min = cost_mat[i][j];
                    v1=i;
                    v2=j;
                }
            }
        }
        
        x=find(v1);
        y=find(v2);

        if(union_structure(x,y)!=0)
        {
            printf("\n The edge between %d and %d with cost %d \n",v1,v2,init_min);
            mincost += init_min;
        }
        cost_mat[v1][v2]=cost_mat[v2][v1]=nonEdgeValue;
        k++;
    }
    printf("\n");
    printf("\nThe MST will have a cost of %d\n",mincost);
    
    
    
}

    
