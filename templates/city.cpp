#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> pi;
#define mp make_pair
#define pb push_back
#define F first
#define S second
const ll N = 1e5+5;
ll parent[N], Size[N], leader[N];

void make_set(int v) {
    parent[v] = v;
    Size[v] = 1;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    // Path compression
    return parent[v] = find_set(parent[v]);
}

void union_sets(ll a, ll b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        leader[b]=b;
        // Union by size
        if (Size[a] < Size[b])
            swap(a, b);
        parent[b] = a;
        Size[a] += Size[b];
    }
}

void solve()
{
   ll n, q;
   cin >> n >> q;
   for(ll i=1;i<=n;i++)
   {
       make_set(i);
   }
   while(q--)
   {
        ll qt;
        cin >> qt;
        if(qt==3)
        {
            ll id;
            cin >> id;
            cout << leader[find_set(id)]<<'\n';
        }
        else if(qt==1)
        {   
            ll a, b;
            cin >> a >> b;
            union_sets(a, b);
        }
   }
}

int main()
{
#ifndef ONLINE_JUDGE
//freopen("input.txt", "r", stdin);
#else
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll T; T=1; 
    cin >> T;
    while(T--)
    {
        solve();
    }
}
