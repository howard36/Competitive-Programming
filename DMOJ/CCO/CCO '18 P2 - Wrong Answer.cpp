#include <bits/stdc++.h>

int A[101][101];

using namespace std;

int main() {
    A[1][2] = 1;
    A[1][3] = 1;
    for (int i = 3; i < 100; i+=2){
        A[i-1][i] = 1;
        A[i][i+1] = 99;
        A[i-2][i+1] = 1;
    }
    printf("100\n");
    for (int i = 1; i <= 100; i++){
        for (int j = i+1; j <= 100; j++){
            if (A[i][j])
                printf("%d ", A[i][j]);
            else
                printf("100 ");
        }
        printf("\n");
    }
    return 0;
}