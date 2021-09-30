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

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ld,ld> pd;
typedef complex<ld> cd;


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
    Mat<int> M(n,n);
    for (int i = 0; i<n; i++)
        for (int j = 0; j<n; j++) 
            cin >> M.d[i][j];
    cin.ignore();
    string s;
    vi v;
    getline(cin, s);
    for (char c : s)
        v.pb(charToInt(c));
    while (sz(v) % n != 0)
        v.pb(36);
    for (int i = 0; i<sz(v); i+=n) {
        Mat<int> x(n,1);
        for (int j = 0; j<n; j++)
            x.d[j][0] = v[i+j];
        x = M*x;
        for (int j = 0; j<n; j++)
            v[i+j] = x.d[j][0];
    }
    for (int i = 0; i<sz(v); i++) {
        v[i] = ((v[i] % 37) + 37) % 37;
        cout << intToChar(v[i]);
    }
    cout << endl;
}
