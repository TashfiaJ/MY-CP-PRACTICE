#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll sieve[1000005], a[1000005], m;

void pre()
{
    for(ll i=0;i<m;i++)sieve[a[i]]++;
    for(ll i=1000004;i>0;i--)
    {
        if(sieve[i])
        {
            ll temp = sieve[i];
            for(ll j=2*i;j<1000005;j+=i)
            {
               sieve[j]+=temp;
            }
        }
    }
}

int main()
{
   cin >> m;
   for(ll i=0;i<m;i++)cin >> a[i];
   pre();
   ll q, c;
   cin >> q;
   while(q--)
   {
       cin >> c;
       cout << m-sieve[c] << '\n';
   }
}
