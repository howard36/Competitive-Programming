#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

int arr[100005], freq[100005], ans[100005];
struct query { int l; int r; int id; };
query queries[100005];
int N, Q, sz;

bool comp(query a, query b) {
	if (a.l / sz == b.l / sz)
		return a.r < b.r;
	return a.l < b.l;
}

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
	}
	scanf("%d", &Q);
	sz = max(N / sqrt(2 * Q), 1.0);
	for (int i = 0; i < Q; i++) {
		scanf("%d%d", &queries[i].l, &queries[i].r);
		queries[i].id = i;
	}
	sort(queries, queries + Q, comp);
	int l = 1, r = 0, even = 0, last = 0;
	for (int i = 0; i < Q; i++) {
		query q = queries[i];
		if (q.l / sz != last) {
			last = q.l / sz;
			l = sz * last + 1;
			r = l - 1;
			memset(freq, 0, sizeof freq);
			even = 0;
		}
		while (r < q.r) {
			r++;
			freq[arr[r]]++;
			if (freq[arr[r]] % 2 == 0)
				even++;
			else if (freq[arr[r]] != 1)
				even--;
		}
		while (l < q.l) {
			freq[arr[l]]--;
			if (freq[arr[l]] % 2 == 0 && freq[arr[l]])
				even++;
			else if (freq[arr[l]])
				even--;
			l++;
		}
		while (l > q.l) {
			l--;
			freq[arr[l]]++;
			if (freq[arr[l]] % 2 == 0)
				even++;
			else if (freq[arr[l]] != 1)
				even--;
		}
		ans[q.id] = even;
	}
	for (int i = 0; i < Q; i++) {
		printf("%d\n", ans[i]);
	}
    return 0;
}