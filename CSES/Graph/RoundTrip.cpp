#include<bits/stdc++.h>
using namespace std;
#define ll int
#define f first
#define s second
 
ll n,m;
vector<ll>adj_list[200005];
bool vis[200005];
ll par[200005], flag=0, sv, ev;
 
bool dfs(ll v, ll p)
{
	vis[v]=true;
	par[v]=p;
	
	for(ll c:adj_list[v])
	{
		if(c==p)continue;
		if(vis[c])
		{
			sv = v;
			ev = c;
			flag=1;
			return true;
		}
		if(!vis[c])
		{
		    bool check=dfs(c, v);
			
		}
	}
	if(flag)return true;
	return false;
}
 
int32_t main()
{
	cin >> n >> m;
	
	for(ll i=0; i<m; i++)
	{
		ll a, b;
		cin >> a >> b;
		adj_list[a].push_back(b);
		adj_list[b].push_back(a);
	}
	
	
	
	for(ll i=1; i<=n; i++)
	{
		if(!vis[i])
		{
			bool check=dfs(i, -1);
			if(flag) break;
		}
	}
	
	if(!flag){cout << "IMPOSSIBLE"; return 0; }
	vector<ll>ans;
	ans.push_back(sv);
	while(ev!=sv)
	{
		ans.push_back(ev);
		ev = par[ev];
	}
	ans.push_back(sv);
	cout << ans.size() << '\n';
	 for( auto c: ans)
	 {
	 	cout << c << " ";
	 }
}
