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
const ll N = 2e5+5;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int my_random(int l, int r)
{
    return uniform_int_distribution<int>(l, r) (rng);
}
ll n;
vector<ll>g[N];
ll dep[N], dis[N];

void dfs(ll i, ll par=-1)
{
    for(auto x: g[i])
    {
        if(x!=par)
        {   
            dep[x]=1+dep[i];
            dfs(x, i);
        }
    }
}

void solve()
{
    cin >> n;
    for(ll i=1;i<n;i++)
    {
        ll a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs(1);
    ll mx_dep=0, mx_node1=-1;
    for(ll i=1;i<=n;i++)
    {
        if(mx_dep<dep[i])
        {
            mx_dep=dep[i];
            mx_node1=i;
        }
        dep[i]=0;
    }
    dfs(mx_node1);
    mx_dep=0;
    ll mx_node2=-1;
    for(ll i=1;i<=n;i++)
    {
        if(mx_dep<dep[i])
        {
            mx_dep=dep[i];
            mx_node2=i;
        }
        dep[i]=0;
    }
    // 2ta leaf node peye gesi
    dfs(mx_node1);
    for(ll i=1;i<=n;i++)
    {
        dis[i]=dep[i];
        dep[i]=0;
    }
    dfs(mx_node2);
    for(ll i=1;i<=n;i++)
    {
        cout << max(dep[i],dis[i]) << " ";
    }

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
