# Problem
[Contest Setting](https://www.hackerrank.com/contests/srbd-code-contest-2023-round-1/challenges/contest-setting-1)

# Solution
<details>
<Summary>Hint</Summary>
Binary Search
</details>
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

<details>
<Summary>Hint</Summary>
Quadratic Equation
</details>
<details>
<Summary>Idea2</Summary>
Quadratic equation: $m^2$ + 2my -2b=0
</details>
<details>
<Summary>Code</Summary>
    
```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define lll __int128_t
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define SetBit(x, k) (x |= (1LL << k))
#define ClearBit(x, k) (x &= ~(1LL << k))
#define CheckBit(x, k) (x & (1LL << k))
const ll inf = 1e18;
const ll md = 998244353;
const ll N = 2e5+5;

ll dx[]={0,1,0,-1};
ll dy[]={1,0,-1,0};
ll dxx[]={0,1,0,-1,1,1,-1,-1};
ll dyy[]={1,0,-1,0,1,-1,1,-1};

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int my_random(int l, int r)
{
    return uniform_int_distribution<int>(l, r) (rng);
}

void solve()
{
    ll b, y;
    cin >> b >> y;
    ll tmp = (-(2*y)+sqrt((4*y*y)+(8*b)))/2;
    ll ans = pow(2,tmp);
    cout<<ans<<'\n';
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll T; T=1; 
    cin >> T;
    for(ll i=1;i<=T;i++)
    {   
        //cout<<"Case "<<i<<": ";
        solve();
    }
}
```
    
</details>
