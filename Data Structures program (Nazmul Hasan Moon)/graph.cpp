#include<bits/stdc++.h>
using namespace std;
#define sz 50
int graph[sz][sz];
int main()
{
    int v,e,x,y;
    cout<<"Enter number of nodes:\n";
    cin>>v;
    cout<<"Enter number of edges:\n";
    cin>>e;
    cout<<"Enter origin & destination of each nodes:\n";
    for(int i=0;i<e;i++)
        cin>>x>>y,graph[x-1][y-1]=1;
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
            cout<<graph[i][j]<<((j==v-1)?'\n':' ');
    }
    return 0;
}

