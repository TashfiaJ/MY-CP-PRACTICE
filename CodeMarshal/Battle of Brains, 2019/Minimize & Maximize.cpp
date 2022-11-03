#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi acos(-1.0)
int main()
{
    int t;
    scanf("%d", &t);
    for(int i=1;i<=t;i++)
    {
        ll n, mini, maxi;
        scanf("%lld", &n);
        mini=n-1;
        ll x = (n-2)/2;
        ll y = (n-2)/2 +((n-2)%2);
        maxi = x+y+(x*y);
        printf("Case %d: %lld %lld\n", i,mini,maxi);
    }
}
