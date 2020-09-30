#include<iostream>

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


int main()
{
    int n,i;
    cout<<"Enter the no of elements";
    cin>>n;
    int iarr[n];
    cout<<"Enter the elements";
    for(i=0;i<n;i++)
    {
        cin>>iarr[i];
    }   

    int initial_root_index = (n/2)-1;

    for(i=initial_root_index;i>=0;i--)
    {
        minheapify(iarr,n,i);
    } 

    for(i=0;i<n;i++)
    {
        cout<<iarr[i]<<" ";
    }
}