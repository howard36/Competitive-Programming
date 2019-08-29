#include <bits/stdc++.h>
using namespace std;

map<int, int> pos[5];
int a[20004];

bool comp(int x, int y) {
    int cnt = 0;
    for (int i = 0; i<5; i++) {
        if (pos[i][x] < pos[i][y])
            cnt++;
    }
    return cnt > 2;
}

int main() {
    int n, id;
    scanf("%d", &n);
    for (int i = 0; i<5; i++) {
        for (int j = 0; j<n; j++) {
            scanf("%d", &id);
            pos[i][id] = j;
            a[j] = id;
        }
    }
    sort(a, a+n, comp);
    for (int i = 0; i<n; i++)
        printf("%d\n", a[i]);
}