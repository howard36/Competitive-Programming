#include <bits/stdc++.h>
using namespace std;
#define pi pair<int, int>

int grid[9][9], r[9], c[9], s[9];
vector<pi> pos[10];

int main() {
    char cc;
    for (int i = 0; i<9; i++){
        for (int j = 0; j<9; j++){
            scanf(" %c", &cc);
            if (cc == '.')
                grid[i][j] = 0;
            else {
                grid[i][j] = cc - '0';
                pos[cc-'0'].push_back(pi(i, j));
            }
        }
    }
    for (int num = 1; num <= 9; num++){
        memset(r, 0, sizeof(r));
        memset(c, 0, sizeof(c));
        memset(s, 0, sizeof(s));
        for (int i = 0; i<9; i++){
            for (int j = 0; j<9; j++){
                if (grid[i][j] == num) {
                    r[i]++;
                    c[j]++;
                    s[3*(i/3)+j/3]++;
                }
            }
        }
        for (int i = 0; i<9; i++){
            if (r[i] > 1 || c[i] > 1 || s[i] > 1){
                printf("ERROR");
                return 0;
            }
        }
    }
    int cnt = 0, num = 1;
    while (cnt < 9){
        cnt++;
        memset(r, 0, sizeof(r));
        memset(c, 0, sizeof(c));
        for (pi p : pos[num]){
            r[p.first] = 1;
            c[p.second] = 1;
        }
        for (int i = 0; i < 3; i++){
            for (int j = 0; j<3; j++){
                int good = 0, numCount = 0;
                for (int k = 0; k<3; k++){
                    for (int l = 0; l<3; l++){
                        if (grid[3*i+k][3*j+l] == 0 && r[3*i+k] == 0 && c[3*j+l] == 0)
                            good++;
                        if (grid[3*i+k][3*j+l] == num)
                            numCount++;
                    }
                }
                if (numCount)
                    continue;
                if (good == 1){
                    for (int k = 0; k<3; k++){
                        for (int l = 0; l<3; l++){
                            if (grid[3*i+k][3*j+l] == 0 && r[3*i+k] == 0 && c[3*j+l] == 0) {
                                grid[3*i+k][3*j+l] = num;
                                pos[num].push_back(pi(3*i+k, 3*j+l));
                            }
                        }
                    }
                    cnt = 0;
                }
                if (good == 0){
                    printf("ERROR");
                    return 0;
                }
            }
        }
        num = num%9 + 1;
    }
    for (int i = 0; i<9; i++){
        for (int j = 0; j<9; j++){
            if (grid[i][j] == 0)
                printf(".");
            else
                printf("%c", (char)(grid[i][j]+'0'));
        }
        printf("\n");
    }
}