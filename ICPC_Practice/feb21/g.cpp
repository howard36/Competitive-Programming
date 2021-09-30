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
ld PI = acosl(-1);

cd p[1003];

int main() { FAST
	int m;
    cin >> m;
    ld x, y;
    for (int i = 0; i<m; i++) {
        cin >> x >> y;
        p[i] = cd(x,y);
    }
    ld bestr = 0;
    int bestn = -1;
    for (int n = 3; n<9; n++) {
        ld Min = 1e50;
        ld Max = 0;
        for (int i = 0; i<m; i++) {
            cd z = p[i];
            int j = (int)(n*(arg(-z)+PI)/(2*PI));
            cd rot = polar((ld)1, PI*(2*j+1)/n);
            ld score = real(z/polar((ld)1, PI*(2*j+1)/n));
            dbg(real(z) _ imag(z) _ j _ score _ real(rot) _ imag(rot));
            Min = min(Min, score);
            Max = max(Max, score);
        }
        dbg(n _ Min _ Max);
        if (Min/Max > bestr) {
            bestr = Min/Max;
            bestn = n;
        }
    }
    cout << bestn << " " << bestr*bestr << endl;
}
