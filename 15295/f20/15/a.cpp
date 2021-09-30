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
#define dbg(x) cerr << ">>> " << #x << " = " << x << "\n";
#define _ << " _ " <<

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ld,ld> pd;
typedef complex<ld> cd;

int dp[502][502];
string s;
int m;

// interval [a, b)
int solve(int a, int b) {
    for (int i = a; i<=b; i++) {
        if (dp[a][i] && dp[i][b]) {
            dbg(a _ i _ b);
            return 1;
        }
    }
    return 0;
}

int main() { FAST
    cin >> s >> m;
    int n = s.length();
    
	for (int i = 0; i <= n; i++) {
        dp[i][i] = 1;
    }
    for (int i = 0; i<n; i++)
    for (int i = 0; i+m <= n; i++) {
        bool same = true;
        for (int j = i+1; j<i+m; j++) {
            if (s[j] != s[i])
                same = false;
        }
        if (same) {
            dbg("same" _ i);
            dp[i][i+m] = 1;
        }
    }
    for (int l = m+1; l <= n; l++) {
        for (int i = 0; i+l<=n; i++) {
            dp[i][i+l] = solve(i, i+l);
        }
    }
    if (dp[0][n]) {
        finish("Yes");
    } else {
        finish("No");
    }
}
