#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
   
        ll n, m, k;
        cin >> n >> m >> k;
        ll a[n], b[m];
        for(ll i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(ll i=0;i<m;i++)
        {
            cin>>b[i];
        }
        sort(a,a+n);
        sort(b,b+m);
        ll ans=0;
        ll i=0,j=0;
        while(i<n && j<m)
        {
            if(abs(a[i]-b[j])<=k)
            {
                ans++;
                i++;
                j++;
            }
            else if(a[i]<b[j])
            {
                i++;
            }
            else
            {
                j++;
            }
        }
        cout << ans;
        
    
}
