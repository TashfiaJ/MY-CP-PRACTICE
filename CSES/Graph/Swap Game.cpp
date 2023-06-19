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
const ll N = 2e5+5;
const ll mod=1e9+7;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int my_random(int l, int r)
{
    return uniform_int_distribution<int>(l, r) (rng);
}

unordered_map<string, ll>dis;
ll dx[]={0,1,2,3,4,5,1,2,4,5,7,8};
ll dy[]={3,4,5,6,7,8,0,1,3,4,6,7};
string target="";

ll pre()
{
    string per="123456789";
    dis[per]=1;
    queue<string>q;
    q.push(per);
    while(!q.empty())
    {
        string x=q.front();
        q.pop();
        if(x==target)return dis[x];
        ll d = dis[x];
        for(ll i=0;i<12;i++)
        {
            swap(x[dx[i]],x[dy[i]]);
            if(!dis[x])
            {
                dis[x]=d+1;
                q.push(x);
            }
            swap(x[dx[i]],x[dy[i]]);
        }
    }
    return 1;
}
void solve()
{
    for(ll i=0;i<9;i++)
    {
        char c;
        cin >> c;
        target+=c;
    }
    cout<<pre()-1;
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
