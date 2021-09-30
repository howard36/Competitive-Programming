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

pi dp[100005];
int a[100005];

int main() { FAST
    string s;
    cin >> s;
    int n = s.length();
    M00(i, n) {
        if (s[i] == 'R')
            a[i] = 1;
        else
            a[i] = -1;
    }
    int M = -10, bl, br;
    M00d(i, n) {
        if (dp[i+1].f > 0) {
            dp[i].f = a[i] + dp[i+1].f;
            dp[i].s = dp[i+1].s;
        }
        else {
            dp[i].f = a[i];
            dp[i].s = i;
        }
        if (dp[i].f >= M) {
            M = dp[i].f;
            bl = i;
            br = dp[i].s;
        }
    }
    M00(i, n+1) a[i] *= -1; 
    M00d(i, n) {
        if (dp[i+1].f > 0) {
            dp[i].f = a[i] + dp[i+1].f;
            dp[i].s = dp[i+1].s;
        }
        else {
            dp[i].f = a[i];
            dp[i].s = i;
        }
        if (dp[i].f > M || (dp[i].f == M && i < bl) || (dp[i].f == M && i == bl && dp[i].s < br)) {
            M = dp[i].f;
            bl = i;
            br = dp[i].s;
        }
    }
    cout << bl+1 << " " << br+1 << endl;
}
