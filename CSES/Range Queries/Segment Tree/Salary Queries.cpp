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
    vector<ll>v;
    segtree(ll n)
    {
        k=1;
        while(k<n)k*=2;
        k*=2;
        v.resize(k,0);
    }
    void update(ll ind, ll x)
    {
        ind+=k/2;
        v[ind]+=x;
        ind/=2;
        while(ind)
        {
            v[ind]=v[2*ind]+v[2*ind+1];
            ind/=2;
        }
    }
    ll sum(ll in_l, ll in_r, ll nd, ll a, ll b)
    {
        if(in_l>b || in_r<a)return 0;
        if(in_l<=a && in_r>=b)return v[nd];
        ll mid=(a+b)/2;
        return sum(in_l, in_r, 2*nd, a, mid) + sum(in_l, in_r, 2*nd+1, mid+1, b);
    }
    ll sum(ll in_l, ll in_r)
    {
        return sum(in_l, in_r, 1, 0, (k/2)-1);
    }
};

void solve()
{
    ll n, q;
    cin >> n >> q;
    vector<ll> arr(n+1);
    vector<array<ll,3>>quer;
    vector<ll>poi;
    for(ll i=1;i<=n;i++)
    {
        cin >> arr[i];
        poi.push_back(arr[i]);
    }
    for(ll i=1;i<=q;i++)
    {
        char t; ll a, b;
        cin >> t >> a >> b;
        quer.push_back({t=='?',a,b});
        if(t=='!')poi.push_back(b);
    }
    sort(poi.begin(), poi.end());
    poi.erase(unique(poi.begin(), poi.end()),poi.end());
    ll sz = poi.size();
    segtree seg(sz);
    for(ll i=1;i<=n;i++)
    {
        seg.update(lower_bound(poi.begin(),poi.end(),arr[i])-poi.begin(),1);
    }
    for(ll i=0;i<q;i++)
    {
        if(quer[i][0]==0)
        {
            seg.update(lower_bound(poi.begin(),poi.end(),arr[quer[i][1]])-poi.begin(),-1);
            arr[quer[i][1]]=quer[i][2];
            seg.update(lower_bound(poi.begin(),poi.end(),arr[quer[i][1]])-poi.begin(),1);
        }
        else
        {
            ll in_l = upper_bound(poi.begin(), poi.end(),quer[i][1])-poi.begin();
            ll in_r = upper_bound(poi.begin(), poi.end(),quer[i][2])-poi.begin();
            if(in_r>0)in_r--;
            if(in_l>0 && poi[in_l-1]==quer[i][1])in_l--;
            cout<<seg.sum(in_l,in_r)<<'\n';
        }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll T; T=1; 
    //cin >> T;
    while(T--)
    {
        solve();
    }
}
