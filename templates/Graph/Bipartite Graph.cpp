// problem link:  https://codeforces.com/problemset/problem/862/B

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
bool vis[N];
ll color[N];
vector<ll>red;

void bfs(ll node)
{
    vis[node]=true;
    queue<ll>q;
    q.push(node);
    red.pb(node);
    color[node]=1;
    while(!q.empty())
    {
        ll x = q.front();
        q.pop();
        for(auto z: g[x])
        {
            if(!vis[z])
            {
                color[z]=color[x]^1;
                vis[z]=true;
                q.push(z);
                if(color[z])red.pb(z);
            }
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
    bfs(1);
    ll total = red.size()*(n-red.size());
    cout << total - n + 1 ;
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
