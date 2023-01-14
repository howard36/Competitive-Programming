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
#define dbg(x) // cerr << ">>> " << #x << " = " << x << "\n";
#define _ << " _ " <<

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ld,ld> pd;
typedef complex<ld> cd;

int a[100005], mono[100005], seen[100005], bit[100005];
ll ans[100005], ans2[100005];
int n;
int b[100005];

ll solve(int k) {
	for (int i = 0; i<k; i++) {
		b[i] = a[i];
	}
	ll cnt = 0;
	for (int i = 0; i<k; i++) {
		for (int j = 0; j<k; j++) {
			if (b[i] < b[j]) {
				swap(b[i], b[j]);
				cnt++;
				//dbg(i _ j);
			}
		}
	}
	return cnt;
}

void upd(int i) {
	for (; i<=n; i+=i&-i)
		bit[i]++;
}

int query(int i) {
	int ret = 0;
	for (; i>0; i-=i&-i)
		ret += bit[i];
	return ret;
}

int main() { FAST
	int t = 1000;
	while (t--) {
		n = 8;
		/*
		a[0] = 3;
		a[1] = 3;
		a[2] = 3;
		a[3] = 1;
		a[4] = 5;
		*/
		for (int i = 0; i<n; i++) {
			a[i] = rand() % n + 1;
			cout << a[i] << " ";
		}
		cout << endl;
		int m = a[0], eq = 1, extra = 0;
		for (int i = 1; i<n; i++) {
			if (a[i] > m) {
				mono[i] = mono[i-1] + eq+extra+1;
				m = a[i];
				eq = 1;
				extra = 0;
			} else {
				mono[i] = mono[i-1];
				if (a[i] == m)
					eq++;
				else if (eq > 1) {
					extra++;
				}
			}
			dbg(i _ mono[i])
		}
		for (int i = 1; i<=n; i++) {
			seen[i] = 0;
			bit[i] = 0;
		}
		ll last = 0;
		//cout << "sol:\n";
		for (int i = 0; i<n; i++) {
			if (!seen[a[i]]) {
				upd(n+1-a[i]);
				seen[a[i]] = 1;
			}
			ans[i] = last + query(n-a[i]);
			last = ans[i];
			dbg(i _ ans[i])
			ans[i] += mono[i];
			//cout << ans[i] << " ";
		}
		//cout << "\nbrute force:\n";
		for (int i = 0; i<n; i++) {
			 ans2[i] = solve(i+1);
			 //cout << ans2[i] << " ";
			 if (ans2[i] != ans[i]) {
				 cout << "BAD!";
				 break;
			 }
		}
		cout << endl;
	}
}
