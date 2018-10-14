#include <bits/stdc++.h>
using namespace std;

int a[2003], b[2003], freq[26];

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    string s;
    cin >> s;
    for (int i = 0; i<n; i++){
        a[i] = s[i]-'a';
        freq[a[i]]++;
    }
    int lo = 1e9, letter = -1;
    for (int i = 0; i<26; i++){
        if (freq[i] < lo){
            lo = freq[i];
            letter = i;
        }
    }
    if (k < lo || k > n){
        printf("WRONGANSWER");
        return 0;
    }
    for (int i = 0; i<n; i++){
        b[i] = letter;
    }
    int match = lo;
    int ptr = 0;
    while (match < k){
        while (a[ptr] == b[ptr])
            ptr++;
        b[ptr] = a[ptr];
        match++;
    }
    for (int i = 0; i<n; i++){
        printf("%c", (char)(b[i]+'a'));
    }
}