#include <bits/stdc++.h>
using namespace std;

vector<int> adj[5003];
int a[5003], b[5003], d[5003], rem[5003];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i<m; i++) {
		scanf("%d %d", &a[i], &b[i]);
		adj[a[i]].push_back(b[i]);
		d[b[i]]++;
	}
	bool dag = true;
	for (int i = 0; i<n; i++) {
		int v = -1;
		for (int j = 1; j<=n; j++)
			if (d[j] == 0 && !rem[j])
				v = j;
		if (v == -1) {
			dag = false;
			break;
		}
		rem[v] = 1;
		for (int j : adj[v])
			d[j]--;
	}
	if (dag) {
		printf("1\n");
		for (int i = 0; i<m; i++)
			printf("1 ");
	}
	else {
		printf("2\n");
		for (int i = 0; i<m; i++) {
			if (a[i] < b[i])
				printf("1 ");
			else
				printf("2 ");
		}
	}
}
