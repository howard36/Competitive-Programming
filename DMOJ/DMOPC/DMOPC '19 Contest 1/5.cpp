#include <bits/stdc++.h>
using namespace std;

int p[5], in[460000], out[460000];
vector<int> adj[460000], rev[460000], path;
stack<int> st;

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	if (k == 1) {
		for (int i = 0; i<n; i++) {
			char c;
			scanf(" %c", &c);
			printf("%c", c);
		}
		return 0;
	}
	p[0] = 1;
	for (int i = 1; i<k; i++)
		p[i] = 26*p[i-1];
	for (int i = 0; i<n; i++) {
		int a = 0;
		for (int j = 0; j<k; j++) {
			char c;
			scanf(" %c", &c);
			a *= 26;
			a += c-'a';
		}
		int x = a/26, y = a%p[k-1];
		adj[x].push_back(y);
		rev[y].push_back(x);
		out[x]++;
		in[y]++;
	}
	int s = -1, e = -1;
	for (int i = 0; i<p[k-1]; i++) {
		if (in[i] - out[i] == 1) {
			if (e == -1)
				e = i;
			else {
				printf("-1\n");
				return 0;
			}
		}
		else if (in[i] - out[i] == -1) {
			if (s == -1)
				s = i;
			else {
				printf("-1\n");
				return 0;
			}
		}
		else if (in[i] != out[i]) {
			printf("-1\n");
			return 0;
		}
	}
//	printf("s = %d\n", s);
	if (s == -1 || e == -1) {
		printf("-1");
		return 0;
	}
	st.push(s);
	while (!st.empty()) {
		int v = st.top();
		if (out[v]) {
			st.push(adj[v][out[v]-1]);
			adj[v].pop_back();
			out[v]--;
		}
		else {
			path.push_back(v);
			st.pop();
		}
	}
//	printf("%d\n", (int)path.size());
	reverse(path.begin(), path.end());
	for (int i = k-2; i > 0; i--) {
		printf("%c", 'a'+(path[0]/p[i])%26);
//		printf("%d ", path[0]);
	}
	for (int i = 0; i<path.size(); i++) {
		printf("%c", 'a'+path[i]%26);
//		printf("%d ", path[i]%26);
	}

}
