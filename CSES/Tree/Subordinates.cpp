#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> pi;
#define mp make_pair
#define pb push_back
#define F first
#define S second
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int my_random(int l, int r)
{
    return uniform_int_distribution<int>(l, r) (rng);
}

ll  n;
vector<ll>g[200005];
ll sub[200005];
bool vis[200005];
void dfs(ll node)
{
    vis[node]=1;
    for(auto x: g[node])
    {
        if(!vis[x])
        {
            dfs(x);
            sub[node]+=(1+sub[x]);
        }
    }
}

void solve()
{
    cin>>n;
    for(ll i=2;i<=n;i++)
    {
        ll x;
        cin>>x;
        g[x].push_back(i);
    }
    dfs(1);
    for(ll i=1;i<=n;i++)cout<<sub[i]<<" ";
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
