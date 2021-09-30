#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()
#define sz(v) (int)v.size()

#define MOO(i, a, b) for(int i=a; i<b; i++)
#define FOR(i, a, b) for(int i=a; i<b; i++)
#define M00(i, a) for(int i=0; i<a; i++)
#define F0R(i, a) for(int i=0; i<a; i++)
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

#define MOD 998244353LL

template<class T> struct Mat {
	int r,c;
	vector<vector<T> > d;
	Mat(int _r, int _c) : r(_r), c(_c) { d.assign(r,vector<T>(c)); }
	Mat() : Mat(0,0) {}
	Mat(const vector<vector<T> >& _d) : r(sz(_d)), c(sz(_d[0])) { d = _d; }
	friend void pr(const Mat& m) { pr(m.d); }

	Mat& operator+=(const Mat& m) {
		assert(r == m.r && c == m.c);
		F0R(i,r) F0R(j,c) d[i][j] += m.d[i][j];
		return *this;
	}
	Mat& operator-=(const Mat& m) {
		assert(r == m.r && c == m.c);
		F0R(i,r) F0R(j,c) d[i][j] -= m.d[i][j];
		return *this;
	}
	Mat operator*(const Mat& m) {
		assert(c == m.r); Mat x(r,m.c);
		F0R(i,r) F0R(j,c) F0R(k,m.c) x.d[i][k] = (x.d[i][k] + d[i][j]*m.d[j][k] % MOD) % MOD;
		return x;
	}

	Mat operator+(const Mat& m) { return Mat(*this)+=m; }
	Mat operator-(const Mat& m) { return Mat(*this)-=m; }
	Mat& operator*=(const Mat& m) { return *this = (*this)*m; }

	friend Mat pow(Mat m, ll p) {
		assert(m.r == m.c);
		Mat r(m.r,m.c);
		F0R(i,m.r) r.d[i][i] = 1;
		for (; p; p /= 2, m *= m) if (p&1) r *= m;
		return r;
	}
};


ll a[20] = {1, 0, 4, 6, 2, 9, 3, 8, 7, 5, 11, 10};
ll b[20] = {2, 5, 3, 0, 7, 8, 10, 11, 1, 6, 9, 4};

int main() { FAST
	int n, x;
	string s;
	cin >> n >> s >> x;
	int t = 0;
	for (int i = n-1; i>=0; i--) {
		if (s[i] == 'a') t = a[t];
		else t = b[t];
	}
	Mat<ll> M(12, 12);
	for (int i = 0; i<12; i++) {
		M.d[a[i]][i] = 1;
		M.d[b[i]][i] = 1;
	}
	M = pow(M, x);
	cout << (M.d[t][0] % MOD + MOD) % MOD << "\n";
}
