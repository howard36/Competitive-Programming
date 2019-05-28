#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<ll, ll>
// #define query pair<int, pi>

// query queries[300005];
// vector<ll> prices;

struct node {
	// ll val = 0;
	ll coneCount = 0;
	ll cost = 0;
	ll lazy = 0;
} segtree[1 << 22];

void pop(int i) {
	segtree[i].coneCount += segtree[2 * i].coneCount + segtree[2 * i + 1].coneCount;
	segtree[i].cost += segtree[2 * i].cost + segtree[2 * i + 1].cost;
}

void push(int i, ll tl, ll tr) {
	ll lz = segtree[i].lazy;
	if (lz) {
        if (i < (1<<21)) {
            segtree[2 * i].lazy += lz;
            segtree[2 * i + 1].lazy += lz;
        }
		segtree[i].coneCount += lz * (tr - tl + 1);
		segtree[i].cost += lz * (tr * (tr + 1) / 2 - tl * (tl - 1) / 2);
		segtree[i].lazy = 0;
	}
}

void add(int i, int tl, int tr, ll k, ll p) {
	push(i, tl, tr);
	if (tl == tr) {
		segtree[i].coneCount += k;
		segtree[i].cost += k * p;
		return;
	}
	int mid = (tl + tr) / 2;
	if (p <= mid) {
		add(2 * i, tl, mid, k, p);
	}
	else {
		add(2 * i + 1, mid + 1, tr, k, p);
	}
	pop(i);
}

void addrange(int i, int tl, int tr, ll a, ll b) {
	push(i, tl, tr);
	if (tr < a || tl > b)
		return;
	if (tl == tr) {
		segtree[i].coneCount++;
		segtree[i].cost += tl;
		return;
	}
	if (a <= tl && tr <= b) {
		segtree[i].lazy++;
		return;
	}
	int mid = (tl + tr) / 2;
	addrange(2 * i, tl, mid, a, b);
	addrange(2 * i + 1, mid + 1, tr, a, b);
	pop(i);
}

ll buyamt(int i, int tl, int tr, ll q) {
	push(i, tl, tr);
	if (tl == tr) {
		return min(q / tl, segtree[i].coneCount);
	}
	if (q >= segtree[i].cost) {
		return segtree[i].coneCount;
	}
	int mid = (tl + tr) / 2;
	ll num = buyamt(2 * i, tl, mid, q);
	if (num == segtree[2 * i].coneCount) {
		q -= segtree[2 * i].cost;
		return num + buyamt(2 * i + 1, mid + 1, tr, q);
	}
	else {
		return num;
	}
}

ll buylow(int i, int tl, int tr, ll l) {
	push(i, tl, tr);
	if (tl == tr) {
		return tl * min(l, segtree[i].coneCount);
	}
	if (l >= segtree[i].coneCount) {
		return segtree[i].cost;
	}
	int mid = (tl + tr) / 2;
	ll cost = buylow(2 * i, tl, mid, l);
	if (cost == segtree[2 * i].cost) {
		l -= segtree[2 * i].coneCount;
		return cost + buylow(2 * i + 1, mid + 1, tr, l);
	}
	else {
		return cost;
	}
}

ll buyhigh(int i, int tl, int tr, ll l) {
	push(i, tl, tr);
	if (tl == tr) {
		return tl * min(l, segtree[i].coneCount);
	}
	if (l >= segtree[i].coneCount) {
		return segtree[i].cost;
	}
	int mid = (tl + tr) / 2;
	ll cost = buyhigh(2 * i + 1, mid + 1, tr, l);
	if (cost == segtree[2 * i + 1].cost) {
		l -= segtree[2 * i + 1].coneCount;
		return cost + buyhigh(2 * i, tl, mid, l);
	}
	else {
		return cost;
	}
}

int main() {
	freopen("data.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
        // cout << s << endl;
		if (s == "ADD") {
			ll k, p;
			scanf("%lld %lld", &k, &p);
			add(1, 0, 1 << 21, k, p);
		}
		else if (s == "ADDRANGE") {
			ll a, b;
			scanf("%lld %lld", &a, &b);
			addrange(1, 0, 1 << 21, a, b);
		}
		else if (s == "BUYAMT") {
			ll q;
			scanf("%lld", &q);
			printf("ba = %lld\n", buyamt(1, 0, 1 << 21, q));
		}
		else if (s == "BUYLOW") {
			ll l;
			scanf("%lld", &l);
			printf("bl = %lld\n", buylow(1, 0, 1 << 21, l));
		}
		else if (s == "BUYHIGH") {
			ll l;
			scanf("%lld", &l);
			printf("bh = %lld\n", buyhigh(1, 0, 1 << 21, l));
		}
		else if (s == "COST") {
            ll l;
            scanf("%lld", &l);
            printf("Cost\n");
		}
		else if (s == "NUMCONES") {
			push(1, 0, 1 << 21);
			printf("nc = %lld\n", segtree[1].coneCount);
		}
		else if (s == "TOTALCOST") {
			push(1, 0, 1 << 21);
			printf("tc = %lld\n", segtree[1].cost);
		}
	}
}