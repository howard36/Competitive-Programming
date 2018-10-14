#include <bits/stdc++.h>
using namespace std;

double a[6][21][500];
int num[6] = {4, 6, 8, 10, 12, 20};

int main() {
    for (int i = 0; i<6; i++){
        int n = num[i];
        a[i][0][0] = 1;
        for (int j = 0; j<20; j++){
            for (int k = 0; k<450; k++){
                for (int l = k+1; l<=k+n; l++){
                    a[i][j+1][l] += a[i][j][k];
                }
            }
        }
    }
    for (int i = 0; i<6; i++){
        for (int j = 0; j<=20; j++){
            for (int k = 450; k>=0; k--){
                a[i][j][k] += a[i][j][k+1];
            }
        }
    }
    int t, h, s;
    scanf("%d", &t);
    for (int test = 1; test <= t; test++){
        double best = 0;
        scanf("%d %d", &h, &s);
        for (int i = 0; i < s; i++){
            int x, y, z = 0;
            string str;
            cin >> str;
            auto idx = str.find('+');
            if (idx != string::npos){
                z = stoi(str.substr(idx+1, str.length()-idx-1));
            }
            str = str.substr(0, idx);
            idx = str.find('-');
            if (idx != string::npos){
                z = -stoi(str.substr(idx+1, str.length()-idx-1));
            }
            str = str.substr(0, idx);
            idx = str.find('d');
            x = stoi(str.substr(0, idx));
            y = stoi(str.substr(idx+1, str.length()-idx-1));
            int ii = 0;
            while (num[ii] != y)
                ii++;
            int hnew = h - z;
            double ans;
            if (hnew < 0)
                ans = 1;
            else if (hnew > 400)
                ans = 0;
            else
                ans = a[ii][x][hnew] / a[ii][x][0];
            best = max(best, ans);
        }
        printf("Case #%d: %lf\n", test, best);
    }
}