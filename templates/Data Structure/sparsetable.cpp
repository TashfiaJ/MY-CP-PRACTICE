// video https://youtu.be/0jWeUdxrGm4
// problem https://cses.fi/problemset/task/1647/
// max, min, gcd
// nope - sum, any update

#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll MAX_N = 2e5+5;
ll a[MAX_N];
ll m[MAX_N][17]; // m[i][j] is minimum among a[i..i+2^j-1]


ll query(ll L, ll R) { // O(1)
	ll length = R - L + 1;
	ll k = log2(length);
	return min(m[L][k], m[R-(1<<k)+1][k]);
}

int main() {
	// 1) read input
	ll n, q;
	cin >> n >> q;
	for(ll i = 1; i <= n; i++) {
		cin >> a[i];
		m[i][0] = a[i];
	}
	// 2) preprocessing, O(N*log(N))
    ll LOG = log2(n);
	for(ll k = 1; k <= LOG; k++) {
		for(ll i = 1; i + (1 << k) - 1 <= n; i++) {
			m[i][k] = min(m[i][k-1], m[i+(1<<(k-1))][k-1]);
		}
	}
	// 3) answer queries
	
	for(ll i = 0; i < q; i++) {
		ll L, R;
		cin >> L >> R;
		cout << query(L, R) << "\n";
	}
}
