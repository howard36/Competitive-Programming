#include <bits/stdc++.h>
using namespace std;

int sa[10004][60], len[10004], link[10004], states, last, paths[10004];

void append(int c) {
	int cur = states++;
	len[cur] = len[last] + 1;
	int p = last;
	last = cur;
	for (; p != -1 && !sa[p][c]; p = link[p])
		sa[p][c] = cur;
	if (p == -1)
		link[cur] = 0;
	else {
		int q = sa[p][c];
		if (len[q] == len[p] + 1)
			link[cur] = q;
		else {
			int clone = states++;
			len[clone] = len[p] + 1;
			link[clone] = link[q];
			link[q] = link[cur] = clone;
			for (int cc = 0; cc < 60; cc++)
				sa[clone][cc] = sa[q][cc];
			for (; p != -1 && sa[p][c] == q; p = link[p])
				sa[p][c] = clone;
		}
	}
}

int calc(int i) {
	if (paths[i])
		return paths[i];
	paths[i] = 1;
	for (int c = 0; c < 60; c++) {
		if (sa[i][c])
			paths[i] += calc(sa[i][c]);
	}
	return paths[i];
}

int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		memset(sa, 0, sizeof sa);
		memset(len, 0, sizeof len);
		memset(link, 0, sizeof link);
		memset(paths, 0, sizeof paths);
		link[0] = -1;
		states = 1;
		last = 0;
		string s;
		cin >> s;
		for (char c : s)
			append(c - 'A');
		printf("%d\n", calc(0));
	}
}