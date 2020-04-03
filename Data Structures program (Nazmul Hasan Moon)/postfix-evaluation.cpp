/*-------------------------------------------------------------------
Md. Nazmul Hasan Moon

Problem : Evaluation of Postfix Expression


---------------------------------------------------------------------*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string p;
    cin>>p;
    ///p.push_back(')'); useless
    stack<int>st;
    ///cout<<p<<endl;
    int l=p.size();
    for(int i=0;i<l;i++)
    {
        if(p[i]!='+'&&p[i]!='-'&&p[i]!='*'&&p[i]!='/'&&p[i]!='^'&&p[i]!=',')
        {
            int j,x=0;
            for(j=i;p[j]!=','&&j<l;j++){
                int z=p[j]-48;
                x=x*10+z;
            }
            i=j-1;
            st.push(x);
            //cout<<st.top();
        }
        else if(p[i]!=',')
        {
            int x,y;
            x=st.top(),st.pop();
            y=st.top(),st.pop();
            if(p[i]=='+')
                st.push(y+x);
            else if(p[i]=='-')
                st.push(y-x);
            else if(p[i]=='*')
                st.push(y*x);
            else if(p[i]=='/')
                st.push(y/x);
            else{
                double z=pow(y+0.0,x);
                int k=(int)z;
                if(k<z)
                    k++;
                st.push(k);
            }
        }

    }
    cout<<st.top()<<endl;
    return 0;
}
