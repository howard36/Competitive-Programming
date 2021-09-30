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

string s[100];
map<string, ll> cnt;
map<string, ll> correct;
map<string, string> last;

int main() { FAST
    int n, m;
    cin >> n;
    for (int i = 0; i<n; i++)
        cin >> s[i];
    cin >> m;
    string s1, s2, s3;
    for (int i = 0; i<m; i++) {
        cin >> s1 >> s2 >> s3;
        cnt[s1]++;
        if (s3 == "correct")
            correct[s1]++;
        last[s1] = s2;
    }
    ll prod = 1;
    ll cprod = 1;
    bool wrong = false;
    for (int i = 0; i<n; i++) {
        prod *= cnt[s[i]];
        cprod *= correct[s[i]];
    }
    if (prod == 1) {
        for (int i = 0; i<n; i++)
            cout << last[s[i]] << " ";
        cout << endl;
        if (cprod == 1)
            cout << "correct" << endl;
        else
            cout << "incorrect" << endl;
    }
    else {
        cout << cprod << " correct\n" << prod-cprod << " incorrect" << endl;
    }

}
