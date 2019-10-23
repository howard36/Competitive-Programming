#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<ll, ll>
#define ppi pair<pi, pi>
#define f first
#define s second

bool closer(ppi p, ppi a, ppi b) {
	ll x = p.f.f, y = p.f.s, z = p.s.f;
	if (abs(x-a.f.f) < abs(x-b.f.f))
		return true;
	else if (abs(x-a.f.f) == abs(x-b.f.f)) {
		if (abs(y-a.f.s) < abs(y-b.f.s))
			return true;
		else if (abs(y-a.f.s) == abs(y-b.f.s)) {
			if (abs(z-a.s.f) <= abs(z-b.s.f)) {
				return true;
			}
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
}

ll dist(ppi a, ppi b) {
	return abs(a.f.f - b.f.f) + abs(a.f.s - b.f.s) + abs(a.s.f - b.s.f);
}

set<ppi> S;
ppi points[100005];
int used[100005];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i<n; i++) {
		ll x, y, z;
		scanf("%lld %lld %lld", &x, &y, &z);
		points[i] = ppi(pi(x, y), pi(z, i+1));
		S.insert(points[i]);
	}
	for (int i = 0; i<n; i++) {
		if (used[i])
			continue;
		used[i] = 1;
		int best = -1;
		for (int j = 0; j<n; j++) {
			if (used[j])
				continue;
			if (best == -1 || dist(points[i], points[j]) < dist(points[i], points[best]))
				best = j;
		}
		used[best] = 1;
		printf("%d %d\n", i+1, best+1);
	}
	return 0;
	while (!S.empty()) {
		ppi p2 = *(S.begin());
		S.erase(S.begin());
		auto it = S.begin();
		auto it2 = S.begin();
		++it2;
		while (it2 != S.end() && closer(p2, *it2, *it)) {
			++it;
			++it2;
		}
		ppi q = *it;
		S.erase(it);
		printf("%lld %lld\n", p2.s.s, q.s.s);
	}
}
