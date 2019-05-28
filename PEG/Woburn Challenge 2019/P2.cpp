#include <bits/stdc++.h>
using namespace std;

int main() {
    int r, c;
    scanf("%d %d", &r, &c);
    if (c == 2){
        printf("SE\n");
        for (int i = 0; i<r-1; i++){
            printf("..\n");
        }
        return 0;
    }
    if (c == 3){
        printf("S..\n");
        printf(".#.\n");
        printf(".E.\n");
        for (int i = 0; i<r-c; i++){
            printf("...\n");
        }
        return 0;
    }
    for (int i = 0; i<c; i++){
        printf(".");
    }
    printf("\n");
    for (int i = 1; i<c-1; i++){
        for (int j = 0; j<c; j++){
            if (i == c-3 && j == 0){
                printf("S");
            }
            else if (i+j == c-1)
                printf("#");
            else 
                printf(".");
        }
        printf("\n");
    }
    for (int i = 0; i<c-2; i++){
        printf(".");
    }
    printf("E.\n");
	for (int i = 0; i < r - c; i++) {
		for (int i = 0; i < c; i++) {
			printf(".");
		}
		printf("\n");
    }
}