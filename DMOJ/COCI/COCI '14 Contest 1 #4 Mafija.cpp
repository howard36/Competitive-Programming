#include <bits/stdc++.h>
using namespace std;

int out[500005], in[500005], used[500005];

int ans = 0;

void prune(int v) {
	if (in[v] == 0 && !used[v]) {
		ans++;
		used[v] = 1;
		// in[out[v]]--;
		used[out[v]] = 1;
		in[out[out[v]]]--;
		prune(out[out[v]]);
	}
}

int main() {
    freopen("data.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &out[i]);
        out[i]--;
		in[out[i]]++;
	}
	for (int i = 0; i < n; i++) {
		prune(i);
	}
    for (int i = 0; i<n; i++){
        if (in[i] == 0 && !used[i])
            printf("Should prune again");
    }
	for (int i = 0; i < n; i++) {
		if (used[i])
			continue;
		int cycleSize = 1;
		for (int j = out[i]; j != i; j = out[j]){
            used[j] = 1;
			cycleSize++;
        }
        used[i] = 1;
		ans += cycleSize / 2;
	}
    printf("%d\n", ans);
}