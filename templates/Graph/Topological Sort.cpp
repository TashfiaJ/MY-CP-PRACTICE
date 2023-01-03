#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 1e5;
vector<ll>g[N];
bool vis[N];
stack<ll>stk;
ll n,e;
void dfs(ll node)
{
    vis[node]=true;
    for(auto x: g[node])
    {
        if(!vis[x])dfs(x);
    }
    stk.push(node);
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
    while(!stk.empty())
    {
        cout<<stk.top()<<" ";
        stk.pop();
    }
}
