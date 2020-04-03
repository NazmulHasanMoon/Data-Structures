#include<bits/stdc++.h>
using namespace std;
int i;
string s;
void digit()
{
    while(isdigit(s[i])&&s[i]!='\0'&&s[i]!=EOF)
        i++;
}
int main()
{
    freopen("number.txt","r",stdin);
    freopen("numberO.txt","w",stdout);

    int l;
    while(cin>>s)
    {
        if(isdigit(s[0]))
        {
            i=1;
            digit();
            if(s[i]=='\0'||s[i]==EOF)
                cout<<"Number\n";
            else if(s[i]!='E'&&s[i]!='.')
                cout<<"Not a number\n";
            else if(s[i]=='.')
            {
                i++;
                digit();
            }
            else if(s[i]=='E')
            {
                i++;
                if(s[i]=='+'||s[i]=='-')
                {
                    i++;
                    digit();
                }
                else if(isdigit(s[i]))
                    digit();
                if(s[i]=='\0'||s[i]==EOF)
                    cout<<"Number\n";
                else
                    cout<<"Not a number\n";
            }
        }
        else
            cout<<"Not a number\n";
    }
    return 0;
}
