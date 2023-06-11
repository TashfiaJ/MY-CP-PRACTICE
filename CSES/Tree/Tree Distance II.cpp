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
ll subtreeSize[N], subdisSum[N];
ll ans[N];

void dfs1(ll i, ll par=0)
{   
    subtreeSize[i]=1;
    for(auto x: g[i])
    {
        if(x!=par)
        {   
            dfs1(x, i);
            subtreeSize[i] += subtreeSize[x];
            subdisSum[i] += subdisSum[x]+subtreeSize[x];
        }
    }
}

void dfs2(ll i, ll par=0)
{   
   ll parentRootSubtreeContribution = (ans[par]-(subtreeSize[i]+subdisSum[i])) + (n-subtreeSize[i]);
   ans[i]=parentRootSubtreeContribution+subdisSum[i];
   //cout << i << ": " << parentRootSubtreeContribution << " " << ans[i] << '\n';
   for(auto x: g[i])
    {
        if(x!=par)
        {   
            dfs2(x, i);
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
    dfs1(1);
    ans[1]=subdisSum[1];
    for(auto x: g[1])dfs2(x,1);
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
