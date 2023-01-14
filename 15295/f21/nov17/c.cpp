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
typedef pair<ll,ll> pi;
typedef pair<ld,ld> pd;
typedef complex<ld> cd;

map<ll, ll> ml, mr;
int a[200005], arr[200005];

ll n, q;
ll bit[200005];
void update(ll v, int i) {
    for (; i <= n; i+=i&-i)
        bit[i] += v;
}
ll query(int i) {
    ll ans = 0;
    for (; i; i-=i&-i)
        ans += bit[i];
    return ans;
}


void one(ll i) {
	ll lo = i, hi = i, d;
	auto it = ml.lower_bound(i);
	pi p = *it;
	if (p.f == i+1) {
		hi = p.s;
		d = (p.s-p.f+1)*(p.s-p.f+2)/2;
		update(-d, p.f);
		ml.erase(p.f);
		mr.erase(p.s);
	}
	it = mr.lower_bound(i-1);
	p = *it;
	if (p.f == i-1) {
		lo = p.s;
		d = (p.f-p.s+1)*(p.f-p.s+2)/2;
		update(-d, p.s);
		mr.erase(p.f);
		ml.erase(p.s);
	}
	ml[lo] = hi;
	mr[hi] = lo;
	d = (hi-lo+1)*(hi-lo+2)/2;
	update(d, lo);
}

void zero(ll i) {
	auto it = mr.lower_bound(i);
	pi p = *it;
	ll hi = p.f, lo = p.s;
	mr.erase(hi);
	ml.erase(lo);
	update((hi-lo+1)*(hi-lo+2)/2, lo);
	if (lo < i) {
		ml[lo] = i-1;
		mr[i-1] = lo;
		update((i-lo)*(i-lo+1)/2, lo);
	}
	if (hi > i) {
		ml[i+1] = hi;
		mr[hi] = i+1;
		update((hi-i)*(hi-i+1)/2, i+1);
	}
}

void upd(ll i) {
	if (arr[i] == 0)
		one(i);
	else
		zero(i);
	arr[i] ^= 1;
}



int main() { FAST
	cin >> n >> q;
	for (int i = 1; i<=n; i++)
		cin >> a[i];
	for (int i = 1; i<n; i++)
		if (a[i] != a[i+1])
			upd(a[i]);
	while (q--) {
		ll t, l, r;
		cin >> t >> l >> r;
		l--;
		if (t == 1) {
			if (l > 0)
				upd(l);
			if (r < n)
				upd(r);
		}
		else {
			ans = 0;
			pi p = *mr.lower_bound(l);
			ll lo = p.f+1;
			ll tmp = max(l, p.s);
			ans += (p.f-tmp+1)*(p.f-tmp+2)/2;
			p = *mr.lower_bound(r);
			if (p.s <= r) {
				ans += (r-p.s+1)*(r-p.s+2)/2;
				hi = p.s-1;
			} else {
				hi = r;
			}
			query(hi) - query(lo);
		}
	}
}
