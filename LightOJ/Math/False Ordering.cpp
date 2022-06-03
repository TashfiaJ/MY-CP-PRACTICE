#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second

bool cmp (pair <ll,ll> a, pair<ll,ll> b)
{
    if(a.f==b.f)return a.s>b.s;
    return a.f<b.f;
}

int main()
{
    vector<pair<ll,ll>>v(1001);
    for(ll i=1;i<=1000;i++)
    {
        v[i].f=0;
        v[i].s=i;
    }

    for(ll i=1;i<=1000;i++)
    {
        for(ll j=1;j*j<=i;j++)
        {
            if(j*j==i && i%j==0){v[i].f++;break;}
            if(i%j==0)v[i].f+=2;
        }
    }
    sort(v.begin(),v.end(), cmp);
    ll t, c=1;
    cin >> t;
    while(t--)
    {
        ll n; cin >> n;
        cout << "Case " << c++ << ": " << v[n].s << '\n';
    }   
}
