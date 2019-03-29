#include <bits/stdc++.h>
using namespace std;

int a[100005];

int main() {
    string s;
    cin >> s;
    int n = s.length();
    for (int i = 1; i<n; i++){
        a[i] = a[i-1] + (int)(s[i] == s[i-1]);
    }
    int q;
    scanf("%d", &q);
    while (q--){
        int l, r;
        scanf("%d %d", &l, &r);
        printf("%d\n", a[r-1] - a[l-1]);
    }
}