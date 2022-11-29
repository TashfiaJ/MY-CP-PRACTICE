#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a, b, c;
        cin>>a>>b>>c;
        if((a+b+c)%3==0)cout<<"Peaceful\n";
        else cout << "Fight\n";
    }
}
