#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()
#define sz(v) (int)v.size()

#define MOO(i, a, b) for(int i=a; i<b; i++)
#define M00(i, a) for(int i=0; i<a; i++)
#define MOOd(i,a,b) for(int i = (b)-1; i >= a; i--)
#define M00d(i,a) for(int i = (a)-1; i>=0; i--)

#define FAST ios::sync_with_stdio(0); cin.tie(0);
#define finish(x) return cout << x << '\n', 0;
#define dbg(x) // cerr << ">>> " << #x << " = " << x << "\n";
#define _ << " _ " <<

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ld,ld> pd;
typedef complex<ld> cd;

char a[10][10];
bool dp[100][10][10][3][3][102];

int main() { FAST
	int r, c;
    cin >> r >> c;
    for (int i = 0; i<r; i++)
        for (int j = 0; j<c; j++)
            cin >> a[i][j];
    int k;
    cin >> k;
    string s;
    cin >> s;
    int n = s.length();
    if (k < 0 || k >= n) {
        finish("No");
    }

    for (int i = 0; i<r; i++)
        for (int j = 0; j<c; j++)
            if (a[i][j] == s[0])
                dp[0][i][j][1][1][0] = 1;
    for (int idx = 1; idx < n; idx++) {
        char chr = s[idx];
        for (int i = 0; i<r; i++) {
            for (int j = 0; j<c; j++) {
                if (a[i][j] == chr) {
                    for (int di = 0; di<3; di++) {
                        for (int dj = 0; dj<3; dj++) {
                            int ni = i+di-1;
                            int nj = j+dj-1;
                            if (ni < 0 || nj < 0 || ni >= r || nj >= c)
                                continue;
                            if (di == 1 && dj == 1)
                                continue;
                            if (idx == 1) {
                                dp[idx][i][j][di][dj][0] |= dp[idx-1][ni][nj][1][1][0];
                            } else {
                                for (int kk = 0; kk<=k; kk++)
                                    dp[idx][i][j][di][dj][kk] |= dp[idx-1][ni][nj][di][dj][kk];
                                for (int ii = 0; ii<3; ii++) {
                                    for (int jj = 0; jj<3; jj++) {
                                        if (ii == 1 && jj == 1)
                                            continue;
                                        if (ii == di && jj == dj)
                                            continue;
                                        for (int kk = 0; kk<k; kk++)
                                            dp[idx][i][j][di][dj][kk+1] |= dp[idx-1][ni][nj][ii][jj][kk];
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    bool ans = false;
    for (int i = 0; i<r; i++)
        for (int j = 0; j<c; j++)
            for (int di = 0; di<3; di++)
                for (int dj = 0; dj<3; dj++) {
                    ans |= dp[n-1][i][j][di][dj][k];
                }

    for (int idx = 0; idx<n; idx++)
        for (int i = 0; i<r; i++)
            for (int j = 0; j<c; j++)
                for (int di = 0; di<3; di++)
                    for (int dj = 0; dj<3; dj++)
                        for (int kk = 0; kk<=k; kk++)
                            if (dp[idx][i][j][di][dj][kk]) {
                                dbg(idx _ i _ j _ di _ dj _ kk);
                            }

    if (ans)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
