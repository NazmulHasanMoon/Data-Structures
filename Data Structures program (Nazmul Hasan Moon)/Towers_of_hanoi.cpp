#include<bits/stdc++.h>
using namespace std;
void hanoi(int n,char BEG,char AUX,char END)
{
    if(n>=1){
        hanoi(n-1,BEG,END,AUX);
        printf("%c to %c\n",BEG,END);
        hanoi(n-1,AUX,BEG,END);
    }

}
int main()
{
    int n;
    cin>>n;
    hanoi(n,'A','B','C');
    return 0;
}
