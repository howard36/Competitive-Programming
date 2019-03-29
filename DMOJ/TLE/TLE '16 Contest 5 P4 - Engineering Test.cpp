#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll t[2003];
ll w[100][100];

int main() {
	ll k, n;
	scanf("%lld %lld", &k, &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &t[i]);
	}
	sort(t, t + n, greater<ll>());
	w[0][0] = 0;
	ll h = 1;
	for (; (h + 1) * (h + 2) / 2 <= n; h++) {
		if (k % (1LL << h) != 0)
			break;
		w[h][0] = w[h - 1][0] + (1LL << (h - 1));
		w[h][h] = w[h - 1][h - 1] + (1LL << (h - 1));
		for (int i = 1; i < h; i++) {
			w[h][i] = w[h - 1][i - 1] + w[h - 1][i] + (1LL << h);
		}
		vector<ll> nums;
		for (int hh = 0; hh <= h; hh++) {
			for (int i = 0; i <= hh; i++) {
				nums.push_back(w[hh][i] * (k >> hh));
			}
		}
		bool bad = false;
		sort(nums.begin(), nums.end(), greater<ll>());
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] > t[i]) {
				bad = true;
			}
		}
		if (bad)
			break;
	}
	printf("%lld", h);
}