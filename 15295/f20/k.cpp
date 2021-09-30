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


typedef long double T;
typedef vector<T> vd;
typedef vector<vd> vvd;
const T eps = 1e-15, inf = 1/.0;

#define ltj(X) if (s == -1 || mp(X[j],N[j]) < mp(X[s],N[s])) s=j

struct LPSolver {
	int m, n;
	vi N, B;
	vvd D;

	LPSolver(const vvd& A, const vd& b, const vd& c) :
		m(sz(b)), n(sz(c)), N(n+1), B(m), D(m+2, vd(n+2)) {
			F0R(i,m) F0R(j,n) D[i][j] = A[i][j];
			F0R(i,m) { B[i] = n+i; D[i][n] = -1; D[i][n+1] = b[i]; } // B[i] -> basic variables, col n+1 is for constants, why D[i][n]=-1?
			F0R(j,n) { N[j] = j; D[m][j] = -c[j]; } // N[j] -> non-basic variables, all zero
			N[n] = -1; D[m+1][n] = 1;
		}
	
	void pivot(int r, int s) { // row, column
		T *a = D[r].data(), inv = 1/a[s]; // eliminate col s from consideration
		F0R(i,m+2) if (i != r && abs(D[i][s]) > eps) {
			T *b = D[i].data(), inv2 = b[s]*inv;
			F0R(j,n+2) b[j] -= a[j]*inv2;
			b[s] = a[s]*inv2;
		}
		F0R(j,n+2) if (j != s) D[r][j] *= inv;
		F0R(i,m+2) if (i != r) D[i][s] *= -inv;
		D[r][s] = inv; swap(B[r], N[s]); // swap a basic and non-basic variable
	}

	bool simplex(int phase) {
		int x = m+phase-1;
		for (;;) {
			int s = -1; F0R(j,n+1) if (N[j] != -phase) ltj(D[x]); // find most negative col
			if (D[x][s] >= -eps) return true; // have best solution
			int r = -1;
			F0R(i,m) {
				if (D[i][s] <= eps) continue;
				if (r == -1 || mp(D[i][n+1] / D[i][s], B[i])
							 < mp(D[r][n+1] / D[r][s], B[r])) r = i; // find smallest positive ratio
			}
			if (r == -1) return false; // unbounded
			pivot(r, s);
		}
	}

    T solve(vd &x) {
		int r = 0; FOR(i,1,m) if (D[i][n+1] < D[r][n+1]) r = i;
		if (D[r][n+1] < -eps) { // x=0 is not a solution
			pivot(r, n); // -1 is artificial variable, initially set to smth large but want to get to 0 
			if (!simplex(2) || D[m+1][n+1] < -eps) return -inf; // no solution
			// D[m+1][n+1] is max possible value of the negation of artificial variable, starts negative but should get to zero
			F0R(i,m) if (B[i] == -1) {
				int s = 0; FOR(j,1,n+1) ltj(D[i]);
				pivot(i,s);
			}
		}
		bool ok = simplex(1); x = vd(n);
		F0R(i,m) if (B[i] < n) x[B[i]] = D[i][n+1];
		return ok ? D[m][n+1] : inf;
	}
};

ld x[20005], y[20005], z[20005], v[20005];
int n;

bool good(ld m) {
    ld max1 = -1e50;
    ld max2 = -1e50;
    ld max3 = -1e50;
    ld max4 = -1e50;
    ld min1 = 1e50;
    ld min2 = 1e50;
    ld min3 = 1e50;
    ld min4 = 1e50;
    M00(i, n) {
        // x + y + z <= vi*m + xi + yi + zi
        // x + y - z <= vi*m + xi + yi - zi
        // x - y - z <= vi*m + xi - yi - zi
        // -x - y - z <= vi*m - xi - yi - zi
        // x + y + z >= -(vi*m - xi - yi - zi)
        // max(-(vi*m - xi - yi - zi)) <= min(vi*m + xi + yi + zi)
        max1 = max(max1, -v[i]*m + x[i] + y[i] + z[i]);
        min1 = min(min1, v[i]*m + x[i] + y[i] + z[i]);
        max2 = max(max2, -v[i]*m - x[i] + y[i] + z[i]);
        min2 = min(min2, v[i]*m - x[i] + y[i] + z[i]);
        max3 = max(max3, -v[i]*m + x[i] - y[i] + z[i]);
        min3 = min(min3, v[i]*m + x[i] - y[i] + z[i]);
        max4 = max(max4, -v[i]*m + x[i] + y[i] - z[i]);
        min4 = min(min4, v[i]*m + x[i] + y[i] - z[i]);
    }
    vvd A = {
        {1, 1, 1}, // x+y+z <= min1
        {-1, 1, 1}, 
        {1, -1, 1}, 
        {1, 1, -1}, 
        {-1, -1, 1}, 
        {-1, 1, -1}, 
        {1, -1, -1}, 
        {-1, -1, -1} // -x -y -z <= -max1
    };
    vd B = {min1, min2, min3, min4, -max4, -max3, -max2, -max1};
    vd C = {1, 1, 1};
    auto L = LPSolver(A, B, C);
    vd x = {0, 0, 0};
    ld t = L.solve(x);
    return (t > -1);
}

int main() { FAST
    cin >> n;
    M00(i, n) {
        cin >> x[i] >> y[i] >> z[i] >> v[i];
        x[i]++;
        y[i]++;
        z[i]++;
    }
    ld lo = 0, hi = 1e20;
    while (hi - lo > 1e-10) {
        ld mid = (lo + hi)/2.0;
        if (good(mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    cout << fixed << setprecision(10) << lo << endl;
}
