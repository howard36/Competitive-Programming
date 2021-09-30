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
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
typedef complex<ld> cd;


typedef ld T;
template <class T> int sgn(T x) { return (x > 0) - (x < 0); }

namespace Point {
	typedef pair<T,T> P;
	typedef vector<P> vP;

	P dir(T ang) {
		auto c = exp(ang*complex<T>(0,1));
		return P(c.real(),c.imag());
	}
	
	T norm(P x) { return x.f*x.f+x.s*x.s; }
	T abs(P x) { return sqrt(norm(x)); }
	T angle(P x) { return atan2(x.s,x.f); }
	P conj(P x) { return P(x.f,-x.s); }
	
	P operator+(const P& l, const P& r) { return P(l.f+r.f,l.s+r.s); }
	P operator-(const P& l, const P& r) { return P(l.f-r.f,l.s-r.s); }
	P operator*(const P& l, const T& r) { return P(l.f*r,l.s*r); }
	P operator*(const T& l, const P& r) { return r*l; }
	P operator/(const P& l, const T& r) { return P(l.f/r,l.s/r); }
	P operator*(const P& l, const P& r) { return P(l.f*r.f-l.s*r.s,l.s*r.f+l.f*r.s); }
	P operator/(const P& l, const P& r) { return l*conj(r)/norm(r); }
	
	P& operator+=(P& l, const P& r) { return l = l+r; }
	P& operator-=(P& l, const P& r) { return l = l-r; }
	P& operator*=(P& l, const T& r) { return l = l*r; }
	P& operator/=(P& l, const T& r) { return l = l/r; }
	P& operator*=(P& l, const P& r) { return l = l*r; }
	P& operator/=(P& l, const P& r) { return l = l/r; }
	
	P unit(P x) { return x/abs(x); }
	T dot(P a, P b) { return (conj(a)*b).f; }
	T cross(P a, P b) { return (conj(a)*b).s; }
	T cross(P p, P a, P b) { return cross(a-p,b-p); }
	P rotate(P a, T b) { return a*P(cos(b),sin(b)); }

	P reflect(P p, P a, P b) { return a+conj((p-a)/(b-a))*(b-a); }
	P foot(P p, P a, P b) { return (p+reflect(p,a,b))/(T)2; }
	bool onSeg(P p, P a, P b) { return cross(a,b,p) == 0 && dot(p-a,p-b) <= 0; }
};

using namespace Point;


vP segIntersect(P a, P b, P c, P d) { 
	T x = cross(a,b,c), y = cross(a,b,d); 
	T X = cross(c,d,a), Y = cross(c,d,b); 
	if (sgn(x)*sgn(y) < 0 && sgn(X)*sgn(Y) < 0) return {(d*x-c*y)/(x-y)};
	set<P> s;
	if (onSeg(a,c,d)) s.insert(a);
	if (onSeg(b,c,d)) s.insert(b);
	if (onSeg(c,a,b)) s.insert(c);
	if (onSeg(d,a,b)) s.insert(d);
	return {all(s)};
}


int main() { FAST
	
}
