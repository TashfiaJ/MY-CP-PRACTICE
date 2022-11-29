#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
	int t;
	cin >> t;
	while(t--)
		{
			ll a1,b1,a2,b2;
			cin>>a1>>b1>>a2>>b2;
			cout<<(min(abs(a2-a1),16-abs(a2-a1)))+(min(abs(b2-b1),20-abs(b2-b1)))<<'\n';
		}
}
