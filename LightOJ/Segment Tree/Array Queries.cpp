#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct segtree{
    ll k;
    vector<ll>v;
    segtree(ll n)
    {
        k=1;
        while(k<n)k*=2;
        k*=2;
        v.resize(k,1e18);
    }
    void update(ll ind, ll x)
    {
        ind+=(k/2);
        v[ind]=x;
        ind/=2;
        while(ind)
        {
            v[ind]=min(v[2*ind],v[2*ind+1]);
            ind/=2;
        }
    }
    ll mn(ll in_l, ll in_r, ll nd, ll a, ll b)
    {
        if(in_l>b || in_r<a)return 1e18;
        if(in_l<=a && in_r>=b)return v[nd];
        ll mid=(a+b)/2;
        return min(mn(in_l, in_r,2*nd,a,mid), mn(in_l,in_r,2*nd+1,mid+1,b));
    }
    ll mn(ll in_l, ll in_r)
    {
        return mn(in_l, in_r, 1, 0, (k/2)-1);
    }
};

void solve()
{
    ll n, q;
    cin >> n >> q;
    segtree seg(n);
    for(ll i=0;i<n;i++)
    {
        ll x; cin >> x;
        seg.update(i,x);    
    }
    while(q--)
    {
        ll l, r; cin >> l >> r;
        l--, r--;
        cout<<seg.mn(l,r)<<'\n';
    }
}

int main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t; cin >> t;
    for(int i=1;i<=t;i++)
    {
        cout<<"Case "<<i<<":\n";
        solve();
    }
}
