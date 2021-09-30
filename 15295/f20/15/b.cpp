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

int p[24][4] = {
    {0, 1, 2, 3},
    {0, 1, 3, 2},
    {0, 2, 1, 3},
    {0, 2, 3, 1},
    {0, 3, 1, 2},
    {0, 3, 2, 1},
    {1, 0, 2, 3},
    {1, 0, 3, 2},
    {1, 2, 0, 3},
    {1, 2, 3, 0},
    {1, 3, 0, 2},
    {1, 3, 2, 0},
    {2, 0, 1, 3},
    {2, 0, 3, 1},
    {2, 1, 0, 3},
    {2, 1, 3, 0},
    {2, 3, 0, 1},
    {2, 3, 1, 0},
    {3, 0, 1, 2},
    {3, 0, 2, 1},
    {3, 1, 0, 2},
    {3, 1, 2, 0},
    {3, 2, 0, 1},
    {3, 2, 1, 0}
};

int a[4];
set<int> s;

void ins(int x) {
    if (x >= 0) {
        s.insert(x);
    }
}

int main() { FAST
	for (int i = 0; i<4; i++) {
        cin >> a[i];
    }
    for (int i = 0; i<24; i++) {
        int b = a[p[i][0]];
        int c = a[p[i][1]];
        int d = a[p[i][2]];
        int e = a[p[i][3]];
        int bc = 10*b+c;
        int bd = 10*b+d;
        int be = 10*b+e;
        int de = 10*d+e;
        int bcd = 100*b+10*c+d;
        ins(b+c+d+e);
        ins(b+c+d-e);
        ins(b+c+d*e);
        ins(b+c-d+e);
        ins(b+c-d-e);
        ins(b+c-d*e);
        ins(b+c*d+e);
        ins(b+c*d-e);
        ins(b+c*d*e);
        ins(b-c+d+e);
        ins(b-c+d-e);
        ins(b-c+d*e);
        ins(b-c-d+e);
        ins(b-c-d-e);
        ins(b-c-d*e);
        ins(b-c*d+e);
        ins(b-c*d-e);
        ins(b-c*d*e);
        ins(b*c+d+e);
        ins(b*c+d-e);
        ins(b*c+d*e);
        ins(b*c-d+e);
        ins(b*c-d-e);
        ins(b*c-d*e);
        ins(b*c*d+e);
        ins(b*c*d-e);
        ins(b*c*d*e);

        ins(bc+d+e);
        ins(bc+d-e);
        ins(bc+d*e);
        ins(bc-d+e);
        ins(bc-d-e);
        ins(bc-d*e);
        ins(bc*d+e);
        ins(bc*d-e);
        ins(bc*d*e);
        ins(c+bd+e);
        ins(c+bd-e);
        ins(c+bd*e);
        ins(c-bd+e);
        ins(c-bd-e);
        ins(c-bd*e);
        ins(c*bd+e);
        ins(c*bd-e);
        ins(c*d*be);
        ins(c+d+be);
        ins(c+d-be);
        ins(c+d*be);
        ins(c-d+be);
        ins(c-d-be);
        ins(c-d*be);
        ins(c*d+be);
        ins(c*d-be);
        ins(c*d*be);

        ins(bc+de);
        ins(bc-de);
        ins(bc*de);

        ins(bcd+e);
        ins(bcd-e);
        ins(bcd*e);
        ins(e+bcd);
        ins(e-bcd);
        ins(e*bcd);
    }
    cout << s.size() << endl;
}
