#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
   
        ll t;
        cin >> t;
        while(t--)
        {
                ll n,ans=-10005;
                cin >> n;
                ll a[n+1],pre=0,mini=0;
                for(ll i=1;i<=n;i++)
                {
                        cin>>a[i];
                        ans=max(ans,a[i]+pre*2-mini);
                        pre+=a[i];
                        mini=min(mini,pre);
                }
                cout<<ans<<'\n';
                
        }
    
}
