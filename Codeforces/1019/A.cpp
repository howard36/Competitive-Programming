#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> votes[3003];

int main() {
    // freopen("data.txt", "r", stdin);
    int n, m, p;
    ll c;
    scanf("%d %d", &n, &m);
    // printf("n = %d, m = %d\n", n, m);
    for (int i = 0; i < n; i++) {
        scanf("%d %lld", &p, &c);
        // printf("p = %d, c = %lld\n", p, c);
        votes[p].push_back(c);
    }
    for (int i = 1; i <= m; i++) {
        sort(votes[i].begin(), votes[i].end());
    }
    ll best = 1e18;
    for (int i = max(1, (int)votes[1].size()); i <= n; i++) {
        ll cost = 0;
        int voters = votes[1].size();
        for (int j = 2; j <= m; j++) {
            for (int k = 0; k < (int)votes[j].size() - i + 1; k++) {
                cost += votes[j][k];
                voters++;
                // printf("Converted %d %lld\n", j, votes[j][k]);
            }
        }
        // printf("%d\n", voters);
        if (voters < i) {
            // printf("%d voters not enough\n", voters);
            vector<ll> consider;
            for (int j = 2; j <= m; j++) {
                for (int k = max(0, (int)votes[j].size() - i + 1); k < votes[j].size(); k++) {
                    consider.push_back(votes[j][k]);
                // printf("Considering %d %lld\n", j, votes[j][k]);
                }
            }
            sort(consider.begin(), consider.end());
            for (int j = 0; j < i - voters; j++){
                cost += consider[j];
            }
        }
        best = min(best, cost);
        // printf("i = %d, cost = %lld\n", i, cost);
    }
    printf("%lld\n", best);
}