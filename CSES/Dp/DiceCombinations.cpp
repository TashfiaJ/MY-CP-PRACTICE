#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
ll dp[1000005];
 
ll dice(ll sum)
{
    if(sum==0)return 1;
    if(dp[sum]!=-1)return dp[sum];
    ll way=0;
    for(ll j=1;j<7;j++){
        if(sum-j>=0)
    way += dice(sum-j);}
 
    return dp[sum]=(way%1000000007);
}
 
int main()
{
    
    memset(dp, -1, sizeof(dp));
    ll sum; cin >> sum;
    cout << dice(sum);
}
