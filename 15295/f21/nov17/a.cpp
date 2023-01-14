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

#define ll long long
#define M 1000000007LL

int bit1[1000006];
ll bit2[1000006];
int n, a[1000006];
int b[1000006];

void update1(int i) {
    for (; i <= n; i+=i&-i)
        bit1[i]++;
}

void update2(ll v, int i) {
    for (; i <= n; i+=i&-i)
        bit2[i] += v;
}

int query1(int i) {
    int ans = 0;
    for (; i; i-=i&-i)
        ans += bit1[i];
    return ans;
}

ll query2(int i) {
    ll ans = 0;
    for (; i; i-=i&-i)
        ans += bit2[i];
    return ans;
}

int main() {
	cin >> n;
    ll ans1 = 0, ans2 = 0;
    for (int i = 0; i<n; i++) {
		cin >> a[i];
		b[a[i]-1] = i;
	}
	for (int i = 0; i<n; i++) {
        ans1 += query1(n-b[i]);
        update1(n-b[i]);
	}
	cout << ans1 << "\n";
}

