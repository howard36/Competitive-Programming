#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()
#define sz(v) (int)v.size()

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

int freq[100005][3];
vi need[3][3];
char chr[3] = {'w', 'i', 'n'};
vector<pair<pi,pi>> sol;

void ans(int a, int j, int b, int i) {
    sol.pb(mp(pi(a,j), pi(b,i)));
}

void print(pair<pi,pi> p) {
    int a = p.f.f, j = p.f.s, b = p.s.f, i = p.s.s;
    cout << a+1 << " " << chr[j] << " " << b+1 << " " << chr[i] << endl;
}

void solve() {
    int n;
    cin >> n;
    sol.clear();
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            need[i][j].clear();
        }
    }
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < 3; j++) {
            freq[i][j] = 0;
        }
        for (int j = 0; j < 3; j++) {
            if (s[j] == 'w') freq[i][0]++;
            if (s[j] == 'i') freq[i][1]++;
            if (s[j] == 'n') freq[i][2]++;
        }
        int extra = -1;
        for (int j = 0; j < 3; j++) {
            if (freq[i][j] > 1) extra = j;
        }
        if (extra != -1) {
            for (int j = 0; j < 3; j++) {
                if (freq[i][j] == 0) {
                    need[j][extra].pb(i);
                    // dbg(i _ " has " _ extra _ " need " _ j)
                }
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = i+1; j < 3; j++) {
            while (sz(need[i][j]) && sz(need[j][i])) {
                int a = need[i][j][sz(need[i][j])-1];
                int b = need[j][i][sz(need[j][i])-1];
                need[i][j].pop_back();
                need[j][i].pop_back();
                ans(a, j, b, i);
            }
        }
    }
    while (sz(need[0][1])) {
        int a = need[0][1][sz(need[0][1])-1];
        int b = need[1][2][sz(need[1][2])-1];
        int c = need[2][0][sz(need[2][0])-1];
        need[0][1].pop_back();
        need[1][2].pop_back();
        need[2][0].pop_back();
        ans(a, 1, c, 0);
        ans(b, 2, c, 1);
    }
    while (sz(need[1][0])) {
        int a = need[1][0][sz(need[1][0])-1];
        int b = need[2][1][sz(need[2][1])-1];
        int c = need[0][2][sz(need[0][2])-1];
        need[1][0].pop_back();
        need[2][1].pop_back();
        need[0][2].pop_back();
        ans(a, 0, b, 1);
        ans(b, 0, c, 2);
    }
    cout << sz(sol) << endl;
    for (auto p : sol) {
        print(p);
    }
}

int main() { FAST
    int t = 1;
    cin >> t;
    while (t--) {
        // cout << solve() << endl;
        solve();
    }
}
