#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> pi;
#define mp make_pair
#define pb push_back
#define F first
#define S second
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int my_random(int l, int r)
{
    return uniform_int_distribution<int>(l, r) (rng);
}
const ll N = 1e5+5;
vector<pair<ll,ll>>g[N];
ll dis[N], par[N];
bool vis[N];
void dijkstra(ll node)
{
    for(ll i=0;i<=N;i++)dis[i]=-1;
    dis[node]=0;
    set<pair<ll,ll>>st;
    st.insert({0,node});
    while(st.size())
    {
        auto nd=*st.begin();
        ll wt=nd.first;
        ll v=nd.second;
        st.erase(st.begin());
        if(vis[v])continue;
        vis[v]=1;
        for(auto x: g[v])
        {
            ll adj_nd=x.first;
            ll adj_wt=x.second;
            if(dis[adj_nd]>dis[v]+adj_wt || dis[adj_nd]==-1)
            {
                dis[adj_nd]=dis[v]+adj_wt;
                st.insert({dis[adj_nd], adj_nd});
                par[adj_nd]=v;
            }
        }
    }
}
vector<ll> path(ll node)
{   
    vector<ll>shortest_path;
    while(par[node]!=0)
    {
        shortest_path.push_back(node);
        node=par[node];
    }
    shortest_path.push_back(node);
    reverse(shortest_path.begin(), shortest_path.end());
    return shortest_path;
}
void solve()
{
    ll n, m;
    cin >> n  >> m;
    for(ll i=0;i<m;i++)
    {
        ll x, y, z;
        cin>>x>>y>>z;
        g[x].push_back({y,z});
        g[y].push_back({x,z});
    }
    dijkstra(1);
    if(dis[n]==-1)cout<<-1;
    else{
    vector<ll>ans=path(n);
    for(ll i=0;i<ans.size();i++)cout<<ans[i]<<" ";}
}

int main()
{
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int T; T=1; 
    //cin >> T;
    for(int i=1;i<=T;i++)
    {   
        //cout<<"Case "<<i<<": ";
        solve();
    }
}
