#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lll __int128_t
#define pb push_back
#define F first
#define S second
#define SetBit(x, k) (x |= (1LL << k))
#define ClearBit(x, k) (x &= ~(1LL << k))
#define CheckBit(x, k) (x & (1LL << k))
#define debug(x)       { cerr << #x << " = " << x << endl; }
double pi = 2*acos(0.0);
const ll inf = 1e18;

struct segtree{
    ll k;
    vector<ll>v;
    segtree(ll n)
    {
        k=1;
        while(k<n)k*=2;
        k*=2;
        v.resize(k,0);
    }
    void update(ll in, ll x)
    {
        in+=k/2;
        v[in]=x;
        in/=2;
        while(in)
        {
            v[in]=max(v[in*2],v[in*2+1]);
            in/=2;
        }
    }
    ll f(ll in_l, ll ind, ll a, ll b)
    {   
        if(in_l>v[ind])return -1;
        if(a==b)
        {
            return a;
        }
        ll mid = (a+b)/2;
        if(v[2*ind]>=in_l)return f(in_l,2*ind, a, mid);
        else return f(in_l, 2*ind+1, mid+1, b);
    }
    ll f(ll in_l)
    {
        return f(in_l, 1, 0, (k/2)-1);
    }
    
};

void solve()
{   
    ll n, q; cin >> n >> q;
    segtree seg(n);
    for(ll i=0;i<n;i++)
    {
        ll x; cin >> x;
        seg.update(i,x);
    }
    while (q--)
    {    
        ll l; cin >> l;
        ll ind = seg.f(l);
        if(ind!=-1)
        seg.update(ind,seg.v[ind+seg.k/2]-l);
        cout << ind+1 << " ";
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
    for(int i=1;i<=T;i++)
    {
        solve();
    }
}
