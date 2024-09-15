# Problem
[Bright Birthday](https://www.hackerrank.com/contests/srbd-code-contest-2023-round-1/challenges/bright-birthday)

# Solution

<details>
<summary>Idea</summary>

There are only 15 colors possible. Each color has a maximum length of 6. <br>
So, it is possible to brute force all possible combinations of colors and check if it can be made from the given string. To do that, we have to keep the count of each letter in $S$. <br>
The answer is the maximum size of the subset among all possible subsets which can be built.

</details>

<details>
<summary>Code</summary>

```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e9;

vector<string>c={ "blue", "green", "yellow", "red", "purple", "orange", "pink", "grey", "cyan", "brown", "ash", "silver", "gold", "white", "black" };

bool ok(vector<ll>cnt, ll val)
{
    for(ll i=0;i<15;i++)
    {
        if(val&(1ll<<i))
        {
            for(ll j=0;j<c[i].size();j++)
            {
                if(cnt[c[i][j]-'a']==0)return false;
                cnt[c[i][j]-'a']--;
            }
        }
    }
    return true;
}

void solve() 
{   
    string s;
    cin >> s;
    vector<ll>cnt(26,0ll);
    for(auto c: s)cnt[c-'a']++;
    ll ans=0ll;
    for(ll i=0;i<(1ll<<15);i++)
    {
        if(ok(cnt,i))
        {
            ans=max(ans,(ll)__builtin_popcountll(i));
        }
    }
    cout<<ans<<'\n';
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
