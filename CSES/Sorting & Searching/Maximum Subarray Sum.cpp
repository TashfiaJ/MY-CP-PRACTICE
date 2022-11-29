#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
   
        ll n;
        cin >> n;
        ll a[n];
        for(ll i=0;i<n;i++)
        {
            cin >> a[i];
        }
        ll ans=a[0];
        ll aans=a[0];
        for(ll i=1;i<n;i++)
        {
            if(ans+a[i]>a[i])ans+=a[i];
            else ans=a[i];
            aans=max(aans,ans);
        }
        cout<<aans;
    
}
