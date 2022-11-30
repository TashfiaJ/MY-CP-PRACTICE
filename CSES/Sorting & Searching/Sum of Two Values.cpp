#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll n, x;
    cin>>n>>x;
    pair<ll,ll>v[n];
    for(ll i=0;i<n;i++)
    {
        cin>>v[i].first;
        v[i].second=i+1;
    }
    sort(v,v+n);
    ll l=0,r=n-1;
    while(l<r)
    {
        if(v[l].first+v[r].first==x)
        {
            cout<<v[l].second<<" "<<v[r].second;
            return 0;
        }
        else if(v[l].first+v[r].first>x)
        {
            r--;
        }
        else
        {
            l++;
        }
    }
    cout<<-1;
   
}
