#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long

template <class T>
using Tree =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

Tree<pair<ll,ll>>o;

int main()
{
    ll n, q; cin >> n >> q;
    ll a[n+1];
    for(ll i=1;i<=n;i++)
    {
        cin >> a[i];
        o.insert({a[i],i});
    }
    while(q--)
    {
        char ch; cin >> ch;
        if(ch=='!')
        {
            ll k, x; cin >> k >> x;
            o.erase({a[k], k});
            a[k]=x;
            o.insert({a[k], k});
        }
        else
        {
            ll l, r;
            cin >> l >> r;
            cout << o.order_of_key({r,1000000007})-o.order_of_key({l-1,1000000007})<<'\n';
        }
    }
}
