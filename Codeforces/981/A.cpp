#include <bits/stdc++.h>
using namespace std;

bool palindrome(string s){
    int n = s.length();
    for (int i = 0; i<n; i++){
        if (s[i] != s[n-i-1])
            return false;
    }
    return true;
}

int main(){
    string s;
    cin >> s;
    int n = s.length();
    for (int i = n; i>0; i--){
        for (int j = 0; j+i<=n; j++){
            if (!palindrome(s.substr(j, i))){
                printf("%d\n", i);
                return 0;
            }
        }
    }
    printf("0\n");
}
