#include <bits/stdc++.h>
using namespace std;

set<string> S;

int main() {
    int n;
    string s;
    scanf("%d", &n);
    for (int i = 0; i<n; i++){
        cin >> s;
        if (S.find(s) == S.end()){
            printf("NO\n");
        }
        else{
            printf("YES\n");
        }
        S.insert(s);
    }
}