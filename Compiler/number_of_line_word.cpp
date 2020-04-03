#include<bits/stdc++.h>
using namespace std;

int main() {
	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    string ch;
    int x,y;
    x=y=0;
    while(getline(cin,ch))
    {
        /*for(int i=0;ch[i]!='\0';i++)
        {
            if(((isalnum(ch[i])||(i>0&&isalnum(ch[i-1])&&ispunct(ch[i])))&&isspace(ch[i+1]))||((isalnum(ch[i])||(ispunct(ch[i])&&i>0&&isalnum(ch[i-1])))&&ch[i+1]=='\0'))
                y++;
        }*/
        x++;
        ch.clear();
    }
    cout<<"Number of words: "<<y<<"\nNumber of lines: "<<x<<'\n';
    return 0;
}
