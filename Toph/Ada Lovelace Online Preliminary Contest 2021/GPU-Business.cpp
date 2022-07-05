#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 0;

int main()
{
	ll t;
	cin >> t;
	while(t--)
	{
		ll n, m;
		cin >> n >> m;
		ll a[n], b[m];
		for(ll i=0;i<n;i++)cin >> a[i];
		for(ll j=0;j<m;j++)cin >> b[j];
		sort(a,a+n);
		sort(b, b+m, greater<ll>());
		ll i=0, j=0, ans =0;
		while(i<n && j<m)
		{
			if(a[i]<b[j])
			{
				ans+=(b[j]-a[i]);
				i++;
				j++;
			}
			else if(a[i]>=b[j])
			{
				j++;
			}
		}
		cout << ans << '\n';
	}	
}
