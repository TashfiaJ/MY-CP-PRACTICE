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
        k*=2;      //2^0 + 2^1 + 2^2 + 2^3 + ...... + 2^k = 2^(k+1) -1
        v.resize(k,0);
    }
    void update(ll ind, ll x)
    {
        ind+=k/2;
        v[ind]=x;
        ind/=2;
        while(ind)
        {
            v[ind]=v[2*ind]+v[2*ind+1];
            ind/=2;
        }
    }
    ll sum(ll in_l, ll in_r, ll nd, ll a, ll b) // nd->which node in segment tree, (a,b)->range covered in nd
    {
        if(in_l>b || in_r<a)return 0;
        if(in_l<=a && in_r>=b)return v[nd];
        ll mid=(a+b)/2;
        return sum(in_l,in_r,2*nd,a,mid) + sum(in_l, in_r, 2*nd+1, mid+1, b);
    }
    ll sum(ll in_l, ll in_r)
    {
        return sum(in_l, in_r, 1, 0, (k/2)-1);
    }
};

int main()
{
    ll n, q;
    cin >> n >> q;
    segtree seg(n);
    for(ll i=0;i<n;i++)
    {
        ll x; cin >> x; seg.update(i,x);
    }
    while(q--)
    {
        ll type; cin >> type;
        if(type==1)
        {
            ll ind, x; cin >> ind >> x;
            ind--;
            seg.update(ind,x);
        }
        else
        {
            ll l, r; cin >> l >> r;
            l--;
            r--;
            cout<<seg.sum(l,r)<<'\n';
        }
    }
}
