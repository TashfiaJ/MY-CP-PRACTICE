#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 1e5;
vector<ll>g[N];
ll vis[N];
stack<ll>stk;
bool cycle=false;
ll n,e;
void dfs(ll node)
{
    vis[node]=1;
    for(auto x: g[node])
    {
        if(vis[x]==0)
        {
            dfs(x);
        }
        else if(vis[x]==1)
        {
            cycle=true;
            return;
        }
        else continue;
    }
    stk.push(node);
    vis[node]=2;
}
int main()
{
    cin>>n>>e;
    for(ll i=1;i<=e;i++)
    {   
        ll a, b;
        cin>>a>>b;
        g[a].push_back(b);
    }
    for(ll i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            dfs(i);
        }
    }
    if(cycle)
    {
        cout << "IMPOSSIBLE";
        return;
    }
    else
    {
        while(!stk.empty())
        {
            cout << stk.top() << " ";
            stk.pop();
        }
    }
}
