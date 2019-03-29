#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll h[1003], s[1003];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i<n; i++){
        scanf("%lld %lld", &h[i], &s[i]);
    }
    ll minTime = 1e18;
    for (int i = 0; i<n; i++){
        for (int j = i+1; j<n; j++){
            if (s[i] == s[j]){
                if (h[i] == h[j]){
                    printf("0");
                    return 0;
                }
            }
            else{
                if (abs(h[i]-h[j]) % abs(s[i]-s[j]) == 0){
                    ll t = (h[j]-h[i]) / (s[i]-s[j]);
                    if (t > 0){
                        minTime = min(minTime, t);
                    }
                }
            }
        }
    }
    if (minTime == 1e18){
        minTime = -1;
    }
    printf("%lld", minTime);
}