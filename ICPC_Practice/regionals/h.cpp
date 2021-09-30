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

multiset<int> S[2];

int main() { FAST
	int k, n;
    cin >> k >> n;
    for (int i = 0; i<n; i++) {
        int d;
        char c;
        cin >> d >> c;
        if (c == 'y')
            S[0].insert(d);
        else
            S[1].insert(d);
    }
    for (int i = n; i>0; i--) {
        int rem = k;
        auto it = S[0].lower_bound(i);
        if (it != S[0].end()) {
            S[0].erase(it);
            rem--;
        }
        while (rem > 0) {
            it = S[1].lower_bound(i);
            if (it != S[1].end())
                S[1].erase(it);
            else
                break;
            rem--;
        }
    }
    if (S[0].empty() && S[1].empty())
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
