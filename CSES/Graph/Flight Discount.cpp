#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> pi;
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define SetBit(x, k) (x |= (1LL << k))
#define ClearBit(x, k) (x &= ~(1LL << k))
#define CheckBit(x, k) (x & (1LL << k))
const ll inf = 1LL<<60; //1.15e18
const ll mod = 1000000007;
const ll N = 2e5+5;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int my_random(int l, int r)
{
    return uniform_int_distribution<int>(l, r) (rng);
}

ll n, m;
bool vis[N];

vector<ll> dijkstra(ll X, vector<vector<pi>>& g)
{
    vector<ll>dis(n+1, inf);
    set<pi>s;
    s.insert({0,X});
    dis[X]=0;
    while(!s.empty())
    {
        auto x = *s.begin();
        ll node = x.S;
        ll we = x.F;
        s.erase(s.begin());
        if(vis[node])continue;
        vis[node]=1;
        for(auto z: g[node])
        {
            ll adj_node = z.F, adj_we = z.S;
            if(dis[adj_node]>we+adj_we)
            {
                dis[adj_node]=we+adj_we;
                s.insert({dis[adj_node], adj_node});
            }
        }
    }
    return dis;
}


void solve()
{   
    cin >> n >> m;
    vector<vector<pi>>g(n+1, vector<pi>());
    vector<vector<pi>>re_g(n+1, vector<pi>());
    for(ll i=0;i<m;i++)
    {
        ll a, b, we;
        cin >> a >> b >> we;
        g[a].pb({b,we});
        re_g[b].pb({a,we});
    
    }
    vector<ll>dis1(n+1), dis2(n+1);
    dis1=dijkstra(1,g);
    memset(vis, false, sizeof(vis));
    dis2=dijkstra(n, re_g);
    ll ans=inf;
    for(ll i=1;i<=n;i++)
    {
        for(auto x: g[i])
        {
            ans = min(ans, dis1[i]+(x.S/2)+dis2[x.F]);
        }
    }
    cout << ans;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll T; T=1; 
    //cin >> T;
    while(T--)
    {
        solve();
    }
}
