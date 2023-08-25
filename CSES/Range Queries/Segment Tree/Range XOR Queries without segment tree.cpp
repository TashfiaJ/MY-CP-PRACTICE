#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> pi;
#define lll __int128_t
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define SetBit(x, k) (x |= (1LL << k))
#define ClearBit(x, k) (x &= ~(1LL << k))
#define CheckBit(x, k) (x & (1LL << k))
#define debug(x)       { cerr << #x << " = " << x << endl; }
const ll inf = 1LL<<60; //1.15e18
const ll md = 10000007;
const ll N = 1e6+5;

ll dx[]={0,1,0,-1};
ll dy[]={1,0,-1,0};
ll dxx[]={0,1,0,-1,1,1,-1,-1};
ll dyy[]={1,0,-1,0,1,-1,1,-1};

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int my_random(int l, int r)
{
    return uniform_int_distribution<int>(l, r) (rng);
}

void solve()
{   
    ll n, q;
    cin >> n >> q;
    ll a[n+1]={}, pre[n+1]={};
    for(ll i=1;i<=n;i++)cin>>a[i];
    for(ll i=1;i<=n;i++)pre[i]=pre[i-1]^a[i];
    while(q--)
    {
        ll a, b; cin >> a >> b;
        cout << (pre[b]^pre[a-1]) <<'\n';
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int T; T=1; 
    //cin >> T;
    while(T--)
    {   
        solve();
    }
    return 0;
}

