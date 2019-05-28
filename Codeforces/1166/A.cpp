#include <bits/stdc++.h>
using namespace std;

int a[27];

int main() {
    int n;
    scanf("%d", &n);
    string s;
    for (int i = 0; i<n; i++){
        cin >> s;
        a[s[0]-'a']++;
    }
    int ans = 0;
    for (int i = 0; i<26; i++){
        int x = a[i]/2;
        int y = a[i]-x;
        ans += x*(x-1)/2 + y*(y-1)/2;
    }
    printf("%d", ans);
}