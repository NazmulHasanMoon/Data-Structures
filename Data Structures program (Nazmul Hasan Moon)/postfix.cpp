#include<bits/stdc++.h>
using namespace std;
int main()
{
    stack<char>st;
    string q;
    vector<char>p;
    cin>>q;
    st.push('(');
    q.push_back(')');
    int l=q.size();
    for(int i=0; i<l; i++)
    {
        if(q[i]!='+'&&q[i]!='-'&&q[i]!='*'&&q[i]!='/'&&q[i]!='^'&&q[i]!='('&&q[i]!=')')
            p.push_back(q[i]);
        else if(q[i]=='(')
            st.push(q[i]);
        else if(q[i]==')')
        {
            while(st.top()!='(')
            {
                p.push_back(st.top());
                //cout<<st.top()<<' ';
                st.pop();
            }
            st.pop();
        }
        else
        {
            if(q[i]=='^')
            {
                while(st.top()=='^')
                {
                    p.push_back(st.top());
                    //cout<<st.top()<<' ';
                    st.pop();
                }
            }
            else if(q[i]=='/'||q[i]=='*')
            {
                while(st.top()=='^'||st.top()=='/'||st.top()=='*')
                {
                    p.push_back(st.top());
                    //cout<<st.top()<<' ';
                    st.pop();
                }
            }
            else
            {
                while(st.top()!='(')
                {
                    p.push_back(st.top());
                    //cout<<st.top()<<' ';a+(b*c-(d/e^f)*g)*h
                    st.pop();
                }
            }
            st.push(q[i]);
            //cout<<q[i]<<' ';
        }

    }
    //cout<<st.top()<<endl;
    for(auto i: p)
        cout<<i;
    cout<<endl;
    return 0;
}
