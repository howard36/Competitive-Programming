#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();
    int h = 0, v = 0;
    for (int i = 0; i<n; i++){
        if (s[i] == 'H'){
            h ^= 1;
        }
        else {
            v ^= 1;
        }
    }
    if (h){
        if (v) {
            printf("4 3\n2 1");
        }
        else {
            printf("3 4\n1 2");
        }
    }
    else {
        if (v) {
            printf("2 1\n4 3");
        }
        else {
            printf("1 2\n3 4");
        }
    }
}