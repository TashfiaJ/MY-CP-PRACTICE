#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n,m,ans=0;
bool g[1005][1005];
ll dx[]={-1,1,0,0},dy[]={0,0,-1,1};

void dfs(ll x, ll y)
{
    g[x][y]=true;
    for(ll i=0;i<4;i++)
    {
        ll tempx=x+dx[i],tempy=y+dy[i];
        if(tempx>=0 && tempx<n && tempy>=0 && tempy<m && !g[tempx][tempy])
        {
            dfs(tempx, tempy);
        }

    }
}

int main()
{
    //freopen("cr.txt","r",stdin);
    cin >> n >> m;
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<m;j++)
            g[i][j]=false;
    }
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<m;j++)
        {
            char c; cin >> c;
            g[i][j]=(c=='#');
        }
    }
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<m;j++)
        {
            if(!g[i][j])
            {
                dfs(i,j);
                ans++;
            }
        }
    }
    cout << ans;
}
