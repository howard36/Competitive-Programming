#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    long long a, b;
    scanf("%d", &n);
    while (n--){
        scanf("%lld %lld", &a, &b);
        if (abs(a-b) <= 1000000000LL)
            printf("%lld\n", a-b);
        else
            printf("%lld\n", a+b);
    }
    return 0;
}