#include <bits/stdc++.h>
using namespace std;

int best[100];

int main() {
    string s;
    cin >> s;
    int n = s.length();
    int top = 0;
    for (int i = 0; i<n; i++){
        int hi = 0;
        for (int j = 0; j<i; j++){
            if (s[j] < s[i])
                hi = max(hi, best[j]);
        }
        best[i] = hi + 1;
        top = max(top, best[i]);
    }
    printf("%d", 26-top);
}