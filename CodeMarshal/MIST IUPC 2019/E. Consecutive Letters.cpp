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
    string s;
    cin>>s;
    ll sz=s.size();
    set<ll>st;
    for(ll i=0;i<sz;i++)
    {
        if(i==0)st.insert(i);
        else if(s[i]!=s[i-1])st.insert(i);
    }
    st.insert(sz);
    ll q;
    cin>>q;
    while(q--)
    {
        ll type, id;
        cin>>type>>id;
        if(type==1)
        {
            auto x=st.upper_bound(id);
            ll right=*x;
            x--;
            ll left=*x;
            cout<<right-left<<'\n';
        }
        else
        {
            st.insert(id);
            st.insert(id+1);
        }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll T; T=1; 
    cin >> T;
    for(ll i=1;i<=T;i++)
    {   
        cout<<"Case "<<i<<":\n";
        solve();
    }
}
