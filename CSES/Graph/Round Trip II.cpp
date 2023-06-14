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
vector<vector<ll>>g;
vector<bool>vis, onstack;
bool cycle=false;
stack<ll>s;

bool dfs(ll node)
{
    vis[node]=true;
    onstack[node]=true;
    s.push(node);
    for(auto x: g[node])
    {
        if(!vis[x])
        {
            if(dfs(x))
            return true;
        }
        else if(onstack[x])
        {
            cycle=true;
            s.push(x);
            return true;
        }
    }
    onstack[node]=false;
    s.pop();
    return false;
}

void solve()
{
    cin >> n >> m;
    g=vector<vector<ll>>(n+1, vector<ll>());
    vis=vector<bool>(n+1, false);
    onstack=vector<bool>(n+1, false);
    for(ll i=0;i<m;i++)
    {
        ll a, b;
        cin >> a >> b;
        g[a].pb(b);
    }
    for(ll i=1;i<=n;i++)
    {   
        
        if(!vis[i]){
        if(dfs(i))
            break;}
    }
    
    if(!cycle)cout<<"IMPOSSIBLE";
    else
    {   
        vector<ll>ans;
        ll temp=s.top();
        while(!s.empty())
        {
            ans.pb(s.top());
            s.pop();
            if(ans.back() == temp and ans.size() !=1)
                break;
        }
        reverse(ans.begin(), ans.end());
        cout << ans.size() << '\n';
        for(auto x: ans)cout << x << " ";
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
