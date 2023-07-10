ll id[N], r[N];

struct edge {
    ll u, v, cost;
};

vector<edge>edges;
vector<ll>trees;

bool cmp(edge a, edge b)
{
    return a.cost<b.cost;
}

ll root(ll x)
{
    return id[x] == x ? x: id[x] = root(id[x]);
}

ll kruskal(ll n)
{
    trees.clear();
    sort(edges.begin(), edges.end(), cmp);

    ll tot=0;
    for(ll i=0;i<n;i++) id[i]=i, r[i]=1;

    for(auto &p: edges)
    {
        ll x = root(p.u);
        ll y = root(p.v);
        if(x^y)
        {
            tot+=p.cost;
            trees.emplace_back(p.cost);

            if(r[x]<r[y])
                id[x] = y, r[y] += r[x];
            else
                id[y] = x, r[x] += r[y];
        }
    }

    edges.clear();
    return tot;
}
