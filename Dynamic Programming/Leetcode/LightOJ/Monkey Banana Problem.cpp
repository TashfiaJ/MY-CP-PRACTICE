#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll a[300][300], dp[300][300];
int N;

ll monkey(int i, int j)
{
    if(i==1 && j==1)return dp[i][j]=a[1][1];
    if(dp[i][j]!=-1)return dp[i][j];
    if(i<=N)
    {   
        if(j<=i-1){
        ll left = monkey(i-1, j)+a[i][j];
        dp[i][j]=left;}
        if(j-1<=i-1){
        ll right  = monkey(i-1, j-1)+a[i][j];
        dp[i][j]=max(dp[i][j], right);
        }
        return dp[i][j];
    }
    else
    {
        ll left = monkey(i-1, j)+a[i][j];
        dp[i][j]=left;
        int baki=i-1-N;
        int ache=N-baki;
        if(j+1<=ache || i-1==N){
        ll right  = monkey(i-1, j+1)+a[i][j];
        dp[i][j]=max(left, right);
        }
        return dp[i][j];
    }
     
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int t=1;t<=T;t++)
    {
        scanf("%d", &N);
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=i;j++)
            {
                scanf("%lld", &a[i][j]);
            }
        }
        for(int i=N-1, c=1;i>=1;i--,c++)
        {
            for(int j=1;j<=i;j++)
            {
                scanf("%lld", &a[N+c][j]);
            }
        }
        for(int i=1;i<(2*N);i++)
        {
            for(int j=1;j<=i;j++)
                dp[i][j]=-1;
        }
        printf("Case %d: %lld\n", t,monkey(2*N-1, 1));
    }
}
