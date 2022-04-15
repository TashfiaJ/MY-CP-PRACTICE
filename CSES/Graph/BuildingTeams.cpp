#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
vector < ll > g [200010];
bool vis[200010];
ll col [200010]={};
ll flag=0;
 
void bfs ( ll s)
{
    std::queue<ll>q ;
    q.push(s);
    vis[s]=true;
    col[s]=1;
    while (!q.empty())
    {
        ll x = q.front();
        q.pop();
        for( auto z: g[x])
        {
           if(!vis[z])
           {
               vis[z]=true;
               col[z]=1-col[x];
               q.push(z);
           }
           else{
               if(col[z]==col[x])
               {
                   flag=1;
                   break;
               }
           }
        }
        if(flag)break;
    }
}
 
int main()
{
    ll n,m;
    cin>>n>>m;
    for ( ll i = 0; i<m ; i++)
    {
        ll a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
        
    }
    
    for(ll i = 1 ; i<=n; i++)
    {
        if(!vis[i])
        {
            bfs (i);
        }
        if(flag)break;
    }
    if(flag)
        cout<<"IMPOSSIBLE";
    else
    {
        for(ll i=1; i<=n; i++)
        {
            if(!col[i])cout<<2<<" ";
            else
            cout<<col[i]<<" ";
                
        }
    }
    
}
