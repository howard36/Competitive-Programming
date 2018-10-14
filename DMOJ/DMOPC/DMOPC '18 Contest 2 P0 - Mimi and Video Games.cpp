#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, a, r;
    scanf("%d %d %d", &n, &a, &r);
    printf("%d", min(n, r/a));
    return 0;
}