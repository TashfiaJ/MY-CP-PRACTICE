#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
   ll n;
   cin >> n;
   pair<ll,ll> a[n+n];
   for(ll i=0;i<n;i++)
   {
        cin>>a[i].first>>a[n+i].first;
        a[i].second=1;
        a[n+i-1].second=2;
   }
   sort(a,a+(2*n));
   //for(ll i=0;i<2*n;i++)cout<<a[i].first<<" ";
   ll ans=0,ans2=0;
   for(ll i=0;i<2*n;i++)
   {
        if(a[i].second==1)ans++;
        else ans--;
        ans2=max(ans,ans2);
   }
        cout<<ans2;
    
}
