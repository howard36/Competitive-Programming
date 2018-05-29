#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#define pb push_back
#define ll long long
using namespace std;

struct corner { int x; int y; int change; int around = 0; };
corner corners[800005];
int bit[500005];
set<ll> good;

inline int sum(int x) {
	int ans = 0;
	for (; x; x -= x & -x)
		ans += bit[x];
	return ans;
}

inline void upd(int x, int inc) {
	for (; x < 500005; x += x & -x)
		bit[x] += inc;
}

inline bool comp(corner& a, corner& b) {
	return a.x < b.x;
}

int main()
{
	int N, p, q, r, s;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d%d%d%d", &p, &q, &r, &s);
		corners[4 * i] = corner{ p, q, 1, 0 };
		corners[4 * i + 1] = corner{ r, q, -1, 0 };
		corners[4 * i + 2] = corner{ p, s, -1, 0 };
		corners[4 * i + 3] = corner{ r, s, 1, 0 };
	}
	sort(corners, corners + 4 * N, comp);

	int prevx = 0;
	vector<corner> col;
	for (int i = 0; i < 4 * N; i++) {
		if (corners[i].x == prevx) {
			col.pb(corners[i]);
		}
		else {
			for (int j = 0; j < col.size(); j++) {
				if (sum(col[j].y))
					++col[j].around;
				if (sum(col[j].y - 1))
					++col[j].around;
			}
			for (int j = 0; j < col.size(); j++) {
				upd(col[j].y, col[j].change);
			}
			for (int j = 0; j < col.size(); j++) {
				if (sum(col[j].y))
					++col[j].around;
				if (sum(col[j].y - 1))
					++col[j].around;
				if (col[j].around == 1)
					good.insert(col[j].x * 500000LL + col[j].y);
			}

			col.clear();
			col.pb(corners[i]);
			prevx = corners[i].x;
		}
	}
	// last column
	for (int j = 0; j < col.size(); j++) {
		if (sum(col[j].y))
			++col[j].around;
		if (sum(col[j].y - 1))
			++col[j].around;
	}
	for (int j = 0; j < col.size(); j++) {
		upd(col[j].y, col[j].change);
	}
	for (int j = 0; j < col.size(); j++) {
		if (sum(col[j].y))
			++col[j].around;
		if (sum(col[j].y - 1))
			++col[j].around;
		if (col[j].around == 1)
			good.insert(col[j].x * 500000LL + col[j].y);
	}

	printf("%d", good.size());
    return 0;
}