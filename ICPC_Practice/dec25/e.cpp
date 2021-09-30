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

string names[10004];
int a[10004];

int main() { FAST
	int n;
    cin >> n;
    int sum = 0;
    for (int i = 0; i<n; i++) {
        double x;
        cin >> names[i] >> x;
        a[i] = (int)(100*x + 0.5);
        sum += a[i];
    }
    if (10000 < sum - 50*n || sum + 49*n < 10000) {
        finish("IMPOSSIBLE");
    }
    int sub = max(10000 - (sum + 49*(n-1)), -50);
    int add = min(10000 - (sum - 50*(n-1)), 49);
    for (int i = 0; i<n; i++) {
        cout << fixed << setprecision(2) << names[i] << " " << max((a[i] + sub)/100.0, 0.0) << " " << min((a[i] + add)/100.0, 100.0) << endl;
    }
}

