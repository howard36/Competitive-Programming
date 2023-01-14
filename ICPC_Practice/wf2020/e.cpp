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

ll a[200005];

template<class T> struct node {
	T val;
	T lazy;
	int l, r;
	node *left;
	node *right;
	node(int l, int r) {
		this -> l = l;
		this -> r = r;
		this -> left = nullptr;
		this -> right = nullptr;
	}
};

template<class T, int SZ> struct segtree {
	T combIdentity = 1e9;
	T pushIdentity = 0;
	void push(node<T>* n) {
		n->val += n->lazy;
		if (n->l != n->r) {
			n->left->lazy += n->lazy;
			n->right->lazy += n->lazy;
		}
		n->lazy = pushIdentity;
	}

	node<T>* root;
	segtree() {
		int ub = 1;
		while (ub < SZ) ub *= 2;
		root = new node<T>(0, ub-1);
		root->val = pushIdentity;
		root->lazy = pushIdentity;
	}
	void propagate(node<T>* n) {
		if (n->l != n->r) {
			int mid = ((n->l) + (n->r))/2;
			if (n->left == nullptr) {
				n->left = new node<T>(n->l, mid);
				n->left->val = pushIdentity;
				n->left->lazy = pushIdentity;
			}
			if (n->right == nullptr) {
				n->right = new node<T>(mid+1, n->r);
				n->right->val = pushIdentity;
				n->right->lazy = pushIdentity;
			}
		}
		push(n);
	}
	void updN(node<T>* n, int i1, int i2, T val) {
		propagate(n);
		if (i2 < n->l || i1 > n->r) return;
		if (i1 <= n->l && i2 >= n->r) {
			n->lazy = val;
			push(n);
			return;
		}
		updN(n->left, i1, i2, val);
		updN(n->right, i1, i2, val);
	}
	void upd(int i1, int i2, T val) {
		updN(root, i1, i2, val);
	}
	void pushAllN(node<T>* n) {
		propagate(n);
		push(n);
		if (n->l == n->r) {
			if (n->l < 200005)
				a[n->l] += n->val;
		} else {
			pushAllN(n->left);
			pushAllN(n->right);
		}
	}
	void pushAll() {
		pushAllN(root);
	}
};

segtree<ll, 200005> st;

int main() { FAST
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		char c;
		int l, r;
		cin >> c >> l >> r;
		if (c == 'R') {
			a[l]++;
			a[r+1]--;
		} else if (c == 'D') {
			a[l]--;
			a[r+1]++;
		} else if (c == 'H') {
			int mid1 = (l+r)/2;
			int mid2 = (l+r+1)/2;
			st.upd(l, mid1, 1);
			st.upd(mid2+1, r+1, -1);
		} else {
			int mid1 = (l+r)/2;
			int mid2 = (l+r+1)/2;
			st.upd(l, mid1, -1);
			st.upd(mid2+1, r+1, 1);
		}
	}
	st.pushAll();
	for (int i = 1; i<=n; i++) {
		a[i] += a[i-1];
		cout << a[i] << "\n";
	}
}
