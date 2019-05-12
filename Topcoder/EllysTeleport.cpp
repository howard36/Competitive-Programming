#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<ll, int>

class EllysTeleport {
	ll h[10004];
	pi hs[10004];
	int to[10004];
	int mem[10004];
	int incycle[10004];
	int N;

	int calc(int i, int num, vector<int> &vis) {
		if (mem[i] != -1)
			return mem[i];
		if (vis[i]) {
			int ans = num - vis[i];
			int cur = i;
			for (int j = 0; j < ans; j++) {
				incycle[cur] = 1;
				cur = to[cur];
			}
			vis[i] = 0;
			return ans;
		}
		vis[i] = num;
		int ans = 1 + calc(to[i], num + 1, vis);
		vis[i] = 0;
		if (incycle[i])
			ans--;
		return ans;
	}

  public:
	int getMax(int n, int h1, int a, int b, int p, int q, int m) {
		h[0] = h1;
        hs[0] = pi(h1, 0);
		for (int i = 1; i < n; i++) {
			h[i] = (h[i - 1] * a + b) % m;
			hs[i] = pi(h[i], i);
		}
		sort(hs, hs + n);
		for (int i = 0; i < n; i++) {
			ll val = (h[i] * p + q) % m;
			int idx = upper_bound(hs, hs + n, pi(val, m)) - hs - 1;
			if (idx == -1)
				to[i] = n;
			else
				to[i] = hs[idx].second;
		}
		memset(mem, -1, sizeof mem);
		mem[n] = 0;
		int ans = 0;
		vector<int> vis(n);
		for (int i = 0; i < n; i++) {
			int c = calc(i, 1, vis);
			ans = max(ans, c);
		}
		return ans;
	}
};
