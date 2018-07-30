#include <bits/stdc++.h>
using namespace std;

double a[2003];

int main() {
    // freopen("data.txt", "r", stdin);
    int n;
    double m, orig;
    scanf("%d%lf", &n, &m);
    orig = m;
    for (int i = 0; i<2*n; i+=2){
        scanf("%lf", &a[i]);
    }
    for (int i = 1; i<2*n; i+=2){
        scanf("%lf", &a[i]);
    }
    for (int i = 2*n-1; i>=0; i--){
        if (a[i] <= 1.5){
            printf("-1\n");
            return 0;
        }
        m += m/(a[i]-1);
    }
    printf("%.10lf\n", m-orig);
}