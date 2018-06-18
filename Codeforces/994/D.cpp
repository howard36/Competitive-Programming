#include <bits/stdc++.h>
using namespace std;
#define pi pair<int,int>

pi one[12], two[12];
bool possible[10], p1[10], p2[10];

int match(pi o, pi t){
    int common = 0;
    if (o.first == t.first)
        common = o.first;
    if (o.first == t.second)
        common = o.first;
    if (o.second == t.first)
        common = o.second;
    if (o.second == t.second)
        common = o.second;
    return common;
}

int main() {
    freopen("data.txt", "r", stdin);
    // printf("%d\n", match(pi(1,2), pi(1,5)));
    int n, m;
    int a, b;
    scanf("%d%d", &n, &m);
    for (int i = 0; i<n; i++){
        scanf("%d %d", &a, &b);
        if (a > b)
            swap(a, b);
        one[i] = pi(a,b);
    }
    for (int i = 0; i<m; i++){
        scanf("%d %d", &a, &b);
        if (a > b)
            swap(a, b);
        two[i] = pi(a,b);
    }
    for (int i = 0; i<n; i++){
        for (int j = 0; j<m; j++){
            pi o = one[i];
            pi t = two[j];
            if (o == t)
                continue;
            int common = match(o, t);
            if (common == 0)
                continue;
            possible[common] = true;
        }
    }
    int count = 0;
    for (int i = 1; i<10; i++){
        if (possible[i]){
            // printf("%d ", i);
            count++;
        }
    }
    if (count == 1){
        for (int i = 1; i<10; i++){
            if (possible[i])
                printf("%d\n", i);
        }
        return 0;
    }
    for (int i = 0; i<n; i++){
        memset(p1, 0, sizeof(p1));
        for (int j = 0; j<m; j++){
            pi o = one[i];
            pi t = two[j];
            if (o == t)
                continue;
            int common = match(o, t);
            if (common == 0)
                continue;
            p1[common] = true;
        }
        count = 0;
        for (int i = 1; i<10; i++){
            if (p1[i])
                count++;
        }
        if (count > 1){
            printf("-1");
            return 0;
        }
    }
    for (int j = 0; j<m; j++){
        memset(p2, 0, sizeof(p2));
        for (int i = 0; i<n; i++){
            pi o = one[i];
            pi t = two[j];
            if (o == t)
                continue;
            int common = match(o, t);
            if (common == 0)
                continue;
            p2[common] = true;
        }
        count = 0;
        for (int i = 1; i<10; i++){
            if (p2[i])
                count++;
        }
        if (count > 1){
            printf("-1");
            return 0;
        }
    }
    printf("0");
}
