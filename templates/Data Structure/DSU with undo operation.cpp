struct DSU
{
    ll k;
    vector<ll>par,sz;
    stack<tuple<ll,ll,ll>>changes;
    DSU(ll n)
    {
        k=n;
        par.resize(k);
        sz.resize(k);
        for(ll i=0;i<k;i++)
        {
            par[i]=i;
            sz[i]=1;
        }
    }
    ll findpar(ll a)
    {
        if(a==par[a])return a;
        return par[a]=findpar(par[a]);
    }
    void unite(ll a, ll b)
    {
        a=findpar(a);
        b=findpar(b);
        if(a!=b){
        if(sz[a]>sz[b])swap(a,b);
        par[a]=b;
        sz[b]+=sz[a];
        changes.push({a,b,sz[a]});
        }
    }
    void undo(ll n)
    {
        while(n--)
        {
            auto [u,v,x] = changes.top();
            changes.pop();
            par[a]=a;
            sz[v]-=x;
        }
    }
    bool check(ll a, ll b)
    {
        return findpar(a)==findpar(b);
    }
};
