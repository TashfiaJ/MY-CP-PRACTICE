#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> pi;
#define mp make_pair
#define pb push_back
#define F first
#define S second
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int my_random(int l, int r)
{
    return uniform_int_distribution<int>(l, r) (rng);
}

void solve()
{
    int n, m;
    cin >> n >> m;
    int a[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cin >> a[i][j];
    }
    int count = 0,ans=0;
    for(int i=1;i<n-1;i++)
    {
        for(int j=1;j<m-1;j++)
        {
            if(a[i][j]==a[i][j+1] && a[i][j]==a[i][j-1] && a[i][j]==a[i-1][j] && a[i][j]==a[i+1][j])
            {
                count = 1;
                for(int left=j-1;left>=0;left--)
                {
                    if(a[i][j]==a[i][left])count++;
                    else break;
                }
                for(int right=j+1;right<m;right++)
                {
                    if(a[i][j]==a[i][right])count++;
                    else break;
                }
                for(int up=i-1;up>=0;up--)
                {
                    if(a[i][j]==a[up][j])count++;
                    else break;
                }
                for(int down=i+1;down<n;down++)
                {
                    if(a[i][j]==a[down][j])count++;
                    else break;
                }
                ans=max(ans,count);
            }
        }
    }
    cout<<ans<<'\n';
}

int main()
{
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int T; T=1; 
    cin >> T;
    for(int i=1;i<=T;i++)
    {   
        cout<<"Case "<<i<<": ";
        solve();
    }
}
