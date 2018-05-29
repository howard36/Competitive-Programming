#include <cstdio>
#include <vector>
#include <cstring>
#define pi pair<int, int>
using namespace std;

vector<pi> edges;
int visited[100];
int removed;
int N, M;

bool dfs(int v, int target) {
	if (v == target)
		return true;
	visited[v] = 1;
	for (int i = 0; i < M; i++) {
		if (i == removed)
			continue;
		int s = edges[i].first, t = edges[i].second;
		if (s = v && !visited[t] && dfs(t, target))
			return true;
	}
	return false;
}

int main()
{
	int s, t;
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; i++) {
		scanf("%d%d", &s, &t);
		edges.push_back(pi(s,t));
	}
	for (int i = 0; i < M; i++) {
		removed = i;
		memset(visited, 0, sizeof visited);
		if (dfs(1, N)) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
    return 0;
}