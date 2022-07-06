#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll divisor(ll m, ll temp, ll x)
{
    vector<ll>v;
    ll ans=LLONG_MAX, i;
    for(i=1;i*i<temp;i++)
    {
        if(temp%i==0)
        {
            if(i>x)
            v.push_back(i);
            if((temp/i)>x)
            v.push_back(temp/i);
        }
    }
    if(i*i==temp){if(i>x)v.push_back(i);}
    sort(v.begin(), v.end());
    for(ll i=0;i<v.size();i++)
    {
        for(ll j=i;j<v.size();j++)
        {
            if((v[i]*v[j])>=m)
            {
                ans = min(ans, v[i]*v[j]);
                break;
            }
        }

        }
    if(ans==LLONG_MAX)ans=-1;
    return ans;
}

int main()
{
  ll t;
  cin >> t;
  while(t--)
  {
      ll m, x;
      cin >> m >> x;
      ll temp = m-x;
      cout << divisor(m, temp, x) << '\n';
  }
}
