#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll N = 1e9+7;

ll power(ll base, ll p)
{
    ll result = 1;
    while(p)
    {
        if(p%2)result=(result*base)%N;
        base=(base*base)%N;
        p/=2;
    }
    return result;
}

int main()
{
  ll t;
  cin >> t;
  while(t--)
  {
        ll n;
        cin >> n;
        vector<ll>v, a;
        map<ll,ll>mp;
        ll c;
        for(ll i=0;i<n;i++)
        {
            cin >> c;
            mp[c]++;

        }
        ll ans = 0;
        for(auto &i: mp)
        {
            i.second=power(2, i.second)-1;
            ans+=i.second;
            ans%=N;
            v.push_back(i.second);
            a.push_back(ans);
        }

        for(ll i=0;i<v.size()-1;i++)
        {
            ll temp = a.back()-a[i];
            temp%=N;
            temp+=N;
            temp%=N;
            ans+=(((v[i])*temp)%N);
            ans%=N;
        }
        cout << ans << '\n';
  }
}
