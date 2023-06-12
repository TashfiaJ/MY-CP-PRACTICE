// Problem link: https://cses.fi/problemset/task/1757

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
vector<ll>g[N];
ll timee[N], out[N];

void solve()
{
    cin >> n >> m;
    for(ll i=0;i<m;i++)
    {
        ll a, b;
        cin >> a >> b;
        g[b].pb(a); // to decrease outdegree size I have taken reverse graph 
        out[a]++;
    }
    set<pair<ll,ll>>s;
    for(ll i=1;i<=n;i++)
    {
        s.insert({out[i], -i});
    }
    ll label=n;
    while(s.size())
    {
        auto x = *s.begin();
        ll i = -x.S;
        timee[i]=label--;
        s.erase(s.begin());
        for(ll v: g[i])
        {
            s.erase(s.find({out[v], -v}));
            out[v]--;
            s.insert({out[v], -v});
        }
    }
    ll ans[n+1];
    for(ll i=1;i<=n;i++)ans[timee[i]]=i;
    for(ll i=1;i<=n;i++)cout<<ans[i]<<" ";
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
