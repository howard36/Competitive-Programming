#include <bits/stdc++.h>

double a[32], b[32];
int v[400005];

int main() {
    int t;
    scanf("%d", &t);
	while (t--) {
        int n;
        scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &v[i]);
		}
        for (int i = 0; i<30; i++){
            a[i] = 0;
            b[i] = 1;
        }
        for (int i = 0; i<n; i++){
            double p;
            scanf("%lf", &p);
            for (int j = 0; j<30; j++){
                if ((v[i]>>j)&1) {
					double A = p * b[j] + (1 - p) * a[j];
					double B = p * a[j] + (1 - p) * b[j];
                    a[j] = A, b[j] = B;
				}
            }
        }
        double ans = 0;
        for (int i = 0; i<30; i++){
            ans += a[i] * (1<<i);
        }
        printf("%.7lf\n", ans);
	}
}