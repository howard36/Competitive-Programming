#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int, int>

double dp[302][102][102][3];

int main() {
	int R, S, P;
	scanf("%d %d %d", &R, &S, &P);
	for (ll sum = 1; sum <= R + S + P; sum++) {
		for (ll r = 0; r <= sum; r++) {
			for (ll s = 0; s <= sum-r; s++) {
				ll p = sum - r - s;
				int r0 = r%2, r1 = (r+1)%2;
				int p0 = p%2, p1 = (p+1)%2;
				int s0 = s%2, s1 = (s+1)%2;
				for (int i = 0; i<3; i++)
					dp[][s][p][i] = 0
				if (r == sum) {
					dp[r0][p0][s0][0] = 1;
					continue;
				}
				if (p == sum) {
					dp[r0][p0][s0][1] = 1;
					continue;
				}
				if (s == sum) {
					dp[r0][p0][s0][2] = 1;
					continue;
				}
				double rp = 1.0*r*p/(r*p + p*s + s*r);
				double ps = 1.0*p*s/(r*p + p*s + s*r);
				double sr = 1.0*s*r/(r*p + p*s + s*r);
				for (int i = 0; i<3; i++) {
					if (r)
						dp[r0][p0][s0][i] += rp*dp[r1][p0][s0][i];
					if (p)
						dp[r0][p0][s0][i] += ps*dp[r0][p1][s0][i];
					if (s)	
						dp[r0][p0][s0][i] += sr*dp[r0][p0][s1][i];
				}
		//		printf("dp[%lld][%lld][%lld] = %lf %lf %lf\n", r, p, s, dp[r][p][s][0], dp[r][p][s][1], dp[r][p][s][2]);
			}
		}
		//printf("Done sum = %lld\n", sum);
	}
	printf("%.10lf %.10lf %.10lf\n", dp[R][P][S][0], dp[R][P][S][2], dp[R][P][S][1]);
}
