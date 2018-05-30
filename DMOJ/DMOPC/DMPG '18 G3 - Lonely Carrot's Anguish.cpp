#include <cstdio>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;

vector<int> adj[200005];
int depth[200005], parent[200005], subsize[200005], lowest[200005];

void dfs(int v, int d) {
	depth[v] = d;
	for (int i : adj[v]) {
		if (i != parent[v]) {
			parent[i] = v;
			dfs(i, d + 1);
			subsize[v] += subsize[i];
			lowest[v] = max(lowest[v], lowest[i] + 1);
		}
	}
	subsize[v]++;
}

ll count(int v, int d) {
	if (d == 0)
		return 1;
	if (d == 1)
		return adj[v].size();
	if (d >= lowest[v])
		return subsize[v];
	ll ans = 1;
	for (int i : adj[v]) {
		if (i != parent[v]) {
			ans += count(i, d - 1);
		}
	}
	return ans;
}

int main()
{
	int N, a, b;
	scanf("%d", &N);
	for (int i = 0; i < N - 1; i++) {
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1, 0);

	int Q, n, d;
	scanf("%d", &Q);
	for (int i = 0; i < Q; i++) {
		scanf("%d %d", &n, &d);
		if (d >= lowest[n]) {
			ll ans = 1LL * (subsize[n] - 1) * (subsize[n] - 1);
			for (int i : adj[n]) {
				if (i != parent[n]) {
					ans -= 1LL * subsize[i] * subsize[i];
				}
			}
			ans /= 2;
			ans += subsize[n];
			printf("%lld\n", ans);
		}
		else if (d == 0) {
			printf("1\n");
		}
		else {
			ll ans = 0, sum = 0;
			for (int i : adj[n]) {
				if (i != parent[n]) {
					ll c = count(i, d - 1);
					ans -= c * c;
					sum += c;
				}
			}
			ans += sum * sum;
			ans /= 2;
			ans += sum + 1;
			printf("%lld\n", ans);
		}
	}
    return 0;
}