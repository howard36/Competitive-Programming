#include <bits/stdc++.h>
using namespace std;

int X[6], Y[6], S[6], D[6];

int main() {
    // freopen("data.txt", "r", stdin);
    int x, y, xhi, yhi, sumhi, diffhi, xlo, ylo, sumlo, difflo;
    xhi = yhi = sumhi = diffhi = -1e9, xlo = ylo = sumlo = difflo = 1e9;
    for (int i = 0; i<4; i++){
        scanf("%d%d", &x, &y);
        xhi = max(xhi, x);
        xlo = min(xlo, x);
        yhi = max(yhi, y);
        ylo = min(ylo, y);
        S[i] = x+y;
        D[i] = x-y;
    }
    int xhi2 = xhi, xlo2 = xlo, yhi2 = yhi, ylo2 = ylo;
    S[4] = S[5] = xhi + ylo;
    D[4] = D[5] = xhi - yhi;
    xhi = yhi = sumhi = diffhi = -1e9, xlo = ylo = sumlo = difflo = 1e9;
    for (int i = 0; i<4; i++){
        scanf("%d%d", &x, &y);
        xhi = max(xhi, x);
        xlo = min(xlo, x);
        yhi = max(yhi, y);
        ylo = min(ylo, y);
        int sum = x+y, diff = x-y;
        sumhi = max(sumhi, sum);
        sumlo = min(sumlo, sum);
        diffhi = max(diffhi, diff);
        difflo = min(difflo, diff);
        X[i] = x;
        Y[i] = y;
    }
    X[4] = (xhi + xlo)/2;
    X[5] = (xhi + xlo + 1)/2;
    Y[4] = (yhi + ylo)/2;
    Y[5] = (yhi + ylo + 1)/2;

    bool intersect = false;
    for (int i = 0; i<6; i++){
        if (X[i] >= xlo2 && X[i] <= xhi2 && Y[i] >= ylo2 && Y[i] <= yhi2){
            intersect = true;
            // printf("1 %d\n", i);
        }
        if (S[i] >= sumlo && S[i] <= sumhi && D[i] >= difflo && D[i] <= diffhi) {
            intersect = true;
            // printf("2 %d\n", i);
        }
    }
    if (intersect)
        printf("Yes");
    else
        printf("No");
}
