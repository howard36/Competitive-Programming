#include <bits/stdc++.h>
using namespace std;
#define pi pair<int, int>

int p[2000005], pos[200005], covered[200005];
vector<pi> moves;

int cover(int i) {
	while (!covered[i]) {
		covered[i] = 1;
		i = p[i];
	}
}

int needed(int n, int s[], int m, int x[], int y[]) {
	for (int i = 0; i < n; i++) {
		p[i] = s[i];
		pos[p[i]] = i;
	}
	for (int i = 0; i < m; i++) {
		swap(p[x[i]], p[y[i]]);
		swap(pos[p[x[i]]], pos[p[y[i]]]);
	}
	int cycles = 0;
	memset(covered, 0, sizeof covered);
	for (int i = 0; i < n; i++) {
		if (!covered[i]) {
			cover(i);
			cycles++;
		}
	}
	return n - cycles;
}

int findSwapPairs(int N, int S[], int M, int X[], int Y[], int P[], int Q[]) {
	int lo = 0, hi = N;
	while (lo < hi) {
		int mid = (lo + hi) / 2;
		if (needed(N, S, mid, X, Y) <= mid) {
			hi = mid;
		}
		else {
			lo = mid + 1;
		}
	}

	int m = lo;
	for (int i = 0; i < N; i++) {
		p[i] = S[i];
		pos[p[i]] = i;
	}
	for (int i = 0; i < m; i++) {
		swap(p[X[i]], p[Y[i]]);
		swap(pos[p[X[i]]], pos[p[Y[i]]]);
	}

	memset(covered, 0, sizeof covered);
	for (int i = 0; i < N; i++) {
		if (!covered[i]) {
			vector<int> cycle;
			for (int cur = i; !covered[cur]; cur = p[cur]) {
				covered[cur] = 1;
				cycle.push_back(cur);
			}
			for (int j = cycle.size() - 1; j > 0; j--) {
				moves.push_back(pi(cycle[0], cycle[j]));
			}
		}
	}

	for (int i = 0; i < N; i++) {
		p[i] = S[i];
		pos[p[i]] = i;
	}
	for (int i = 0; i < moves.size(); i++) {
		swap(p[X[i]], p[Y[i]]);
		swap(pos[p[X[i]]], pos[p[Y[i]]]);
		P[i] = pos[moves[i].first];
		Q[i] = pos[moves[i].second];
		swap(p[P[i]], p[Q[i]]);
		swap(pos[p[P[i]]], pos[p[Q[i]]]);
	}
    if (m > moves.size()){
        P[m-1] = 0;
        Q[m-1] = 0;
    }
	return m;
}