#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second

int n,m;
bool vis[1005][1005];
pair<int, int>st, en;
int dx[]={0,0,-1,1}, dy[]={-1,1,0,0};
int pa[1005][1005];
string s="LRUD";

bool is_possible(int x, int y)
{
	return (x<n && x>=0 && y<m && y>=0 && !vis[x][y]);
}

void bfs (pair<int, int> a)
{
	vis[a.f][a.s]=true;
	pa[a.f][a.s]=-1;
	
	queue<pair<int,int>>q;
	
	q.push({a.f, a.s});
	
	while(!q.empty())
	{
		pair<int, int> p= q.front();
		q.pop();
		
		for(int i=0;i<4;i++)
		{
			if(is_possible(p.f+dx[i], p.s+dy[i]))
			{
				vis[p.f+dx[i]][p.s+dy[i]]=true;
				pa[p.f+dx[i]][p.s+dy[i]]=i;
				q.push({p.f+dx[i], p.s+dy[i]});
			}
		}
		
		
	}
}

int main()
{
	cin >> n >> m;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			char c;
			cin >> c;
			vis[i][j]=(c=='#');
			if(c=='A')st={i,j};
			if(c=='B')en={i,j};
		}
	}
	
	bfs(st);
	
	if(!vis[en.f][en.s])
	{
		cout << "NO";
		return 0;
	}
	std::vector<int>ans;
	
	while(en!=st)
	{	
		int p = pa[en.f][en.s];
		ans.push_back(p);
		en={en.f-dx[p], en.s-dy[p]};
	}
	
	reverse(ans.begin(), ans.end());
	
	cout << "YES\n";
	
	cout << ans.size() << '\n';
	
	for(auto c: ans)
	{
		cout <<s[c];
	}
	
}
