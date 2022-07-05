#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 0;

int main()
{
	ll n; cin >> n;
	ll a[2*n];
	a[0]=pow(2,n)-1;
	ll k=1;
	for(ll i=0;i<n;i++)
	{	ll pos=0, temp=0;
		for(ll j=0;j<n;j++)
		{
			if(i!=j)temp+=pow(2,pos);
			pos++;
		}
		a[k]=temp;
		k++;
	}
	for(ll i=k;i<(2*n);i++)a[i]=1;
		for(ll i=0;i<(2*n);i++)cout<< a[i] << " ";
}
