# Problem
[Contest Setting](https://www.hackerrank.com/contests/srbd-code-contest-2023-round-1/challenges/contest-setting-1)

# Solution
<details>
<Summary>Idea1</Summary>
We can just do a binary search on the value of $m$ to find the maximum value of $m$. After that, we can say, $N = 2^m$
</details>
<details>
<Summary>Code</Summary>
```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e9;

// Binary Search

void solve() 
{   
    ll B, y; cin >> B >> y;
    ll low = 0, high = INF;
    ll ans=0;
    while(low<=high)
    {
        ll mid = (low+high)/2;
        ll a =mid/2;
        ll b = mid-a;
        if(mid*y+a*a+b*b<=B)
        {
            ans=mid;
            low=mid+1;
        }
        else high=mid-1;
    }
    cout<<(1ll<<ans)<<'\n';
}

signed main() 
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    for(int t = 1; t <= T; t++) {
        solve();
    }
}
```
</details>
