#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
 
vector<pair<ll,ll>>g[100005];
bool vis[100005];
ll dis[100005];
 
 
void dijkstra(int src){
    set<pair<ll,ll>>se;
    se.insert({0,src});
    dis[src]=0;
 
    while(se.size()>0)
    {
        auto node = *se.begin();
        ll node_wt=node.f;
        ll node_v=node.s;
        se.erase(node);
        if(vis[node_v])continue;
        for(auto x: g[node_v])
        {
            if(x.s+dis[node_v]<dis[x.f]){
                dis[x.f]=dis[node_v]+x.s;
                se.insert({dis[x.f],x.f});
            }
        }
        vis[node_v]=true;
    }
    }
 
int main()
{
    ll n,m;
    cin>>n>>m;
    for(ll i=0;i<m;i++)
    {
        ll a,b,w;
        cin>>a>>b>>w;
        g[a].push_back({b,w});
    }
 
    for(ll i=1;i<=n; i++)
    {
        dis[i]=LONG_MAX;
    }
    dijkstra(1);
 
    for(ll i=1;i<=n;i++){
        cout<<dis[i]<<" ";
    }
}
