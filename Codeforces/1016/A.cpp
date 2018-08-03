#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll N, M, sum = 0, a;
    scanf("%lld %lld", &N, &M);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &a);
        sum += a;
        printf("%lld\n", sum / M);
        sum %= M;
    }
}