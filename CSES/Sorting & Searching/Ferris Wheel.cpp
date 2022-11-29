#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
   
        ll n, m;
        cin >> n >> m;
        ll a[n];
        for(ll i=0;i<n;i++)cin>>a[i];
        sort(a,a+n);
        ll ans=0,i=0,j=n-1;
        while(i<=j)
        {   
            if(i==j)
            {
                ans++;break;
            }
            if(a[i]+a[j]<=m)
            {
                ans++;
                i++;
                j--;
            }
            else
            {
                ans++;
                j--;
            }
            
        }
        cout<<ans;
}
