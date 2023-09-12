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
const ll inf = 1e18;
const ll md = 1000000007;
const ll N = 2e5+5;

ll dx[]={0,1,0,-1};
ll dy[]={1,0,-1,0};
ll dxx[]={0,1,0,-1,1,1,-1,-1};
ll dyy[]={1,0,-1,0,1,-1,1,-1};

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int my_random(int l, int r)
{
    return uniform_int_distribution<int>(l, r) (rng);
}

struct segtree
{
    ll k;
    vector<ll>mn,mx;
    segtree(ll n)
    {
        k=1;
        while(k<n)k*=2;
        k*=2;
        mn.resize(k,inf);
        mx.resize(k,0);
    }
    void update(ll ind, ll x)
    {
        ind+=k/2;
        mn[ind]=mx[ind]=x;
        ind/=2;
        while(ind)
        {
            mn[ind]=min(mn[ind*2],mn[2*ind+1]);
            mx[ind]=max(mx[ind*2],mx[ind*2+1]);
            ind/=2;
        }
    }
    ll mnn(ll in_l, ll in_r, ll nd, ll a, ll b)
    {
        if(in_l>b || in_r<a)return inf;
        if(a>=in_l && b<=in_r)return mn[nd];
        ll mid=(a+b)/2;
        return min(mnn(in_l, in_r, 2*nd, a, mid), mnn(in_l, in_r, 2*nd+1, mid+1, b));
    }
    ll mxx(ll in_l, ll in_r, ll nd, ll a, ll b)
    {
        if(in_l>b || in_r<a)return 0;
        if(a>=in_l && b<=in_r)return mx[nd];
        ll mid=(a+b)/2;
        return max(mxx(in_l, in_r, 2*nd, a, mid), mxx(in_l, in_r, 2*nd+1, mid+1, b));
    }

    ll f(ll in_l, ll in_r)
    {
        return mxx(in_l, in_r, 1, 0, (k/2)-1)-mnn(in_l, in_r, 1, 0, (k/2)-1);
    }
};

void solve()
{
    ll n, d; cin >> n >> d;
    segtree seg(n);
    for(ll i=0;i<n;i++)
    {
        ll x; cin >> x;
        seg.update(i,x);
    }
    ll ans=0;
    for(ll i=0;i<=(n-d);i++)
    {
        ans = max(ans, seg.f(i,i+d-1));
    }
    cout<<ans<<'\n';
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll T; T=1; 
    cin >> T;
    for(ll i=1;i<=T;i++)
    {   
        cout<<"Case "<<i<<": ";
        solve();
    }
}
