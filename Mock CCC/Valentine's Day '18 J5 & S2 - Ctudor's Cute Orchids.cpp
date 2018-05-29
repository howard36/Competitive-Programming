#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int needed[10], costs[10], deal[10][10], dealcost[10], cnt[10];

int main()
{
	int N, M;
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d", &costs[i]);
	}
	for (int i = 0; i < M; i++) {
		scanf("%d", &dealcost[i]);
		for (int j = 0; j < N; j++) {
			scanf("%d", &deal[i][j]);
		}
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &needed[i]);
	}
	int mincost = 1e9;
	for (int mask = 0; mask < (1 << M); mask++) {
		memset(cnt, 0, sizeof cnt);
		int cost = 0;
		for (int i = 0; i < M; i++) {
			if (mask & (1<<i)) {
				// buy deal i
				for (int j = 0; j < N; j++) {
					cnt[j] += deal[i][j];
				}
				cost += dealcost[i];
			}
		}
		bool toomuch = false;
		for (int i = 0; i < N; i++) {
			if (cnt[i] > needed[i]) {
				toomuch = true;
			}
		}
		if (toomuch)
			continue;
		else {
			for (int i = 0; i < N; i++) {
				cost += (needed[i] - cnt[i])*costs[i];
			}
		}
		mincost = min(mincost, cost);
	}
	printf("%d", mincost);
    return 0;
}