#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 0;

int main()
{
	ll n, a, b, c;
	set<ll>s;
	scanf("%lld %lld %lld %lld", &n, &a, &b, &c);
	ll ans =0;
	for(ll i=0;i<=a;i+=2)
	{
		for(ll j=0;j<=b;j++)
		{	
			ll temp = n-(i/2)-j;
			if(temp%2==0 && (temp/2)>=0 && (temp/2)<=c)
				ans++;	
			
		}
	}
	printf("%lld", ans);	
}
