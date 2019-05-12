#include <bits/stdc++.h>
using namespace std;

int a[1003];

int main() {
    string s;
    cin >> s;
    int n = s.length();
    for (int i = 0; i<n; i++){
        if (s[i] == '?')
            a[n-i-1] = -1;
        else 
            a[n-i-1] = s[i]-'0';
    }
    for (int m = 1; m < n; m++){
        for (int i = 0; i < (m+1)/2; i++){
            
        }
    }
}