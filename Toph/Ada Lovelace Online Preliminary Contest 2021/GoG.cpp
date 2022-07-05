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
		if((n*m)%2==0)cout <<"Bob\n";
		else
			cout << "Alice\n";
	}	
}
