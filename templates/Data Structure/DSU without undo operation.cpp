// https://codeforces.com/problemset/problem/1559/D1

#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct DSU{
    ll k;
    vector<ll>parent, Size;
    DSU(ll n)
    {
        k=n;
        parent.resize(k);
        Size.resize(k);
    }
    void make_set() {
        for(ll i=0;i<k;i++){
        parent[i] = i;
        Size[i] = 1;}
    }

    ll find_set(ll v) {
        if (v == parent[v])
            return v;
        // Path compression
        return parent[v] = find_set(parent[v]);
    }

    void union_sets(ll a, ll b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            // Union by size
            if (Size[a] < Size[b])
                swap(a, b);
            parent[b] = a;
            Size[a] += Size[b];
        }
    }

    bool check(ll a, ll b)
    {
        return find_set(a)==find_set(b);
    }
};

void solve()
{
    ll n, m1, m2; cin >> n >> m1 >> m2;
    DSU dsu1(n), dsu2(n);
    dsu1.make_set();
    dsu2.make_set();
    for(ll i=0;i<m1;i++)
    {
        ll a, b; cin >> a >> b;
        a--; b--;
        dsu1.union_sets(a,b);
    }
    for(ll i=0;i<m2;i++)
    {
        ll a, b; cin >> a >> b;
        a--; b--;
        dsu2.union_sets(a,b);
    }
    vector<pair<ll,ll>>ans;
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<n;j++)
        {
            if(i!=j)
            {
                if(!dsu1.check(i,j) && !dsu2.check(i,j))
                {
                    dsu1.union_sets(i,j);
                    dsu2.union_sets(i,j);
                    ans.push_back({i+1,j+1});
                }
            }
        }
    }
    cout<<ans.size()<<'\n';
    for(ll i=0;i<(ll)ans.size();i++)
    {
        cout<<ans[i].first<<" "<<ans[i].second<<'\n';
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll T; T=1; 
    //cin >> T;
    while(T--)
    {
        solve();
    }
}
