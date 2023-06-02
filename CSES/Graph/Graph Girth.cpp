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
const ll N = 2e4+5;
const ll INF = 1<<20;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int my_random(int l, int r)
{
    return uniform_int_distribution<int>(l, r) (rng);
}
ll n, m;
vector<ll>g[N];

ll bfs(ll x)
{
    ll ans = INF;
    vector<ll>dis(N, -1);
    queue<ll>q;

    q.push(x);
    dis[x]=0;

    while(!q.empty())
    {
        ll k = q.front();
        q.pop();
        for(auto i: g[k])
        {
            if(dis[i]==-1)
            {
                dis[i]=dis[k]+1;
                q.push(i);
            }
            else if(dis[i]>=dis[k])
            {
                ans = min(ans, 1+dis[i]+dis[k]);
            }
        }
    }
    return ans;
}

void solve()
{
    cin >> n >> m;
    for(ll i=1;i<=m;i++)
    {
        ll a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    ll ans = INF;
    for(ll i=1;i<=n;i++)
    {
        ans = min ( ans, bfs(i));
        
    }
    if(ans==INF)cout << -1;
    else cout << ans;
    
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

