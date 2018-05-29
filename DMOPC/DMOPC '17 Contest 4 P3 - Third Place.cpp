#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
#define pb push_back
#define pi pair<int,int>
using namespace std;

vector<pi> adj[100005];
int depth[100005][2], best[100005][2], parent[100005];

void compute(int v) {
	vector<int> paths;
	vector<pi> semipaths;
	for (const pi& p : adj[v]) {
		int u = p.first, w = p.second;
		if (u == parent[v])
			continue;
		parent[u] = v;
		compute(u);
		paths.pb(best[u][0]);
		paths.pb(best[u][1]);
		semipaths.pb(pi(depth[u][0] + w, u));
		paths.pb(depth[u][0] + w);
		if (adj[u].size() != 1) {
			semipaths.pb(pi(depth[u][1] + w, u));
			paths.pb(depth[u][1] + w);
		}
	}

	sort(semipaths.begin(), semipaths.end(), greater<pi>());
	for (int i = 1; i < semipaths.size(); i++) {
		if (semipaths[i].second != semipaths[0].second) {
			paths.pb(semipaths[0].first + semipaths[i].first);
			if (i + 1 < semipaths.size() && semipaths[0].second != semipaths[i + 1].second)
				paths.pb(semipaths[0].first + semipaths[i + 1].first);
		}
	}
	for (int i = 2; i < semipaths.size(); i++) {
		if (semipaths[i].second != semipaths[1].second) {
			paths.pb(semipaths[1].first + semipaths[i].first);
			if (i + 1 < semipaths.size() && semipaths[1].second != semipaths[i + 1].second)
				paths.pb(semipaths[1].first + semipaths[i + 1].first);
		}
	}
	for (int i = 3; i < semipaths.size(); i++) {
		if (semipaths[i].second != semipaths[2].second) {
			paths.pb(semipaths[2].first + semipaths[i].first);
			if (i + 1 < semipaths.size() && semipaths[2].second != semipaths[i + 1].second)
				paths.pb(semipaths[2].first + semipaths[i + 1].first);
		}
	}

	sort(paths.begin(), paths.end(), greater<int>());
	if (paths.size() >= 1)
		best[v][0] = paths[0];
	if (paths.size() >= 2)
		best[v][1] = paths[1];

	if (semipaths.size() >= 1)
		depth[v][0] = semipaths[0].first;
	if (semipaths.size() >= 2)
		depth[v][1] = semipaths[1].first;
}

int main()
{
	int N, a, b, c;
	scanf("%d", &N);
	for (int i = 1; i < N; i++) {
		scanf("%d%d%d", &a, &b, &c);
		adj[a].pb(pi(b, c));
		adj[b].pb(pi(a, c));
	}
	compute(1);
	printf("%d", best[1][1]);
	return 0;
}