#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 0;

int main()
{
	ll n, m;
	cin >> n >> m;
	ll a[n];
	ll p[m];
	ll s[m];
	for(ll i=0;i<m;i++)cin >> p[i];
	for(ll i=0;i<m;i++)cin >> s[i];
	for(ll i=0;i<n;i++)cin >> a[i];
	for(ll i=1;i<n;i++)a[i]=a[i-1]+a[i];
	ll ans = a[n-1]-(p[0]*n)-s[0];
	for(ll i=1;i<m;i++)
	{
		ans  = max(ans, a[n-1]-(p[i]*n)-s[i]);
	}	
	if(ans>0)cout << "Profit " << ans;
	else if(ans<0)cout<<"Loss " << abs(ans);
	else cout << "Neutral";
}
