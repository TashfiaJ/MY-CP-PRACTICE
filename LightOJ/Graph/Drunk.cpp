//cycle detect in a directed graph using dfs

#include<bits/stdc++.h>
using namespace std;
#define ll long long

unordered_map<string, vector<string>>adj;
unordered_map<string, ll> vis;

bool dfsCyc(string x)
{
	vis[x]=1; //gray
	for(auto y: adj[x])
	{
		if(vis[y]==1)
		{
			return true;
		}
		if(vis[y]==0 && dfsCyc( y))
		{
			return true;
		}
		
	}
	vis[x]=2; //black
	return false;
}


int main()
{
	ll t, tc=0; cin >> t;
	while(t--)
	{
		ll n; cin >> n;
		adj.clear();
        vis.clear();
		while(n--)
		{
			string a, b;
			cin >> a >> b;
			adj[a].push_back(b);
            vis[a]=0; //white
            vis[b]=0;
		}
		bool ans=true;
		
		
		cout << "Case " << ++tc <<": ";
		for(auto x: vis)
		{
			if(x.second==0){			
				ans=dfsCyc(x.first);
                if(ans){
                cout<<"No\n"; break;}
			}
		}
	
		if(!ans)cout<<"Yes\n";
		
		
	}	
}
