#include <bits/stdc++.h>
using namespace std;

set<int> nums;

int main() {
    int n, x;
    scanf("%d", &n);
    while (n--){
        scanf("%d", &x);
        if (x)
            nums.insert(x);
    }
    printf("%d", (int)nums.size());
}
