//--------------------------------CSB18012--------------------------------------------------//


#include<iostream>
#define maxEdge 9
#define inf 100

using namespace std;

void minheapify(int a[],int n, int root)
{
    int smallest = root;

    int l = 2*root+1;
    int r = 2*root+2;

    if(l<n && a[l] < a[smallest])
    {
        smallest=l;
    }
    if(r<n && a[r] < a[smallest])
    {
        smallest=r;
    }

    if(smallest!=root)
    {
        swap(a[root],a[smallest]);
        minheapify(a,n,smallest);
    }
    
}
void chk(int a[maxEdge][maxEdge],int parent[maxEdge],int v , int k)
{
    int i,j,con=0,x,y;
    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
            if(a[i][j]==k)
            {
                x=i;
                y=j;
                con=1;
                a[i][j]=a[j][i]=inf;
                break;
            }
        }
        if(con==1)
        {
            break;
        }
    }
    parent[y]=parent[x]=1;
    cout<<endl<<"The edge between "<<x<<" -> " <<y<<" with cost : "<<k;
    cout<<endl;

}

void fMST(int cost[maxEdge][maxEdge], int v)
{
    int parent[v],i,j,tem[v][v],edge_cnter=0,initial_min;
    int mincost=0;
    int heaparr[(v*(v-1))/2];

    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
            if(cost[i][j]==0)
            {
                cost[i][j]=inf;
            }
        }
    }

    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
            tem[i][j] = cost[i][j];
        }
    }

    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
            if(tem[i][j]<inf)
            {
                heaparr[edge_cnter++] = tem[i][j];
                tem[i][j]=tem[j][i]=inf; 
            }
        }
    }

    for(i=0;i<v;i++)
    {
        parent[i]=0;
    }

    for(i=0;i<v;i++)
    {
        for (int k = (v-i) / 2 - 1; k >= 0; k--) {
             minheapify(heaparr, v-i, k); 
        }
        initial_min = heaparr[0];
        if(parent[i]==0)
        {
            chk(cost,parent,v,initial_min);
            mincost+=initial_min;
        }
        swap(heaparr[0],heaparr[v-i-1]);
    }

    cout<<endl<<"The Minimum Cost of the the MST :"<<mincost;

}

int main()
{
    int v,i,j;
    cout<<"This is Prims Algo for Undirected Graph\n";
    cout<<"\nHow Many Vertices ... Should not exceed 8 ? : ";
    cin>>v;

    int cost_mat[maxEdge][maxEdge];
    int r;
    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
            cost_mat[i][j]=0;
        }
    }
    cout<<"Enter 1 if there exits an edge and then the weight or 0 for no edge";
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
                    cout<<"\n Is "<<i<<" and "<<j<<" or "<<j<<" and "<<i<<" connected by an edge :";
                    cin>>r;

                    if(r==1)
                    {
                        cout<<"       Weight of the edge "<<i<<" and "<<j<< " or "<<j<<" and "<<i<<" ...Weight should not exceed 100: ";
                        cin>>cost_mat[i][j];
                        cost_mat[j][i]=cost_mat[i][j];
                    }
                    else
                    {
                        cost_mat[i][j] = cost_mat[j][i] = inf;
                    }
                    
                } 
                
            }
         }
       
    }
    cout<<"\nThe cost matrix is : \n";
    cout<<"\n";
    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
            cout<<cost_mat[i][j]<<"\t";
        }
        cout<<"\n";
    }
    cout<<"\t"<<"            "<<"\t..........................................100 is given to those edge which doesnot exist\n";
    
    fMST(cost_mat,v);
}




