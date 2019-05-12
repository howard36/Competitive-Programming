#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<ll, int>

set<pi> cc, pp;
multiset<ll> dd;
ll c[50004], p[50004];

int main() {
	ll n, k, m;
	scanf("%lld %lld %lld", &n, &k, &m);
	for (int i = 0; i < n; i++) {
		scanf("%lld %lld", &p[i], &c[i]);
		cc.insert(pi(c[i], i));
		pp.insert(pi(p[i], i));
	}
	ll cost = 0;
	for (int i = 0; i < n; i++) {
		if (i < k) {
			int idx = (*cc.begin()).second;
			cost += c[idx];
			cc.erase(cc.find(pi(c[idx], idx)));
			pp.erase(pp.find(pi(p[idx], idx)));
			dd.insert(p[idx] - c[idx]);
		}
		else {
			int i1 = (*cc.begin()).second;
			int i2 = (*pp.begin()).second;
			ll d = *dd.begin();
			if (c[i1] + d < p[i2]) {
				cc.erase(cc.find(pi(c[i1], i1)));
				pp.erase(pp.find(pi(p[i1], i1)));
                dd.erase(dd.begin());
				dd.insert(p[i1] - c[i1]);
                cost += c[i1] + d;
			}
            else {
				cc.erase(cc.find(pi(c[i2], i2)));
				pp.erase(pp.find(pi(p[i2], i2)));
                cost += p[i2];
            }
		}
		if (cost > m) {
			printf("%d", i);
			return 0;
		}
	}
	printf("%d", n);
}