#include <bits/stdc++.h>
using namespace std;

const int MAX = 4e6;
int good[2000006];
multiset<int> s;
int dist[1000006];
int bit[MAX];

void update(int i, int v) {
	for (; i < MAX; i += (i & -i))
		bit[i] += v;
}

int query(int i) {
	int ans = 0;
	for (; i > 0; i -= i & -i)
		ans += bit[i];
	return ans;
}

int bsearch() {
	int lo = 1, hi = MAX-1;
	while (lo < hi) {
		int mid = (lo + hi) / 2;
		if (query(mid) > 0) {
			hi = mid;
		}
		else {
			lo = mid + 1;
		}
	}
    if (lo == MAX-1) return 1e9;
	return lo;
}

int main() {
    // freopen("data.txt", "r", stdin);
	int h, j, n, a, b;
	scanf("%d %d %d", &h, &j, &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);
		good[a]++;
		good[b + 1]--;
	}
	for (int i = 1; i <= h; i++) {
		good[i] += good[i - 1];
	}
	for (int i = 0; i < h+j; i++) {
		if (good[i]) {
			good[i] = 0;
		}
		else {
			good[i] = 1;
		}
	}

	for (int i = 1; i < h+j; i++) {
		dist[i] = 1e9;
	}
	if (good[j]) {
		dist[j] = 1;
        update(dist[j], 1);
        // printf("i = 0, %d added\n", dist[j]);
	}
	for (int i = 1; i < h; i++) {
        if (i >= j){
            update(dist[i], -1);
            // printf("i = %d, %d removed\n", i, dist[i]);
        }
		if (good[i]) {
            // printf("i = %d, bsearch = %d\n", i, bsearch());
            dist[i] = min(dist[i], bsearch() + 1);
            if (good[i+j]){
                dist[i+j] = dist[i]+1;
                update(dist[i+j], 1);
                // printf("i = %d, %d added\n", i, dist[i+j]);
            }
		}
	}
    int ans = 1e9;
    for (int i = h; i<h+j; i++){
        ans = min(ans, dist[i]);
    }
    if (ans != 1e9){
        printf("%d\n", ans);
    }
    else{
        printf("-1\n");
    }
    // for (int i = 0; i<h+j; i++){
    //     printf("dist[%d] = %d\n", i, dist[i]);
    // }
}