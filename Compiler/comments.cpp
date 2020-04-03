///Delete comments:
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ///ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);///faster I/O compiler: c++11
    freopen("cmntin.txt","r",stdin);///input file: cmntin.txt
    freopen("cmnto.txt","w",stdout);///output file: cmnto.txt
    string ch,cc;
    bool t=0;///this t=0 means t=false (use as a checker)
    while(getline(cin,ch))///get full string in a line input including white space,tab till End of File(EOF)
    {
        int j;
        //cout<<ch<<'?'<<endl;
        for(j=0; ch[j]!='\0'; j++)///ch[j]!='\0' looping means untill reach the end of string
        {
            if(!t&&ch[j]=='/')///!t means if t=0 && ch[j]=='/'
            {
                if(ch[j+1]=='*')
                {
                    j+=2;
                    t=1;///checker =1;
                    while(ch[j]!='\0'&&ch[j]!='*')
                        j++;
                    if(ch[j]=='*')
                    {
                        j++;
                        while(ch[j]!='\0'&&ch[j]!='/')
                            j++;
                        if(ch[j]=='/')
                            t=0;
                    }
                }
                else if(ch[j+1]=='/')
                {
                    j+=2;
                    while(ch[j]!='\0')
                        j++;
                    j--;
                }
                else
                    cout<<ch[j];
            }
            else if(t)
            {
                while(ch[j]!='\0'&&ch[j]!='*')
                    j++;
                if(ch[j]=='*')
                {
                    j++;
                    while(ch[j]!='\0'&&ch[j]!='/')
                        j++;
                    if(ch[j]=='/')
                        t=0;
                }
            }
            else
                cout<<ch[j];
        }
        ch[0]='\0';
        cout<<'\n';
    }
    return 0;
}
