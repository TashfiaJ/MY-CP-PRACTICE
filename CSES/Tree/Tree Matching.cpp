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
const ll N = 2e5+5;
ll n;
vector<ll>g[N];
ll dp[N][2];

ll matching(ll vertex, bool isIncluded, ll par)
{
    if(dp[vertex][isIncluded]!=-1)return dp[vertex][isIncluded];
    if(!isIncluded)
    {
        ll ans=0;
        for(ll x: g[vertex])
        {
            if(x!=par)
            {
                ll notincluded=matching(x, 0, vertex);
                ll included=matching(x, 1, vertex);
                ans+=max(notincluded, included);
            }
        }
        return dp[vertex][isIncluded]=ans;
    }
    else
    {
        ll ans=0;
        for(ll x: g[vertex])
        {
            if(x!=par)
            {
                ans+=matching(x, 1, vertex);
            }
        }
        ll myres=0;
        for(ll x: g[vertex])
        {
            if(x!=par)
            {
                myres=max(myres, ans-dp[x][1]+1+matching(x, 0, vertex));
            }
        }
        return dp[vertex][isIncluded]=myres;
    }
}

void solve()
{   
    memset(dp, -1, sizeof(dp));
    cin>>n;
    for(ll i=1;i<=n-1;i++)
    {
        ll x, y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    cout << max(matching(1, 0, -1), matching(1, 1, -1))<<" ";
    
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
