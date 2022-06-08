#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 505;

const ll INF = 1e18;

int n,m;
ll grid[N][N];

int main()
{
	int q;
	cin >> n >> m >> q;
	
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1; j<=n;j++)
			grid[i][j]=INF;
		grid[i][i]=0;
	}
	for(ll i=0; i<m; i++)
	{
		ll a,b,c;
		cin >> a >> b >> c;
		grid[a][b]=min(grid[a][b], c);
		grid[b][a]=min(grid[b][a], c);
	}
	
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1; j<=n; j++)
		{
			for(ll k=1; k<=n; k++)
				grid[j][k]=min(grid[j][k], grid[j][i]+grid[i][k]);
		}
	}
	
	while(q--)
	{
		int a, b; cin >> a >> b;
		cout << ((grid[a][b]>=INF)? -1 : grid[a][b]) << '\n';
	}
	
		
}
