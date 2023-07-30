// link: https://www.geeksforgeeks.org/index-of-kth-set-bit-in-a-binary-array-with-update-queries/

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
        v.resize(k,0);
    }
    void update(ll ind, ll x)
    {
        ind+=(k/2);
        v[ind]=x;
        ind/=2;
        while(ind)
        {
            v[ind]=(v[2*ind]+v[2*ind+1]);
            ind/=2;
        }
    }
    ll sum(ll in_k, ll nd, ll a, ll b)
    {
        if(a==b)return b;
        ll left = 2*nd;
        ll right = 2*nd + 1;
        ll mid = (a+b)/2;
        if(v[left]>=in_k) return sum(in_k, left, a, mid);
        else return sum(in_k-v[left], right, mid+1, b);
    }
    ll sum(ll in_k)
    {
        return sum(in_k, 1, 0, (k/2)-1);
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
        ll type; cin >> type;
        if(type==1)
        {
            ll ind, x; cin >> ind >> x;
            ind--;
            seg.update(ind,x);
        }
        else 
        {
            ll k; cin >> k;
            cout << seg.sum(k)<<'\n';
        }
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
