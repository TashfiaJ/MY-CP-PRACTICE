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

ll n;
vector<ll>g[N];
queue<ll>q;
bool vis[N];
ll steps;
ll ans[N];


void dfs(ll node)
{
    q.push(node);
    if(vis[node])
    {
        steps+=ans[node];
        return;
    }
    vis[node]=true;
    steps++;
    for(auto x: g[node])
    {   
        dfs(x);
    }
}


void solve()
{
    cin >> n;
    for(ll i=1;i<=n;i++)
    {
        ll a;
        cin >> a;
        g[i].pb(a);
    }
    for(ll i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            steps=0;
            ll komabo=1;
            dfs(i);
            while(!q.empty())
            {
                if(q.front()==q.back())komabo=0;
                ans[q.front()]=steps;
                steps-=komabo;
                q.pop();
            }
        }
    }
    for(ll i=1;i<=n;i++)
    {
        cout << ans[i] << " ";
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
