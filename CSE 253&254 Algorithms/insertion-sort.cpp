#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=1;i<n;i++){
        int temp=a[i];
        int j=i-1;
        while(temp>a[j]&&j>=0){
            a[j+1]=a[j];
            j--;
           /// cout<<j<<' ';
        }
        a[j+1]=temp;
    }
    cout<<"After Insertion sorting:\n";
    for(int i=0;i<n;i++)
        cout<<a[i]<<' ';
    return 0;
}
