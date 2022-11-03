#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> pi;
#define mp make_pair
#define pb push_back
#define F first
#define S second
const int N  = 1000005;
int composite[N], ans[N];
vector<int>primes;
void SieveOfEratosthenes()
{
    primes.push_back(2);
    for(int i = 4; i<N; i+=2)
        composite[i]=1;
    for (int p = 3; p <N ; p+=2) {
        
        if (composite[p]==0) {
            primes.push_back(p);
            if(p<1000)
            for (int i = p * p; i<N; i += p)
                composite[i] = 1;
        }
    }
    int tmp; ans[1]=2;
    for(int i=2;i<N;i++)
    {
        if(!composite[i]) tmp=i;
        ans[i]=tmp;
    }
    for(int i=N-1;i>=1;i--)
    {
        if(!composite[i]) tmp=i;
        if((i-ans[i])>(tmp-i)) ans[i]=tmp;
    }
}
void solve()
{
    int x;
    cin >> x;
    cout << ans[x] << "\n";
}
int main()
{
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int T; 
    cin >> T;
    SieveOfEratosthenes();
    while(T--)
    {
        solve();
    }
}
