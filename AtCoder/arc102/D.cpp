#include <bits/stdc++.h>
using namespace std;
#define pi pair<int, int>
#define edge pair<pi, int>

vector<edge> e;

void solve(int n, int l) {
	e.push_back(edge(pi(n - 1, n), 0));
	if (l > 1) {
		if (l % 2 == 1)
			e.push_back(edge(pi(1, n), l - 1));
		e.push_back(edge(pi(n - 1, n), l / 2));
	}
	if (n > 2)
		solve(n - 1, l / 2);
}

int main() {
	int l;
	scanf("%d", &l);
	solve(20, l);
	printf("20 %d\n", e.size());
	for (edge ee : e) {
		printf("%d %d %d\n", ee.first.first, ee.first.second, ee.second);
	}
}