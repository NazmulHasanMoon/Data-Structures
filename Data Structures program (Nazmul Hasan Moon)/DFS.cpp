#include<bits/stdc++.h>
using namespace std;
#define sz 50
int g[sz][sz],a[sz],r[sz];
int main()
{
    int n,e,in;
    cout<<"Enter number of vertexs & number of edges:\n";
    cin>>n>>e;
    cout<<"Enter the origin & then destination of each edges:\n";
    int x,y;
    for(int i=1;i<=e;i++)
    {
        cin>>x>>y;
        g[x][y]=1;
    }
    cout<<"Enter the initial vertex:\n";
    cin>>in;
    stack<int>st;
    st.push(in);
    int z;
    while(!st.empty())
    {
        cout<<st.top()<<' ';
        z=st.top();
        r[z]=1;
        st.pop();
        for(int i=1;i<=n;i++)
        {
            if(g[z][i]&&!r[i])
                st.push(i),r[i]=1;
        }
    }
    return 0;
}
