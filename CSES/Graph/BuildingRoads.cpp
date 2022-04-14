#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll>g[100005];
bool vis[100005];

void dfs(ll i)
{
    vis[i]=true;
     for(ll x: g[i])
     {
         if(!vis[x])
            dfs(x);
     }
}

int main()
{
    ll n,m; cin >> n >> m;
    for(ll i=0;i<m;i++)
    {
        ll a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    ll ans = 0;
    vector<pair<ll,ll>>ans2;
    for(ll i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            dfs(i);
            ans++;
            if(ans>1)
            {
                ans2.push_back({i,i-1});
            }
        }
    }
    ans--;
    cout<< ans << endl;
    for(auto x: ans2){
        cout << x.first << " " << x.second << endl;
    }
}
