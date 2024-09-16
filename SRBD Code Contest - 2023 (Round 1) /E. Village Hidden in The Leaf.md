# Problem
[Village Hidden in The Leaf](https://www.hackerrank.com/contests/srbd-code-contest-2023-round-1/challenges/village-hidden-in-the-leaf)

# Solution

<details>
<Summary>Hint</Summary>
Sieve, Binary Search
</details>

<details>
<summary>Idea</summary>

Let us answer $type-1$ query first. <br>
The answer is simply,
> (position of closest prime after $X$) - (positon of closest prime before $X$) - 2 <br>

So, we can keep a $set$ where we will only store the position of the prime numbers. Then simply we can use $lower\_{-}bound$ or $upper\_{-}bound$ to find immediate next and previous prime of the number at $X^{th}$ position. <br>

Now, whenever we encounter $type-2$ query, we check if the number $Y$ is a prime or not. If it is a prime, we insert $X$ into the set. Otherwise, we remove the $X$ from the set.

Note: To avoid bound checking, we can insert position 0 and n+1 into the set. As, those position will never come in query, those will never be removed from the set.

</details>

<details>
<summary>Code</summary>

```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e9;
const ll N = 1e7+10;

vector<bool>prime(N, true);

void sieve()
{
    prime[0]=prime[1]=false;
    for(ll i=2;i<N;i++)
    {
        if(prime[i])
        {
            for(ll j=i*i;j<N;j+=i)prime[j]=false;
        }
    }
}

void solve() 
{   
    ll n,m; cin >> n >> m;
    vector<ll>a(n+1);
    set<ll>s;
    s.insert(0ll);
    s.insert(n+1);
    for(ll i=1;i<=n;i++)
    {
        cin >> a[i];
        if(prime[a[i]])s.insert(i);
    }
    while(m--)
    {
        int ty; cin >> ty;
        if(ty==2)
        {
            ll x, y; cin >> x >> y;
            if(prime[y])s.insert(x);
            else s.erase(x);
        }
        else
        {
            ll x; cin >> x;
            auto nxt = s.upper_bound(x);
            auto pre = nxt;
            pre--;
            if(*pre==x)pre--;
            ll ans = (*nxt)-(*pre)-2;
            cout<<ans<<'\n';
        }
    }
}

signed main() 
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    sieve();
    for(int t = 1; t <= T; t++) {
        solve();
    }
}
```

</details>
