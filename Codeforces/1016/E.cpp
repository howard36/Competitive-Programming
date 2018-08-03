#include <bits/stdc++.h>
using namespace std;

double x[400005], l[200005], pre[200005];

int main() {
    // freopen("data.txt", "r", stdin);
    double s, a, b;
    scanf("%lf %lf %lf", &s, &a, &b);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < 2 * n; i++) {
        scanf("%lf", &x[i]);
    }
    for (int i = 1; i <= n; i++) {
        l[i] = x[2 * i - 1] - x[2 * i - 2];
        pre[i] = pre[i - 1] + l[i];
    }
    int q;
    double xq, yq;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%lf %lf", &xq, &yq);
        double xl = (double)(a - xq) * yq / (yq - s) + xq;
        double xr = (double)(b - xq) * yq / (yq - s) + xq;
        int il = upper_bound(x, x + 2 * n, xl) - x;
        int ir = upper_bound(x, x + 2 * n, xr) - x - 1;
        // printf("i = %d, xl = %lf, xr = %lf, il = %d, ir = %d, a = %lf, b = %lf, s = %lf, xq = %lf, yq = %lf\n", i, xl, xr, il, ir, a, b, s, xq, yq);
        double length = 0;
        if (ir < il) {
            if (ir % 2 == 0)
                printf("%.10lf\n", (double)(b - a)); // in the same interval
            else
                printf("%.10lf\n", 0); // in the same gap
            continue;
        }
        if (il % 2 == 1) { // left in interval
            length += x[il] - xl;
        }
        if (ir % 2 == 0) { // right in interval
            length += xr - x[ir];
        }
        length += pre[(ir + 1) / 2] - pre[(il + 1) / 2];
        // printf("length = %lf\n", length);
        printf("%.10lf\n", length * (yq - s) / yq);
    }
}