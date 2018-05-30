#include <bits/stdc++.h>
using namespace std;

int a[101];

int main(){
    int N, x, b = 0, w = 0;
    scanf("%d", &N);
    for (int i = 0; i<N/2; i++){
        scanf("%d", &a[i]);
    }
    sort(a, a+N/2);
    for (int i = 0; i<N/2; i++){
        b += abs(2*i+1 - a[i]);
        w += abs(2*i+2 - a[i]);
    }
    printf("%d", min(b, w));
}
