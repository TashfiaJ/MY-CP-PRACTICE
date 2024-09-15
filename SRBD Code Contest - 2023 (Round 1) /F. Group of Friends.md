# Problem
[Group of Friends](https://www.hackerrank.com/contests/srbd-code-contest-2023-round-1/challenges/group-of-friends)

# Solution

<details>
<Summary>Hint</Summary>
DSU
</details>

<details>
<summary>Idea</summary>

It is clear that, if there are two numbers $x$ and $y$, where $x$ is a multiple of $y$, then $x$ and $y$ are in the same group.
So, for all $A_i$ we find the number that divides $A_i$ (other than $1$) and join them together using $DSU$. After that, the answer is the number of groups formed which contain at least one element from the array $A$.

Complexity: $O(N \sqrt {max(A_i)})$

</details>

<details>
<summary>Code</summary>

```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e9;
const ll N = 1e5+10;
ll s[N],p[N];

void init(ll n)
{
    for(ll i=0;i<=n;i++)
    {
        p[i]=i;
        s[i]=1;
    }
}

ll par(ll n)
{
    if(n==p[n])return n;
    return p[n]=par(p[n]);    
}

void join (ll a, ll b)
{
    ll pa = par(a), pb = par(b);
    if(s[pa]<s[pb])
    {
        swap(a,b);
        swap(pa, pb);
    }
    s[pa]+=s[pb];
    s[pb]=0;
    p[pb]=pa;
}

void solve() 
{   
    ll n; cin >> n;
    init(N);
    vector<ll>a(n);
    for(auto &i: a)
    {
        cin >> i;
        for(ll j=2;j*j<=i;j++)
        {
            if(i%j==0)
            {
                join(i,j);
                join(i,i/j);
            }
        }
    }
    set<ll>x;
    for(auto i: a)
    {
        x.insert(par(i));
    }
    cout<<x.size()<<'\n';
}

signed main() 
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    //cin >> T;
    for(int t = 1; t <= T; t++) {
        solve();
    }
}

```

</details>
