#include <bits/stdc++.h>
using namespace std;

int freq[150004];
int bit[320004];

void update(int i){
    for (; i<32004; i+=(i&-i)){
        bit[i]++;
    }
}

int query(int i){
    int ans = 0;
    for (; i>0; i-=(i&-i)){
        ans += bit[i];
    }
    return ans;
}

int main() {
    int n, x, y;
    scanf("%d", &n);
    for (int i = 0; i<n; i++){
        scanf("%d %d", &x, &y);
        freq[query(x+1)]++;
        update(x+1);
    }
    for (int i = 0; i<n; i++){
        printf("%d\n", freq[i]);
    }
}