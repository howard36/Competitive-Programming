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

int n;
int a[10];
map<ll, ld> m1, m2;

ld f1() {
    bool sorted = true;
    M00(i, n-1) {
        if (a[i] > a[i+1])
            sorted = false;
    }
    if (sorted)
        return 0;
    ll h = 0;
    M00(i, n) h = 101*h+a[i];
    if (m1.find(h) != m1.end())
        return m1[h];
    ld sum = 0, same = n;
    M00(i, n) MOO(j, i+1, n) {
        if (a[i] > a[j]) {
            swap(a[i], a[j]);
            sum += f1();
            swap(a[i], a[j]);
        }
        else
            same += 2;
    }
    m1[h] = (2*sum+n*n)/(n*n-same);
    return m1[h];
}

ld f2() {
    bool sorted = true;
    M00(i, n-1) {
        if (a[i] > a[i+1])
            sorted = false;
    }
    if (sorted)
        return 0;
    ll h = 0;
    M00(i, n) h = 101*h+a[i];
    if (m2.find(h) != m2.end())
        return m2[h];
    ld sum = 0, same = 0;
    M00(i, n-1) {
        if (a[i] > a[i+1]) {
            swap(a[i], a[i+1]);
            sum += f2();
            swap(a[i], a[i+1]);
        }
        else
            same++;
    }
    m2[h] = (sum+n-1)/(n-1-same);
    return m2[h];
}

int main() { FAST
	int t;
    cin >> t;
    while (t--) {
        cin >> n;
        M00(i, n) cin >> a[i];
        cout << fixed << setprecision(6) << "Monty " << f1() << " Carlos " << f2() << endl;
    }
}
