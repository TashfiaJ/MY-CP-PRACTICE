#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second

ll dx[]={-1,1,0,0},dy[]={0,0,-1,1};
string dir="UDLR";
bool vis[1005][1005];
ll p[1005][1005];

int main()
{
    ll n,m; cin >> n >> m;
    getchar();
    char c;
    pair<ll,ll> start, finish;
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<m;j++)
        {
            cin >> c;
            if(c=='A')start={i,j};
            else if(c=='B')finish={i,j};
            else if(c=='#')vis[i][j]=true;
        }
    }

    queue<pair<ll,ll>>q;
    q.push(start);
    vis[start.f][start.s]=true;
    while(!q.empty())
    {
       pair<ll,ll> temp=q.front();
       q.pop();
       for(ll i=0;i<4;i++)
       {
           ll tempx=temp.f+dx[i],tempy=temp.s+dy[i];
           if(tempx>=0 && tempx<n && tempy>=0 && tempy<m && !vis[tempx][tempy])
           {
               q.push({tempx,tempy});
               vis[tempx][tempy]=true;
               p[tempx][tempy]=i;

           }
       }

    }
    if(vis[finish.f][finish.s])
    {
        cout<<"YES\n";
        vector<ll>ans;
        while(finish!=start)
        {
            ll i = p[finish.f][finish.s];
            ans.push_back(i);
            finish={finish.f-dx[i], finish.s-dy[i]};
        }
        reverse(ans.begin(),ans.end());
        cout<<ans.size()<<endl;
        for(ll c:ans)
            cout<<dir[c];
    }
    else
        cout<<"NO";
}
