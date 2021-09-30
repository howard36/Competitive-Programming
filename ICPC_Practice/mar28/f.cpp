#include <bits/stdc++.h>

using namespace std;

#define f first
#define F first
#define s second
#define S second
#define pb push_back
#define MP make_pair
#define mp make_pair
#define all(v) v.begin(), v.end()
#define sz(v) (int)v.size()

#define MOO(i, a, b) for(int i=a; i<b; i++)
#define FOR(i, a, b) for(int i=a; i<b; i++)
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

pl solve(pl a, pl b) {
	auto g = __gcd(a.s,b.s), l = a.s/g*b.s;
	if ((b.f-a.f) % g != 0) return {-1,-1};
	auto A = a.s/g, B = b.s/g;
	auto mul = (b.f-a.f)/g*invGeneral(A,B) % B;
	return {((mul*a.s+a.f)%l+l)%l,l};
}

vi kmp(string s) {
	int N = sz(s); vi f(N+1); f[0] = -1;
	FOR(i,1,N+1) {
		f[i] = f[i-1];
		while (f[i] != -1 && s[f[i]] != s[i-1]) f[i] = f[f[i]];
		f[i] ++;
	}
	return f;
}

int getOc(string a, string b) { // first occurrence of a in b
	vi f = kmp(a+"@"+b);
	FOR(i,sz(a),sz(b)+1) if (f[i+sz(a)+1] == sz(a)) return i-sz(a);
    return -1;
}

int minRot(string a) {
    int n = a.length();
    string b = a.substr(1, n-1) + a;
    return getOc(a, b) + 1;
}


vi pos[1000006][26];
int tt[1000006], pos2[1000006], chr2[1000006], cycle[1000006], mr[1000006];
pi freq[26];
string cycstr[2][1000006];

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main() { FAST
    string s, t;
    cin >> s >> t;
    ll n = s.length();
    if (s[0] != t[0] || s[n-1] != t[n-1]) {
        finish(-1);
    }
    for (int i = 0; i<n; i++)
        tt[i] = t[i]-'a';
    ll inv = n/2;
    ll mod = n-1;
    int cyc = 1;
    for (int i = 1; i<n-1; i++) {
        if (cycle[i] == 0) {
            cycstr[0][cyc] = "";
            cycstr[1][cyc] = "";
            for (int j = i; cycle[j] == 0; j = (2*j)%mod) {
                cycle[j] = cyc;
                cycstr[0][cyc] += s[j];
                cycstr[1][cyc] += t[j];
            }
            cyc++;
        }
    }
    pl period = pl(0,1);
    dbg(cyc);
    for (int i = 1; i<cyc; i++) {
        dbg(cycstr[0][i] _ cycstr[1][i]);
        ll m = minRot(cycstr[0][i]);
        ll r = getOc(cycstr[1][i], cycstr[0][i] + cycstr[0][i]);
        if (r == -1) {
            finish(-1);
        }
        period = solve(period, pl(r, m));
        dbg(period.f _ period.s);
        if (period.f == -1) {
            finish(-1);
        }
    }
    finish(period.f);
    /*
    for (int i = 1; i<n-1; i++) {
        int c = s[i] - 'a';
        pos[cycle[i]][c].pb(i);
    }
    for (int cy = 1; cy<cyc; cy++) {
        int cnt = 0;
        for (int c = 0; c<26; c++) 
            freq[c] = pi(sz(pos[cy][c]), c);
        sort(freq, freq+26);
        for (int j = 0; j<25; j++) {
            int c = freq[j].s;
            for (int i : pos[cy][c]) {
                pos2[cnt] = i;
                chr2[cnt++] = c;
            }
        }
        int r = getOc(cycstr[cy], 
        ll pow = 1;
        for (int i = 0; i<n; i++) {
            
            if (j == cnt) {
                period = solve(period, pl(i, mr[cy]));
                if (period.s == -1) {
                    finish(-1);
                }
                break;
            }
            pow = (pow * inv) % mod;
            if (i == mr[cy]) {
                finish(-1);
            }
        }
    }
    finish(period.f);
    */
}
