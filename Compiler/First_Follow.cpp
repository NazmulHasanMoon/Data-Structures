#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
string s,st[100];
map<char,string>mp,fst,flw;
string fir(char x)
{
    int l=mp[x].size();
    if(fst[x].empty())
    {
        for(int j=0; j<l; j++)
        {
            if(!isupper(mp[x][j]))
            {
                fst[x].push_back(mp[x][j]);
                while(mp[x][j]!='|'&&j<l)
                    j++;
            }
            else
                fst[x]+=fir(mp[x][j]);

        }
    }
    return fst[x];
}
string fol(char x,char w)
{
    int l=mp[x].size();
    for(int i=0; i<l; i++)
    {
        if(mp[x][i]==w)
        {
            ///cout<<mp[x][i]<<'-'<<i<<w<<endl;
start:
            if(i==l-1){
                if(isupper(mp[x][i]))
                    flw[w]+=flw[x];
                else
                    flw[w]+=mp[x][i];
            }
            else if(!isupper(mp[x][i+1])&&mp[x][i+1]!='|'&&i+1<l)
            {

                flw[w].push_back(mp[x][i+1]);

                while(mp[x][i]!='|'&&i<l)
                    i++;
            }
            else if(isupper(mp[x][i+1])&&i+1<l)
            {
                //cout<<mp[x][i+1]<<endl;
                char u=mp[x][i+1];
                flw[w]+=fst[u],i++;
               // cout<<w<<'='<<flw[w]<<'\n';
                int xx=fst[u].size();
                bool t=false;
                for(int z=0; z<xx; z++)
                {
                    if(fst[u][z]=='%')
                    {
                        t=true;
                        break;
                    }
                }
                if(t){
                    i++;
                    goto start;
                }
            }
        }
    }
    return flw[w];
}
int main()
{

    int i(0);
    while(cin>>s)
    {
        string str;
        if(!i)
            flw[s[0]]='$',i=1;
        if(mp.find(s[0])!=mp.end())
            str.push_back('|');
        for(int j=3; s[j]!='\0'; j++)
            str.push_back(s[j]);
        mp[s[0]]=str;
    }
    set<char>re;
    for(auto i:mp)
    {
        char w=i.ff;
        fst[w]=fir(w);
        //cout<<fst[w]<<endl;
    }
    for(auto i:mp)
    {
        char w=i.ff;
        for(auto j:mp)
            flw[w]+=fol(j.ff,w);//cout<<flw[w]<<' ';
        //cout<<endl;
    }
    //cout<<endl;
    for(auto i:fst)
    {
        cout<<"First of "<<i.ff<<"={";
        for(int j=0; i.ss[j]!='\0'; j++)
            re.insert(i.ss[j]);
        int k=re.size();
        for(auto j:re)
        {
            cout<<j;
            k--;
            if(k)
                cout<<',';
            else
                cout<<"}\n";
        }
        re.clear();
    }
    map<char,string>ans;
    for(auto i:flw)
    {
        map<char,bool>mm;
        cout<<"Follow of "<<i.ff<<"={";
        int len(0);
        for(int k=0;i.ss[k]!='\0';k++)
        {
            if(mm.find(i.ss[k])==mm.end())
                mm[i.ss[k]]=1,ans[i.ff].push_back(i.ss[k]),len++;
        }
        for(int j=0;j<len;j++)
        {
            cout<<ans[i.ff][j];
            if(j<len-1)
                cout<<',';
            else
                cout<<"}\n";
        }
    }
    return 0;
}
