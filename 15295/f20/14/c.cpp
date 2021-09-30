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
typedef pair<ll,ll> pi;
typedef pair<ld,ld> pd;
typedef complex<ld> cd;


int main() { FAST
    int t;
    cin >> t;
    while (t--) {
        ld h, l, w;
        cin >> h >> l >> w;
        ld c = sqrt(w*w+4*h*h);
        ld x = sqrt((c+w)/(c-w));
        ld r = x*w*l/(2*h*(1+x));
        if (c/2 >= r+l) {
            cout << fixed << setprecision(10) << r << endl;
        }
        else {
            ld B = -w -2*h +2*l;
            ld C = w*w/4 + (h-l)*(h-l);
            r = (-B - sqrt(B*B-4*C))/2;
            cout << fixed << setprecision(10) << r << endl;
        }
    }
}

