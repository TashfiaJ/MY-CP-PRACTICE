// https://www.codechef.com/COOK39/problems/PPXOR

#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

int main() {
	int t; cin >> t;
	while(t--)
	{
        ll n; cin >> n;
        vector<ll>a(n+1);
        a[0]=0;
        for(ll i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        ll bits[31][n+1];
        memset(bits,0, sizeof bits);
        for(ll i=0;i<31;i++)
        {
            for(ll j=1;j<=n;j++)
                bits[i][j]=(bits[i][j-1]+((a[j]&(1ll<<i))!=0))%2;
        }
        
        ll ans=0;
        for(ll mask=0;mask<31;mask++)
        {
            ll odd=0, even=0,total=0;
            for(ll j=n;j>=0;j--)
            {
                if(bits[mask][j]==0)
                {
                    even++;
                    total+=(odd);
                }
                else
                {
                    odd++;
                    total+=even;
                }
            }
            //<<total<<" ";
            ans+=(total*(1ll<<mask));
        }
        cout<<ans<<'\n';
	}
}
