#include <bits/stdc++.h>
using namespace std;

bool exists[5000006], covered[5000006];
int subset[22];
int n, m, a;
vector<int> checked;

void cover(int v){
    covered[v] = true;
    bool put = true;
    for (int &i : checked){
        if ((i&v) == i) // i contained in v means that complement of i containt complement of v
            return;
        else if ((i&v) == v){
            i = v;
            put = false;
        }
    }
    if (put)
        checked.push_back(v);
    memset(subset, 0, sizeof subset);
    int count = 0;
    for (int i = 0; i<n; i++){
        if ((v & (1<<i)) == 0){
            subset[count] = 1<<i;
            count++;
        }
    }
    for (int mask = 0; mask < (1<<count); mask++){
        int u = 0;
        for (int i = 0; i<count; i++){
            if (mask & (1<<i)){
                u += subset[i];
            }
        }
        if (exists[u] && !covered[u])
            cover(u);
    }
}

int main(){
    // freopen("data.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    for (int i = 0; i<m; i++){
        scanf("%d", &a);
        exists[a] = true;
        if (a == 0){
            printf("1");
            return 0;
        }
    }
    int ans = 0;
    for (int i = 0; i < (1<<n); i++){
        if (exists[i] && !covered[i]){
            ans++;
            cover(i);
        }
    }
    printf("%d", ans);
}
