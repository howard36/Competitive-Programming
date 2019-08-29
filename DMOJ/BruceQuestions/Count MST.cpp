#include <bits/stdc++.h>
using namespace std;
#define pi pair<int, int>
#define ll long long
#define mod 1000000007LL

int p[40004], sz[40004], f[1000006], f2[1000006];
vector<pi> e[1000006];

int find(int i) {
	if (p[i] == i)
		return i;
	return p[i] = find(p[i]);
}

void join(int i, int j) {
	i = find(i);
	j = find(j);
	if (sz[i] > sz[j])
		swap(i, j);
	p[i] = j;
	sz[j] += sz[i];
}

int main() {
	int n, m, u, v, w;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &u, &v, &w);
        e[w].push_back(pi(u, v));
	}
	sort(edges, edges + m);
    for (int i = 1; i<=n; i++) {
        p[i] = i;
        sz[i] = 1;
    }
	ll ans = 1, sum = 0;
	for (int i = 1; i<=1000000; i++) {
        for (pi p : e[i]) {
            tie(u, v) = p;
            if (find(u) != find(v))
                f[i]++;
        }
		for (pi p : e[i]) {
			tie(u, v) = p;
			if (find(u) != find(v)){
                join(u, v);
                sum += i;
                f2[i]++;
            }
		}
		if (f2[i] > 0 && f2[i] < f[i])
			ans = (f[i] * ans) % mod;
	}
	printf("%lld %lld", sum, ans);
}