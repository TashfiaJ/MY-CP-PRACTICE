#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main()
{
    ll n,c=0; cin >> n;
    ll temp = n;
    while(n)
    {
        ll maxx=0;
        temp = n;
        while(temp)
        {
            maxx=max(maxx, temp%10);
            temp/=10;
        }
        n-=maxx;
        c++;
    }
 
    cout << c;
}
