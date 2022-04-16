#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll t, tc=1;
    scanf("%lld", &t);
    while(t--)
    {
        ll n, q;
        scanf("%lld %lld", &n, &q);
        ll a[n];
        for(ll i=0;i<n;i++)scanf("%lld", &a[i]);
        printf("Case %lld:\n", tc++);
        while(q--)
        {
            ll l, r;  scanf("%lld %lld", &l, &r);
            ll ub = upper_bound(a, a+n, r)-a;
            ll lb = lower_bound(a, a+n, l)-a;
            printf("%lld\n", ub-lb);
        }
    }
}
