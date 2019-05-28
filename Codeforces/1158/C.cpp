#include <bits/stdc++.h>
using namespace std;

int a[500005], p[500005];

bool solve(int l, int r, int s){
    // printf("Calling solve(%d, %d, %d)\n", l, r, s);
    if (l == r)
        return true;
    if (a[l] > r)
        return false;
    if (a[l] == -1)
        a[l] = r;
    p[l] = a[l] - l + s;
    // printf("p[%d] = %d\n", l, p[l]);
    if (!solve(l+1, a[l], s))
        return false;
    if (!solve(a[l], r, p[l]))
        return false;
    return true;
}

int main() {
    // freopen("data.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    while (t--){
        int n;
		scanf("%d", &n);
        // printf("n=%d\n", n);
		for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
		}
        if (solve(1, n+1, 0)) {
            // printf("Good!\n");
            for (int i = 1; i<=n; i++){
                printf("%d ", p[i]);
            }
            printf("\n");
        }
        else {
            printf("-1\n");
        }
	}
}