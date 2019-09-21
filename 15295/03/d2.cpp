#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int, int>

double dp[102][102][102][3];

int main() {
	ll R, S, P;
	scanf("%lld %lld %lld", &R, &S, &P);
	for (ll sum = 1; sum <= R + S + P; sum++) {
		for (ll r = 0; r <= min(R,sum); r++) {
			for (ll s = 0; s <= min(S, sum-r); s++) {
				ll p = sum - r - s;
				if (r == sum) {
					dp[r][p][s][0] = 1;
					continue;
				}
				if (p == sum) {
					dp[r][p][s][1] = 1;
					continue;
				}
				if (s == sum) {
					dp[r][p][s][2] = 1;
					continue;
				}
				double rp = 1.0*r*p/(r*p + p*s + s*r);
				double ps = 1.0*p*s/(r*p + p*s + s*r);
				double sr = 1.0*s*r/(r*p + p*s + s*r);
				for (int i = 0; i<3; i++) {
					if (r)
						dp[r][p][s][i] += rp*dp[r-1][p][s][i];
					if (p)
						dp[r][p][s][i] += ps*dp[r][p-1][s][i];
					if (s)	
						dp[r][p][s][i] += sr*dp[r][p][s-1][i];
				}
		//		printf("dp[%lld][%lld][%lld] = %lf %lf %lf\n", r, p, s, dp[r][p][s][0], dp[r][p][s][1], dp[r][p][s][2]);
			}
		}
		//printf("Done sum = %lld\n", sum);
	}
	printf("%.10lf %.10lf %.10lf\n", dp[R][P][S][0], dp[R][P][S][2], dp[R][P][S][1]);
}
