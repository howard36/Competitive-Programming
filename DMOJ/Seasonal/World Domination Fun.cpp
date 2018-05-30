#include <cstdio>
#include <algorithm>
using namespace std;

int h[100005];

int main()
{
	int N, M, K;
	scanf("%d%d%d", &N, &M, &K);
	for (int i = 0; i < N; ++i)
		scanf("%d", &h[i]);
	int minh = 1000000009, minidx, minidx2;
	for (int i = 0; i < N; ++i) {
		if (h[i] == minh)
			minidx2 = i;
		else if (h[i] < minh) {
			minh = h[i];
			minidx = i;
			minidx2 = i;
		}
	}
	if (K == 1) {
		if (minidx2 - minidx < M)
			printf("%d", minh + 1);
		else
			printf("%d", minh);
	}
	else if (M == 1) {
		sort(h, h + N);
		int eqmin = 0;
		while (K > 0) {
			while (h[eqmin + 1] == minh)
				++eqmin;
			if (eqmin == N - 1) {
				minh += K / N;
				K = 0;
			}
			int inc = K / (eqmin + 1);
			if (inc <= h[eqmin + 1] - h[eqmin]) {
				K = 0;
				minh += inc;
			}
			else {
				inc = h[eqmin + 1] - h[eqmin];
				minh += inc;
				K -= (eqmin + 1)*inc;
			}
		}
		printf("%d", minh);
	}
    return 0;
}