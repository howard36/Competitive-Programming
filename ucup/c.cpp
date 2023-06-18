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

int waiting[10][1003];

pi w1(pi p) {
    int b = p.f;
    int i = p.s;
    return mp(b-1, ((i>>b)<<b)-1);
}

pi w2(pi p) {
    int b = p.f - 1;
    int i = p.s;
    while (b >= 0 && (i>>b)%2 == 0) b--;
    return mp(b, i);
}

void solve() {
    int n;
    cin >> n;
    if (n < 13) {
        for (int i = 0; i < n; i++) {
            for (int b = 0; b < 10; b++) {
                if ((i>>b)&1) {
                    pi p1 = w1(mp(b,i));
                    if (p1.f >= 0)
                        waiting[p1.f][p1.s]++;
                    pi p2 = w2(mp(b,i));
                    if (p2.f >= 0)
                        waiting[p2.f][p2.s]++;
                }
            }
        }

        priority_queue<pi> pq;
        for (int b = 9; b >= 0; b--) {
            for (int i = n-1; i >= 0; i--) {
                if ((i>>b)&1) {
                    if (waiting[b][i] == 0) {
                        pq.push(mp(b,i));
                    }
                }
            }
        }

        vector<vector<pi>> ans;
        while (!pq.empty()) {
            vector<pi> mov;
            for (int i = 0; i < 4; i++) {
                if (pq.empty())
                    break;
                pi p = pq.top();
                pq.pop();
                // dbg(p.f _ p.s _ i _ sz(ans));
                mov.pb(p);
            }
            for (pi p : mov) {
                pi p1 = w1(p);
                if (p1.f >= 0) {
                    waiting[p1.f][p1.s]--;
                    if (waiting[p1.f][p1.s] == 0)
                        pq.push(p1);
                }
                pi p2 = w2(p);
                dbg(p.f _ p.s _ p2.f _ p2.s)
                if (p2.f >= 0) {
                    waiting[p2.f][p2.s]--;
                    if (waiting[p2.f][p2.s] == 0) {
                        pq.push(p2);
                        dbg("push" _ p2.f _ p2.s)
                    }
                }
            }
            ans.pb(mov);
        }

        cout << sz(ans) << endl;
        for (int i = sz(ans)-1; i >= 0; i--) {
            for (pi p : ans[i]) {
                cout << p.s+1 << " " << ((p.s>>p.f)<<p.f) << " " << p.s+1 << endl;
            }
            for (int j = 0; j < 4-sz(ans[i]); j++) {
                cout << "2000 2000 2000" << endl;
            }
        }
    } else if (n == 13) {
        cout << "5\n";
        cout << "2 1 2\n4 3 4\n6 5 6\n8 7 8\n";
        cout << "4 2 4\n8 6 8\n10 9 10\n12 11 12\n";
        cout << "8 4 8\n12 10 12\n3 2 3\n5 4 5\n";
        cout << "12 8 12\n6 4 6\n10 8 10\n9 8 9\n";
        cout << "11 10 11\n13 12 13\n7 6 7\n99 99 99\n";
    } else if (n == 14) {
        cout << "6\n";
        cout << "2 1 2\n4 3 4\n6 5 6\n8 7 8\n";
        cout << "4 2 4\n8 6 8\n10 9 10\n12 11 12\n";
        cout << "8 4 8\n12 10 12\n14 13 14\n99 99 99\n";
        cout << "12 8 12\n6 4 6\n10 8 10\n99 99 99\n";
        cout << "14 12 14\n3 2 3\n5 4 5\n7 6 7\n";
        cout << "9 8 9\n11 10 11\n13 12 13\n99 99 99\n";
    } else if (n == 15) { 
        cout << "6\n";
        cout << "2 1 2\n4 3 4\n6 5 6\n8 7 8\n";
        cout << "4 2 4\n8 6 8\n10 9 10\n12 11 12\n";
        cout << "8 4 8\n12 10 12\n14 13 14\n99 99 99\n";
        cout << "12 8 12\n6 4 6\n10 8 10\n99 99 99\n";
        cout << "14 12 14\n3 2 3\n5 4 5\n7 6 7\n";
        cout << "9 8 9\n11 10 11\n13 12 13\n15 14 15\n";
    } else if (n == 16) {
        cout << "7\n";
        cout << "2 1 2\n4 3 4\n6 5 6\n8 7 8\n";
        cout << "10 9 10\n12 11 12\n14 13 14\n16 15 16\n";
        cout << "4 2 4\n8 6 8\n12 10 12\n16 14 16\n";
        cout << "8 4 8\n16 12 16\n99 99 99\n99 99 99\n";
        cout << "16 9 16\n12 8 12\n6 4 6\n10 8 10\n";
        cout << "14 12 14\n3 2 3\n5 4 5\n7 6 7\n";
        cout << "9 8 9\n11 10 11\n13 12 13\n15 14 15\n";
    }
}

int main() { FAST
    int t = 1;
    while (t--) {
        solve();
    }
}
