#include <bits/stdc++.h>
using namespace std;

string s[300005];

struct node {
    int next[26];
    int cnt;
} trie[400005];

int main() {
    int n;
    scanf("%d", &n);
    string S = "";
    for (int i = 0; i<n; i++) {
        cin >> s[i];
        S += s[i];
    }
    int N = S.length();
    for (int i = 0; i<N; i++){

    }
}