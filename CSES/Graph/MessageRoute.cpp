#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll n,m; cin >> n >> m;
    vector<ll>g[n+1];
    for(ll i=0;i<m;i++)
    {
        ll a,b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    bool vis[n+1]={false};
    ll p[n+1];

    queue<ll>q;
    q.push(1);
    vis[1]=true;
    p[1]=0;
    while(!q.empty())
    {
        ll t=q.front();
        q.pop();
        for(auto x: g[t])
        {
            if(!vis[x])
            {
                q.push(x);
                vis[x]=true;
                p[x]=t;
            }
        }
    }
    if(!vis[n])
    {
        cout<<"IMPOSSIBLE";
    }
    else
    {
        ll end_=n;
        vector<ll>path;
        while(end_!=1)
        {
            path.push_back(end_);
            end_=p[end_];
        }
        path.push_back(1);
        reverse(path.begin(),path.end());
        cout << path.size() << endl;
        for(auto x: path)
        {
            cout << x << " ";
        }
    }
}
