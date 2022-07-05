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
		ll q;
		cin >> q;
		while(q--)
		{
			ll x, d, n; cin >> x >> d >> n;
			
			cout << x+(d*(n-1)) << '\n';
		}
	}	
}
