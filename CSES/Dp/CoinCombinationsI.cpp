#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1000000007;
ll n, sum, coin[200];
ll dp[1000005];
ll ways (ll target)
{
    if(target==0)return 1;
    if(dp[target]!=-1)return dp[target];
    ll way=0;
    for(ll i=0; i<n; i++)
    {
        if (target-coin[i]>=0)
            way+=ways(target-coin[i]);
    }
    return dp[target]=(way%mod);
}
 
int main()
{
    memset(dp, -1, sizeof(dp));
    cin >> n >> sum;
    for(ll i=0; i<n; i++) cin >> coin[i];
    cout << ways(sum);
}
