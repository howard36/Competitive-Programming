#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll w[20], val[5000], freq[5000], sum[5000][102];

int main() {
    freopen("data.txt", "r", stdin);
    auto start = chrono::high_resolution_clock::now();
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);
    for (int i = n - 1; i >= 0; i--)
        scanf("%lld", &w[i]);
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            if ((i >> j) & 1)
                val[i] += w[j];
        }
    }
    for (int i = 0; i < m; i++) {
        int a = 0;
        char c;
        for (int j = 0; j < n; j++) {
            scanf(" %c", &c);
            a = 2 * a + (int)(c == '1');
        }
        freq[a]++;
    }
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < (1 << n); j++) {
            ll changed = val[i ^ j];
            if (changed <= 100)
                sum[i][changed] += freq[j];
        }
        for (int j = 1; j<=100; j++){
            sum[i][j] += sum[i][j-1];
        }
    }
    for (int i = 0; i < q; i++) {
        int a = 0, k;
        char c;
        for (int j = 0; j < n; j++) {
            scanf(" %c", &c);
            a = 2 * a + (int)(c == '1');
        }
        a ^= (1<<n)-1;
        scanf("%d", &k);
        printf("%lld\n", sum[a][k]);
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    cout << "Solved in " << duration.count() << " seconds\n";
}
