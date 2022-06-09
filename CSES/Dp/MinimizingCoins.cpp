#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main()
{
    int n, sum;
    cin >> n >> sum;
    vector<int>c(n);
    for(int&i: c)cin>>i;
    vector<int>dp(sum+1, 1e9);
    dp[0]=0;
    for(int i=1; i<=sum; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i-c[j]>=0)
                dp[i]=min(dp[i], dp[i-c[j]]+1);
        }
    }
    //cout << (dp[sum] == 1e9 ? -1 : dp[sum]) << '\n';
    dp[sum]==1e9? cout<<-1 : cout<<dp[sum];
 
}
