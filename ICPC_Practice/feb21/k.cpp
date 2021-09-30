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

ld r[5000], sr[5000];
ld p[5000][20];

int main() { FAST
    int n;
    cin >> n;
	for (int i = 0; i<n; i++) {
        cin >> r[i];
    }
    int k = 0;
    while ((1<<k) < n) k++;
    sort(r+1, r+n);
    for (int i = 0; i<(1<<k)-n; i++) {
        sr[2*i] = r[i];
        sr[2*i+1] = 0;
    }
    for (int i = (1<<k)-n; i<n; i++) {
        sr[i+(1<<k)-n] = r[i];
    }
    for (int i = 0; i<(1<<k); i++) {
        dbg(i _ sr[i]);
    }
    for (int i = 0; i<(1<<k); i++)
        p[i][0] = 1;

    for (int i = 1; i<=k; i++) {
        for (int j = 0; j<(1<<k); j++) {
            if (i == k && j != 0)
                continue;
            int b = j>>(i-1);
            int oppb = b^1;
            ld prob = 0;
            for (int l = oppb<<(i-1); l < (oppb+1)<<(i-1); l++) {
                prob += sr[j]/(sr[j]+sr[l]) * p[l][i-1];
            }
            p[j][i] = prob*p[j][i-1];
            dbg(j _ i _ p[j][i]);
        }
    }
    cout << fixed << setprecision(10) << p[0][k] << endl;
}
