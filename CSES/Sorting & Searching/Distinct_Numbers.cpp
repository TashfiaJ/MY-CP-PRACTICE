#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
   
        ll n;
        cin >> n;
        set<ll>s;
        for(ll i=0;i<n;i++)
        {
            ll x;
            cin >> x;
            s.insert(x);
        }
        cout<<s.size();
    
}
