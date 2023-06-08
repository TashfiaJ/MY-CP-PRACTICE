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
const ll INF = 1LL<<60; //1.15e18
const ll md = 1000000007;
const ll N = 2e5+5;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int my_random(int l, int r)
{
    return uniform_int_distribution<int>(l, r) (rng);
}

ll n, m;
vector<ll>g[N];
stack<ll>stk;
ll vis[N];
bool cycle=false;

bool is_possible(ll x, ll y)
{
    return (x<n && x>=0 && y<m && y>=0 && g[x][y]!='#');
}

bool is_boundary(ll x, ll y)
{
    return (x==0 || x==n-1 || y==0 || y==m-1);
}


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


void solve()
{
    cin >> n >> m;
    for(ll i=0;i<m;i++)
    {
        ll a, b;
        cin >> a >> b;
        g[a].pb(b);
    }
    for(ll i=1;i<=n;i++)
    {
        if(!vis[i])dfs(i);
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
