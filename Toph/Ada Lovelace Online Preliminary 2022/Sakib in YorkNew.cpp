#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n, q, mx;
ll lv[200005], dis[200005];
vector<ll>adj[200005];
bool vis[200005];
void bfs1(ll des, ll par[])
{   
    for(ll i=1;i<=n;i++)
    {
        lv[i]=0;
        dis[i]=0;
        vis[i]=false;
        par[i]=-1;
    }
    queue<ll>q;
    q.push(1);
    lv[1]=0;
    //dis[1]+=2;
    vis[1]=true;
    par[1]=-1;
    while(!q.empty())
    {
        ll tmp=q.front();
        q.pop();
        for(auto x: adj[tmp])
        {
            if(!vis[x])
            {
                vis[x]=true;
                lv[x]=lv[tmp]+1;
                par[x]=tmp;
                q.push(x);
                // if(x!=des)
                // dis[x]+=2;
                // else
                // dis[x]+=1;
                // if(dis[x]>dis[mx]){mx=x;}
                // else if(dis[x]==dis[mx] && lv[x]>lv[mx]){mx=x;}
            }
        }
    }
    
    ll a=des;
    mx=a;
            dis[a]+=1;
            for(ll i=par[a];i!=-1;i=par[i])
            {   
                
                dis[i]+=2;
                if(dis[i]>dis[mx])mx=i;
                else if(dis[i]==dis[mx] && lv[i]>lv[mx])mx=i; 
            }
    
}

void bfs2(ll des, ll src, ll par[])
{   
    for(ll i=1;i<=n;i++)
    {
        par[i]=-1;
        vis[i]=false;
    }
    queue<ll>q;
    q.push(src);
    
    //dis[1]+=1;
    vis[src]=true;
    par[src]=-1;
    while(!q.empty())
    {
        ll tmp=q.front();
        q.pop();
        for(auto x: adj[tmp])
        {
            if(!vis[x])
            {
                vis[x]=true;
                
                par[x]=tmp;q.push(x);
                // if(x!=des)
                // dis[x]+=2;
                // else
                // dis[x]+=1;
                // if(dis[x]>dis[mx]){mx=x;}
                // else if(dis[x]==dis[mx] && lv[x]>lv[mx]){mx=x;}
            }
        }
    }
    
}

int main()
{
    
    cin >> n >> q;
    ll par[n+1];
    for(ll i=0;i<n-1;i++)
    {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    while(q--)
    {
        ll a, b;
        cin >> a >> b;
        if(a==1 || b==1)cout << 1 << " " << 2 << '\n';
        else
        {
            bfs1(a, par);
            // mx=a;
            // dis[a]+=1;
            // for(ll i=par[a];i!=-1;i=par[i])
            // {   
            //     cout << i << " ";
            //     dis[i]+=2;
            //     if(dis[i]>dis[mx])mx=i;
            //     else if(dis[i]==dis[mx] && lv[i]>lv[mx])mx=i; 
            // }
            //cout << dis[3];
            bfs2(b, a, par);
            dis[b]+=1;
            for(ll i=par[b];i!=-1;i=par[i])
            {   
                if(i==1)dis[1]++;
                else
                dis[i]+=2;
                if(dis[i]>dis[mx])mx=i;
                else if(dis[i]==dis[mx] && lv[i]>lv[mx])mx=i; 
            }
            cout << mx << " " << dis[mx] << '\n';
        }
    }
}
