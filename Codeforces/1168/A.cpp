#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int, int>

int n, m;
int a[300005], b[300005];

bool check(int s) {
	for (int i = 0; i < n; i++) {
		b[i] = (a[i] + s) % m;
	}
    int last = 0;
    for (int i = 0; i<n; i++) {
        if (b[i] >= a[i]) {
            if (b[i] < last)
                return false;
            last = max(last, a[i]);
        }
        else {
            if (b[i] < last) {
                last = max(last, a[i]);
            }
        }
    }
    return true;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	int lo = 0, hi = m;
	while (lo < hi) {
		int mid = (lo + hi) / 2;
		if (check(mid)) {
			hi = mid;
		}
		else {
			lo = mid + 1;
		}
	}
    printf("%d", lo);
}