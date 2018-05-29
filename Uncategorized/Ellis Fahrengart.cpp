#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#define ll long long
#define pi pair<int,int>
using namespace std;

int arr[100005];
pi temp[100005];
struct query { int l; int r; int id; ll ans; };
query queries[100005];
int N, Q, blocksize, length;
ll inversions;

int bit[100005];

inline int sum(int idx) {
	int ans = 0;
	while (idx) {
		ans += bit[idx];
		idx -= idx & -idx;
	}
	return ans;
}

inline void update(int idx, int inc) {
	for (int x = idx; x <= N; x+=x&-x) {
		bit[x] += inc;
	}
	length += inc;
}

bool Mo(query& a, query& b) {
	if (a.l / blocksize != b.l / blocksize)
		return a.l / blocksize < b.l / blocksize;
	return a.r < b.r;
}

bool id(query& a, query& b) {
	return a.id < b.id;
}

bool comp(pi& a, pi& b) {
	return a.second < b.second;
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &temp[i].first);
		temp[i].second = i+1;
	}
	sort(temp, temp + N);
	int smallval = 1, lastval = temp[0].first;
	for (int i = 0; i < N; i++) {
		if (temp[i].first > lastval)
			++smallval;
		lastval = temp[i].first;
		temp[i].first = smallval;
	}
	sort(temp, temp + N, comp);
	for (int i = 0; i < N; i++) {
		arr[i + 1] = temp[i].first;
	}

	scanf("%d", &Q);
	blocksize = max((int)(N / sqrt(2*Q)), 1);
	for (int i = 0; i < Q; i++) {
		scanf("%d %d", &queries[i].l, &queries[i].r);
		queries[i].id = i;
	}
	sort(queries, queries + Q, Mo);

	int l = 1, r = 0, prevblock = 0;
	for (int i = 0; i < Q; i++) {
		query& q = queries[i];
		if (q.l / blocksize != prevblock) {
			memset(bit, 0, sizeof bit);
			l = q.l;
			r = l - 1;
			prevblock = q.l / blocksize;
			inversions = length = 0;
		}
		while (r < q.r) {
			++r;
			update(arr[r], 1);
			inversions += length - sum(arr[r]);
		}
		while (l < q.l) {
			update(arr[l], -1);
			inversions -= sum(arr[l] - 1);
			++l;
		}
		while (l > q.l) {
			--l;
			update(arr[l], 1);
			inversions += sum(arr[l] - 1);
		}
		q.ans = inversions;
	}
	sort(queries, queries + Q, id);
	for (int i = 0; i < Q; i++) {
		printf("%lld\n", queries[i].ans);
	}
    return 0;
}