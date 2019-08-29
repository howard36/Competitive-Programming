#include <bits/stdc++.h>
using namespace std;

int a[200005], b[200005], last[30];
int c = 0;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if (a[i] <= i) {
			printf("-1");
			return 0;
		}
	}
    memset(last, -1, sizeof last);
	for (int i = n - 1; i >= 0; i--) {
		if (a[i] == n + 1) {
			b[i] = c;
            last[c] = i;
            c++;
        }
		else if (last[b[a[i]-1]] == a[i]-1) {
			b[i] = b[a[i] - 1];
			last[b[i]] = i;
		}
		else {
			printf("-1");
			return 0;
		}
	}
	if (c > 26)
		printf("-1");
	else {
		for (int i = 0; i < n; i++)
			printf("%c", 'a' + b[i]);
	}
}