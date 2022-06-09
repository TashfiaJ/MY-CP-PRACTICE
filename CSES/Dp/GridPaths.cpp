#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9+7;
 
ll n;
string s[1005];
ll dp[1005][1005];
 
ll grid (ll r, ll c)
{
    if(r==0 && c==0 && s[0][0]=='.')return dp[0][0]=1;
    if(r<0 || c<0)return 0;
    if(s[r][c]=='*')return dp[r][c]=0;
    if(dp[r][c]!=-1)return dp[r][c];
    if(s[r][c]=='.'){
       return dp[r][c]=(grid(r-1, c)+ grid(r,c-1))%MOD;
    }
}
int main()
{
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for(ll i=0;i<n;i++)
        cin >> s[i];
    cout<< grid(n-1, n-1);
}
