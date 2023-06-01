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
ll n, m;
vector<ll>g[N][2];
bool vis[N];

void dfs(ll x, ll y)
{
    vis[x]=true;
    for(auto i: g[x][y])
    {
        if(!vis[i])dfs(i,y);
    }
}

void solve()
{
    cin >> n >> m;
    for(ll i=0;i<m;i++)
    {
        ll a, b;
        cin >> a >> b;
        g[a][0].pb(b);
        g[b][1].pb(a);
    }
    
    dfs(1,0);

    for(ll i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            cout << "NO\n" << 1 << " " << i << '\n';
            return;
        }
    }
    memset(vis, false, sizeof(vis));
    dfs(1,1);
    for(ll i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            cout << "NO\n" << i << " " << 1 << '\n';
            return;
        }
    }
    cout << "YES\n";
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
