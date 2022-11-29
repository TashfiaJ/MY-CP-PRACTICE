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
ll n;
string s;
ll vis[1000005];
ll hash1[1000005],hash2[1000005],ans=1,level[1000005];

void dfs(ll i, vector<ll>edge[], ll n)
{
     vis[i]=true;
     for(ll x: edge[i])
     {
         if(!vis[x])
         {  
            level[x]=1+level[i];
            hash1[x]=hash1[i]+(pow(51,level[x]-1)*(s[x]-'A'+1));
            hash2[x]=(hash2[i]*51)+(s[x]-'A'+1);
            if(hash1[i]==hash2[i])ans++;
            dfs(x, edge, n);
         }
     }
}

void solve(int T)
{
    cin >> n >> s;
    s='9'+s;
    ans=1;
    vector<ll>edge[n+1];
    for(ll i=1;i<=n;i++)
    {
        vis[i]=false;
        hash1[i]=0;
        hash2[i]=0;
    }
    for(ll i=1;i<=n-1;i++)
    {
        ll a, b;
        cin >> a >> b;
        edge[a].pb(b);
        edge[b].pb(a);
    }
    level[1]=1;
    dfs(1,edge,n);
    ll g=__gcd(ans,n);
    cout<<"Case "<<T<<": "<<(ans/g)<<"/"<<(n/g)<<'\n';
}

int main()
{
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll T; T=1; 
    cin >> T;
    for(int i=1;i<=T;i++)
    {
        solve(i);
    }
}
