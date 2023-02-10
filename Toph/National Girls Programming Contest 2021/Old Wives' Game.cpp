#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> pi;
#define mp make_pair
#define pb push_back
#define F first
#define S second
const ll m = 1e7+1;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int my_random(int l, int r)
{
    return uniform_int_distribution<int>(l, r) (rng);
}

ll binpow(ll a, ll b, ll m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
ll n;
ll g[m],mex[m];

void pre()
{
    g[0]=0;
    mex[0]=1;
    ll mx=1;
    set<ll>s;
    s.insert(0);
    for(ll i=1;i<m;i++)
    {   
        g[i]=mex[(i+1)/2 -1];
        s.insert(g[i]);
        while(s.count(mx))mx++;
        mex[i]=mx;
    }
}
void solve()
{
    
    cin>>n;
    ll a[n];
    ll res=0;
    for(ll i=0;i<n;i++){
    cin>>a[i];
    res^=g[a[i]];}
    if(res? cout<<"Mrinalini\n" : cout<<"Kadambari\n");
}

int main()
{
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    pre();
    int T; T=1; 
    cin >> T;
    for(int i=1;i<=T;i++)
    {   
        //cout<<"Case "<<i<<": ";
        solve();
    }
}
