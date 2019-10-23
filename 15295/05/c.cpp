#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int, int>
#define cd complex<double>

cd a[202];
int n;

double check(cd o) {
	double ans = 0;
	for (int i = 0; i<n; i++) {
		ans = max(ans, abs(o-a[i]));
	}
	return ans;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i<n; i++) {
		double rl, im;
		scanf("%lf %lf", &rl, &im);
		a[i] = cd(rl, im);
	}
	if (n == 1) {
		printf("0\n");
		return 0;
	}
	double ans = 1e9;
	for (int i = 0; i<n; i++) {
		for (int j = i+1; j<n; j++) {
			cd o = (a[i]+a[j])/2.0;
			double r = abs(o - a[i]);
			bool works = true;
			if (r < ans) {
				for (int l = 0; l<n; l++) {
					if (abs(a[l] - o) > r + 1e-7) {
						works = false;
						break;
					}
				}
				if (works)
					ans = r;
			}
			for (int k = j+1; k<n; k++) {
				cd b = a[j]-a[i], c = a[k]-a[i];
				if (abs(b*conj(c) - c*conj(b)) < 1e-7)
					continue;
				if (a[i] == a[j] || a[j] == a[k] || a[k] == a[i])
					continue;
				cd o = a[i] + (b*norm(c) - c*norm(b))/(b*conj(c)-c*conj(b));
				r = abs(o - a[i]);
				if (r < ans) {
					works = true;
					for (int l = 0; l<n; l++) {
						if (abs(a[l] - o) > r + 1e-7) {
							works = false;
							break;
						}
					}
					if (works)
						ans = r;
				}
			}
		}
	}
	printf("%.10lf", ans);
}
