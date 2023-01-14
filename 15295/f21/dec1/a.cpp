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

int p[100005], sz[100005];
unordered_map<int, int> cnt[100005];
unordered_set<int> s[100005];
vector<int> adj[100005];

int find(int i) {
	if (p[i] == i) return i;
	return p[i] = find(p[i]);
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
	if (a == b)
		return;
	if (sz[a] < sz[b])
		swap(a, b);
	p[b] = a;
	sz[a] += sz[b];
	set<int> update;
	for (int i : s[b]) {
		s[a].insert(i);
		for (int j : adj[i])
			update.insert(j);
	}
	for (int j : update)
		cnt[j][a] += cnt[j][b];
}

void newF(int a, int b) {
	adj[a].pb(b);
	adj[b].pb(a);
	cnt[a][find(b)]++;
	cnt[b][find(a)]++;
}

int main() { FAST
	int n, m, k, q;
	cin >> n >> m >> k;
	for (int i = 1; i<=n; i++) {
		p[i] = i;
		sz[i] = 1;
		s[i].insert(i);
	}
	for (int i = 0; i<m; i++) {
		int a, b;
		cin >> a >> b;
		newF(a, b);
	}
	for (int i = 0; i<k; i++) {
		int a, b;
		cin >> a >> b;
		merge(a, b);
	}
	cin >> q;
	for (int i = 0; i<q; i++) {
		char c;
		int a, b, v;
		cin >> c;
		if (c == '?') {
			cin >> v;
			cout << cnt[v][find(v)] << "\n";
		} else if (c == 'F') {
			cin >> a >> b;
			newF(a, b);
		} else {
			cin >> a >> b;
			merge(a, b);
		}
	}
}
