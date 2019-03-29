#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();
    for (int i = 0; i<n; i++){
        if (s[i] == '0'){
            cout << s.substr(0, i) << s.substr(i+1, n-(i+1));
            return 0;
        }
    }
    cout << s.substr(0, n-1);
}