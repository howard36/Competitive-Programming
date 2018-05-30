#include <cstdio>
#define ll long long

ll price[5003][5003];
//pi changes[5003];

int main()
{
	int N, M, Q, a, l, r;
	ll p, x;
	scanf("%d%d%d", &N, &M, &Q);
	for (int i = 1; i <= N; i++)
		scanf("%lld", &price[i][0]);
	for (int i = 1; i <= M; i++) {
		scanf("%d%lld", &a, &p);
		for (int j = 1; j <= N; j++)
			price[j][i] = price[j][i - 1];
		price[a][i] = p;
	}
	for (int i = 0; i < Q; i++) {
		scanf("%d%d%lld", &l, &r, &x);
		int t = 0;
		for (; t<=M; t++) {
			bool works = true;
			for (int j = l; j <= r; j++) {
				if (price[j][t] % x != 0) {
					works = false;
					break;
				}
			}
			if (works)
				break;
		}
		if (t == M+1)
			printf("-1\n");
		else
			printf("%d\n", t);
	}
    return 0;
}