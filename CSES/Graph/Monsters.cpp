#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> pi;
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define SetBit(x, k) (x |= (1LL << k))
#define ClearBit(x, k) (x &= ~(1LL << k))
#define CheckBit(x, k) (x & (1LL << k))
const ll INF = 1LL<<60; //1.15e18
const ll md = 1000000007;
const ll N = 2e5+5;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int my_random(int l, int r)
{
    return uniform_int_distribution<int>(l, r) (rng);
}

ll n, m;
char g[2000][2000];
vector<vector<ll>>dis1(2000, vector<ll>(2000, INF));
vector<vector<ll>>dis2(2000, vector<ll>(2000, INF));
vector<vector<ll>>pa(2000, vector<ll>(2000, -1));
vector<ll>ans;
pair<ll,ll>st, en;
ll dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
string dir="RLDU";

bool is_possible(ll x, ll y)
{
    return (x<n && x>=0 && y<m && y>=0 && g[x][y]!='#');
}

bool is_boundary(ll x, ll y)
{
    return (x==0 || x==n-1 || y==0 || y==m-1);
}

void path()
{

    while(en!=st)
    {
        ll p = pa[en.F][en.S];
        ans.pb(p);
        en = {en.F-dx[p], en.S-dy[p]};
    }

    reverse(ans.begin(), ans.end());

    cout << "YES\n";

    cout << ans.size() << '\n';

    for(auto x: ans)
    {
        cout << dir[x];
    }
}

void bfs(queue<pair<ll,ll>> q, ll c)
{

  while(!q.empty())
  {
        pair<ll,ll> p = q.front();
        q.pop();
        for(ll i=0;i<4;i++)
        {
            if(is_possible(p.F+dx[i], p.S+dy[i]))
            {   
                if(c==2 && (dis2[p.F+dx[i]][p.S+dy[i]]>dis2[p.F][p.S]+1)){
                    
                    dis2[p.F+dx[i]][p.S+dy[i]]=min(dis2[p.F+dx[i]][p.S+dy[i]], dis2[p.F][p.S]+1);
                    if(is_boundary(p.F+dx[i], p.S+dy[i]))
                    {  
                        if(dis2[p.F+dx[i]][p.S+dy[i]]<dis1[p.F+dx[i]][p.S+dy[i]])
                            {   
                            en={p.F+dx[i], p.S+dy[i]};
                            pa[p.F+dx[i]][p.S+dy[i]]=i;
                            path();
                            return;
                            }
                    
                    }
                    q.push({p.F+dx[i], p.S+dy[i]});
                    pa[p.F+dx[i]][p.S+dy[i]]=i;
                }
                else
                {
                    if((dis1[p.F+dx[i]][p.S+dy[i]]>dis1[p.F][p.S]+1))
                    {
                        dis1[p.F+dx[i]][p.S+dy[i]]=min(dis1[p.F+dx[i]][p.S+dy[i]], dis1[p.F][p.S]+1);
                        q.push({p.F+dx[i], p.S+dy[i]});
                        pa[p.F+dx[i]][p.S+dy[i]]=i;
                    }
                }
            }
            
        }

  }
   if(c==2)
        {
            cout << "NO";
        }
}


void solve()
{
    cin >> n >> m;
    queue<pair<ll,ll>>monster, me;
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<m;j++)
        {
            cin >> g[i][j];
            if(g[i][j]=='M')
            {
                monster.push({i,j});
                dis1[i][j]=0;
            }
            if(g[i][j]=='A')
            {
                st={i,j};
                me.push({i,j});
                dis2[i][j]=0;
                if(is_boundary(i,j))
                {
                    cout <<"YES\n";
                    cout << 0;
                    return;
                }
            }
        }
    }
    bfs(monster, 1);
    pa.assign(2000, vector<ll>(2000, -1));
    bfs(me, 2);

}

int main()
{
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll T; T=1; 
    //cin >> T;
    while(T--)
    {
        solve();
        
    }
}
