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
const ll N = 3e5+5;
ll n;
vector<ll>g[N];
ll depth[N];

void dfs(ll node, ll par=-1)
{
    for(auto x: g[node])
    {
        if(x!=par)
        {   
            depth[x]=1+depth[node];
            dfs(x, node);
        }
    }
}

void solve()
{   
    cin>>n;
    if(n==1)
    {
        cout<<0;
        return;
    }
    for(ll i=1;i<=n-1;i++)
    {
        ll x, y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1);
    ll mx_d=0,mx_n=-1;
    for(ll i=1;i<=n;i++)
    {
        if(depth[i]>mx_d)
        {
            mx_d=depth[i];
            mx_n=i;
        }
        depth[i]=0;
    }
    dfs(mx_n);
    mx_d=0;
    for(ll i=1;i<=n;i++)
    {
        if(depth[i]>mx_d)
        {
            mx_d=depth[i];
        }
    }
    cout<<mx_d;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int T; T=1; 
    //cin >> T;
    for(int i=1;i<=T;i++)
    {   
        //cout<<"Case "<<i<<": ";
        solve();
    }
}
