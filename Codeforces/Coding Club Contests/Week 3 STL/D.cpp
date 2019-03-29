#include <bits/stdc++.h>
using namespace std;
#define ps pair<string, string>

set<ps> S;

int main() {
    int n;
    scanf("%d", &n);
    string s, t;
    for (int i = 0; i<n; i++){
        cin >> s >> t;
        S.insert(ps(s, t));
    }
    printf("%d", (int)S.size());
}