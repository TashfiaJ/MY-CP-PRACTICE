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
const ll N = 5e4+5;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int my_random(int l, int r)
{
    return uniform_int_distribution<int>(l, r) (rng);
}

ll n, k;
vector<vector<ll>>g;
ll dep1[N][501], dep2[N][501], cnt[N];
bool vis[N];
ll ans=0;

// subtree te k distance e koyta node ache
void dfs1(ll node, ll par)
{   
    dep1[node][0]=1;
    vis[node]=1;
    for(auto x: g[node])
    {
        if(!vis[x] && x!=par)
        {   
            dfs1(x,node);
        }
    }
    for(ll dis=1;dis<=k;dis++)
    {
        for(auto x: g[node])
        {
            if(x!=par)
            {
                dep1[node][dis]+=dep1[x][dis-1];
            }
        }
    }
}

// number of nodes having k distance within subtree and not 
void dfs2(ll node, ll par)
{   
    // first insert all subtree node
    for(ll dis=0;dis<=k;dis++)
    {
        dep2[node][dis]=dep1[node][dis];
    }
    if(par!=0)
    {   
        //add parent node
        dep2[node][1]++;

        for(ll dis=2;dis<=k;dis++)
        {
            dep2[node][dis]+=dep2[par][dis-1];
            dep2[node][dis]-=dep1[node][dis-2];
        }
    }

    for(auto x: g[node])
    {
        if(x!=par)
        {
            dfs2(x, node);
        }
    }
}

void solve()
{
    cin >> n >> k;
    g=vector<vector<ll>>(n+1, vector<ll>());
    for(ll i=1;i<n;i++)
    {
        ll a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs1(1,0);
    // for(ll i=1;i<=n;i++)
    // {
    //     cout << "node " << i << ": " <<  dep1[i][k] <<'\n'; 
    // }
    dfs2(1,0);
    for(ll i=1;i<=n;i++)
    {
        ans+=dep2[i][k];
    }
    ans/=2;
    cout<<ans;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll T; T=1; 
    //cin >> T;
    while(T--)
    {
        solve();
        
    }
}
