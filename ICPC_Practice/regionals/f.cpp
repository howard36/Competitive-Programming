#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()
#define sz(v) (int)v.size()

#define FOR(i, a, b) for(int i=a; i<b; i++)
#define F0R(i, a) for(int i=0; i<a; i++)
#define MOOd(i,a,b) for(int i = (b)-1; i >= a; i--)
#define M00d(i,a) for(int i = (a)-1; i>=0; i--)

#define FAST ios::sync_with_stdio(0); cin.tie(0);
#define finish(x) return cout << x << '\n', 0;
#define dbg(x) cerr << ">>> " << #x << " = " << x << "\n";
#define _ << " _ " <<
#define MOD 37

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
typedef complex<ld> cd;

pl euclid(ll a, ll b) { // returns {x,y} such that a*x+b*y=gcd(a,b)
	if (!b) return {1,0};
	pl p = euclid(b,a%b);
	return {p.s,p.f-a/b*p.s};
}
ll invGeneral(ll a, ll b) { 
	pl p = euclid(a,b); assert(p.f*a+p.s*b == 1);
	return p.f+(p.f<0)*b;
}

template<class T> struct modular {
	T val; 
	explicit operator T() const { return val; }
	modular() { val = 0; }
	modular(const ll& v) { 
		val = (-MOD <= v && v <= MOD) ? v : v % MOD;
		if (val < 0) val += MOD;
	}
	
	// friend ostream& operator<<(ostream& os, const modular& a) { return os << a.val; }
	friend void pr(const modular& a) { pr(a.val); }
	// friend void re(modular& a) { ll x; re(x); a = modular(x); }
   
	friend bool operator==(const modular& a, const modular& b) { return a.val == b.val; }
	friend bool operator!=(const modular& a, const modular& b) { return !(a == b); }
	friend bool operator<(const modular& a, const modular& b) { return a.val < b.val; }

	modular operator-() const { return modular(-val); }
	modular& operator+=(const modular& m) { if ((val += m.val) >= MOD) val -= MOD; return *this; }
	modular& operator-=(const modular& m) { if ((val -= m.val) < 0) val += MOD; return *this; }
	modular& operator*=(const modular& m) { val = (ll)val*m.val%MOD; return *this; }
	friend modular pow(modular a, ll p) {
		modular ans = 1; for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans;
	}
	friend modular inv(const modular& a) { 
		assert(a != 0);
        return invGeneral(a.val,MOD); 
	}
	modular& operator/=(const modular& m) { return (*this) *= inv(m); }
	
	friend modular operator+(modular a, const modular& b) { return a += b; }
	friend modular operator-(modular a, const modular& b) { return a -= b; }
	friend modular operator*(modular a, const modular& b) { return a *= b; }
	
	friend modular operator/(modular a, const modular& b) { return a /= b; }
};

typedef modular<int> mi;
typedef pair<mi,mi> pmi;
typedef vector<mi> vmi;
typedef vector<pmi> vpmi;


template<class T> struct Mat {
	int r,c;
	vector<vector<T>> d;
	Mat(int _r, int _c) : r(_r), c(_c) { d.assign(r,vector<T>(c)); }
	Mat() : Mat(0,0) {} 
	Mat(const vector<vector<T>>& _d) : r(sz(_d)), c(sz(_d[0])) { d = _d; }
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
		F0R(i,r) F0R(j,c) F0R(k,m.c) x.d[i][k] += d[i][j]*m.d[j][k];
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

template<class T> T gauss(Mat<T>& m) { // determinant of 1000x1000 Matrix in ~1s
	int n = m.r;
	T prod = 1; int nex = 0;
	F0R(i,n) {
		int row = -1; // for ld use EPS rather than 0
		FOR(j,nex,n) if (m.d[j][i] != 0) { row = j; break; } 
		if (row == -1) { prod = 0; continue; }
		if (row != nex) prod *= -1, swap(m.d[row],m.d[nex]);
		prod *= m.d[nex][i];
		auto x = 1/m.d[nex][i]; FOR(k,i,m.c) m.d[nex][k] *= x;
		F0R(j,n) if (j != nex) {
			auto v = m.d[j][i];
			if (v != 0) FOR(k,i,m.c) m.d[j][k] -= v*m.d[nex][k];
		}
		nex ++;
	}
	return prod;
}


int charToInt(char c) {
    if (c >= 'A' && c <= 'Z')
        return (int)(c - 'A');
    if (c == ' ')
        return 36;
    return (int)(c - '0') + 26;
}

char intToChar(int i) {
    if (i < 26)
        return (char)('A' + i);
    if (i == 36)
        return ' ';
    return (char)('0' + (i-26));
}



int main() { FAST
    int n;
    cin >> n;
    cin.ignore();
    string s;
    vi v1, v2;
    getline(cin, s);
    for (char c : s)
        v1.pb(charToInt(c));
    getline(cin, s);
    for (char c : s)
        v2.pb(charToInt(c));
    while (sz(v1) % n != 0 || sz(v1) < sz(v2))
        v1.pb(36);
    while (sz(v2) % n != 0 || sz(v2) < sz(v1))
        v2.pb(36);

    int N = sz(v1);
    vector<Mat<mi>> M(n, Mat<mi>(N/n, n+1));
    for (int i = 0; i<N/n; i++) {
        for (int j = 0; j<n; j++)
            for (int k = 0; k<n; k++)
                M[k].d[i][j] = v1[n*i+j];
        for (int k = 0; k<n; k++)
            M[k].d[i][n] = v2[n*i+k];
    }

    /*
    for (int k = 0; k<n; k++) {
        cout << k << endl;
        for (int i = 0; i<N/n; i++) {
            for (int j = 0; j<n+1; j++) {
                cout << M[k].d[i][j].val << " ";
            }
            cout << endl;
        }
        cout << endl;
    }*/

    for (int k = 0; k<n; k++) {
        gauss(M[k]);
        for (int i = 0; i<N/n; i++) {
            bool allZero = true;
            for (int j = 0; j<n; j++)
                if (M[k].d[i][j] != 0)
                    allZero = false;
            if (allZero && M[k].d[i][n] != 0) {
                finish("No solution");
            }
        }
    }

    /*
    for (int k = 0; k<n; k++) {
        cout << k << endl;
        for (int i = 0; i<N/n; i++) {
            for (int j = 0; j<n+1; j++) {
                cout << M[k].d[i][j].val << " ";
            }
            cout << endl;
        }
        cout << endl;
    }*/

    for (int k = 0; k<n; k++) {
        int firstRow = N/n;
        for (int i = N/n-1; i>=0; i--) {
            bool allZero = true;
            for (int j = 0; j<n+1; j++)
                if (M[k].d[i][j] != 0)
                    allZero = false;
            if (allZero) {
                firstRow = i;
            }
        }
        if (firstRow < n) {
            finish("Too many solutions");
        }
    }

    for (int k = 0; k<n; k++) {
        for (int j = 0; j<n; j++) {
            for (int i=0; i<N/n; i++) {
                if (M[k].d[i][j] != 0) {
                    cout << M[k].d[i][n].val << " ";
                    // dbg(k _ i _ j);
                }
            }
        }
        cout << endl;
    }
}
