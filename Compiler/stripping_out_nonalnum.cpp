#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("nonalnumI.txt","r",stdin);
    freopen("nonalnumO.txt","w",stdout);
    char ch;
    while(cin>>ch){
        if(isalnum(ch))
            cout<<ch;
    }
    return 0;
}
