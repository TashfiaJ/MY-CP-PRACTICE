#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll c (ll n)
{
    ll ans  =0;
    while(n)
    {
        ans += (n/5);
        n/=5;
    }
    return ans;
}

int main()
{
    ll t, tc=1;
    cin >> t;
    while(t--){
    
        ll n; scanf("%lld", &n);
        ll l=1, r=1e9, ans = -1, mid;
        printf("Case %lld: ", tc++);
        while(l<=r)
        {
            mid = l+(r-l)/2;
            ll temp = c(mid);
            if(temp==n)
            {
                ans = mid;
                r = mid-1;
            }
            else if(temp<n)
            {
                l = mid+1;
            }
            else
                r = mid-1;
        }
    
    if(ans==-1)
    {
        printf("impossible\n");
    }
    else{
        printf("%lld\n", ans);
    }
}}
