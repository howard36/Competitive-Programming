#include <bits/stdc++.h>
using namespace std;

double p[1000006], q[1000006];

int main() {
	FILE *fin = fopen("cowdate.in", "r");
	FILE *fout = fopen("cowdate.out", "w");
	int n;
	fscanf(fin, "%d", &n);
	for (int i = 1; i <= n; i++) {
		int a;
		fscanf(fin, "%d", &a);
		if (a == 1e6) {
			fprintf(fout, "1\n");
			return 0;
		}
		p[i] = (double)a / 1e6;
		q[i] = 1 - p[i];
	}
	int r = 1;
	double prod = 1, sum = 0; // interval [l, r)
	double best = 0;
	for (int l = 1; l <= n; l++) {
		while (sum < 1 && r <= n) {
			sum += p[r] / q[r];
			prod *= q[r];
			r++;
		}
		// printf("best l = %d, r = %d, prob = %lf\n", l, r, prod * sum);
		best = max(best, prod * sum);
		sum -= p[l] / q[l];
		prod /= q[l];
	}
	fprintf(fout, "%d", (int)floor(1e6 * best));
}