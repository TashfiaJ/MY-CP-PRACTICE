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
ll dep[N];

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
    ll mx_dep=0, mx_node=-1;
    for(ll i=1;i<=n;i++)
    {
        if(mx_dep<dep[i])
        {
            mx_dep=dep[i];
            mx_node=i;
        }
        dep[i]=0;
    }
    dfs(mx_node);
    mx_dep=0, mx_node=-1;
    for(ll i=1;i<=n;i++)
    {
        if(mx_dep<dep[i])
        {
            mx_dep=dep[i];
            mx_node=i;
        }
    
    }
    cout << mx_dep;
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
