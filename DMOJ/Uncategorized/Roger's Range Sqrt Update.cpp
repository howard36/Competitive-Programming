#include <bits/stdc++.h>
#define ll long long

const int sz = 17;

struct node {
	ll sum = 0LL;
	bool done = false;
} seg[1 << (sz + 1)];

void update(int ql, int qr, int tl, int tr, int i) {
	if (qr < tl || ql > tr)
		return;
	if (seg[i].done)
		return;
	if (i >= (1 << sz)) {
		seg[i].sum = (ll)sqrt(seg[i].sum);
		seg[i].done = (seg[i].sum <= 1);
		return;
	}
	int mid = (tl + tr) / 2;
	update(ql, qr, tl, mid, 2 * i);
	update(ql, qr, mid + 1, tr, 2 * i + 1);
	seg[i].sum = seg[2 * i].sum + seg[2 * i + 1].sum;
	seg[i].done = seg[2 * i].done & seg[2 * i + 1].done;
}

ll query(int ql, int qr, int tl, int tr, int i) {
	if (qr < tl || ql > tr)
		return 0LL;
	if (ql <= tl && qr >= tr)
		return seg[i].sum;
	int mid = (tl + tr) / 2;
	ll ans = 0;
	ans += query(ql, qr, tl, mid, 2 * i);
	ans += query(ql, qr, mid + 1, tr, 2 * i + 1);
	return ans;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &seg[i + (1 << sz)].sum);
		seg[i].done = (seg[i].sum <= 1);
	}
	for (int i = (1 << sz) - 1; i > 0; i--) {
		seg[i].sum = seg[2 * i].sum + seg[2 * i + 1].sum;
		seg[i].done = seg[2 * i].done & seg[2 * i + 1].done;
	}
	int q;
	scanf("%d", &q);
	while (q--) {
		int t, l, r;
		scanf("%d %d %d", &t, &l, &r);
		l--;
		r--;
		if (t == 1) {
			printf("%lld\n", query(l, r, 0, (1 << sz) - 1, 1));
		}
		else {
			update(l, r, 0, (1 << sz) - 1, 1);
		}
	}
}