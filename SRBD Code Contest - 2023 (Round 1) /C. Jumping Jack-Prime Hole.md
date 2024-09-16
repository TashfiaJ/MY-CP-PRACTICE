# Problem
[Jumping Jack: Prime Hole](https://www.hackerrank.com/contests/srbd-code-contest-2023-round-1/challenges/jacks-prime-hole)

# Solution

<details>
<summary>Idea</summary>

Two key things to notice: <br>
1. We do not care about the jumps. Rather, we will only consider hole-size to calculate the answer. <br>
2. If there is a hole of size $x$, then Jack must be able to jump at least $x+1$ bricks. <br>

So, it is clear that no hole can have a size more than $M-1$. This can be done by dynamic programming. <br>
Let's say, we are standing on position $i$. So, $i$ is a good brick. Then, we can create a hole of size $j$, where $j$ is a prime number and $j < M$. In that case, the next brick we can stand on would be $i+j+1$. So, for each $i$ we can iterate over all $j$ to calculate the ans. <br>
[Note that $0$ is also a prime number in this problem]. <br>
This gives us a solution with time complexity $O(N*M)$. This can be further optimized by only iterating over the prime numbers smaller than  $M$.
</details>

<details>
<summary>Code</summary>

```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e9;
const ll N = 1e5;
const ll mod = 1e9+7;

vector<bool>prime(N, true);
vector<ll>p;

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
    for(ll i=2;i<N;i++)
    {
        if(prime[i])p.push_back(i);
    }
}

void solve() 
{   
    ll n, m; cin >> n >> m;
    vector<ll>dp(n+2,0ll);
    //dp[i] -> i te bhalo brick thakle kotobhabe i position e jawa jay
    dp[0]=1;
    for(ll i=1;i<=n+1;i++)
    {
        dp[i]=dp[i-1];
        for(ll j=0;j<p.size()&&p[j]<m;j++)
        {
            if(i-p[j]-1>=0)dp[i]+=dp[i-p[j]-1];
        }
        dp[i]%=mod;
    }
    cout<<dp[n+1]<<'\n';
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
