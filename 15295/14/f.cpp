#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

ll c[200005], v[200005];
vector<ll> g;

ll time(ll f) {
	ll ans = 0;
	for (int i = 0; i<g.size()-1; i++) {
		ll d = g[i+1] - g[i];
		if (d > f)
			return 1e18;
		ll b = min(f - d, d);
		ll a = d - b;
		ans += 2*a+b;
	}
	return ans;
}

int main() {
	ll n, k, s, t;
	cin >> n >> k >> s >> t;
	ll V2 = 0, V1 = 1e18;
	for (int i = 0; i<n; i++) { 
		cin >> c[i] >> v[i];
		V2 = max(V2, v[i]);
		V1 = min(V1, v[i]);
	}
	g.pb(0);
	for (int i = 0; i<k; i++) {
		ll x;
		cin >> x;
		g.pb(x);
	}
	g.pb(s);
	sort(g.begin(), g.end());

	ll lo = V1, hi = V2 + 1;
	while (lo < hi) {
		ll mid = (lo+hi)/2;
		if (time(mid) <= t)
			hi = mid;
		else
			lo = mid+1;
	}
	if (lo == V2 + 1)
		cout << -1 << endl;
	else {
		ll ans = 1e18;
		for (int i = 0; i<n; i++) {
			if (v[i] >= lo)
				ans = min(ans, c[i]);
		}
		cout << ans << endl;
	}
}
