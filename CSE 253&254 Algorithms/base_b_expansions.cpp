#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int q(n),b;
    stack<char>s;
    cout<<"Enter the base u wants to expansion:\n";
    cin>>b;
    while(q!=0)
    {
        int x=q%b;
        if(x==10)
            s.push('A');
        else if(x==11)
            s.push('B');
        else if(x==12)
            s.push('C');
        else if(x==13)
            s.push('D');
        else if(x==14)
            s.push('E');
        else if(x==15)
            s.push('F');
        else{
            s.push(char(48+x));
        }
        q/=b;
    }
    if(n==0)
        cout<<"0\n";
    while(!s.empty())
    {
        cout<<s.top();
        s.pop();
    }
    return 0;
}
